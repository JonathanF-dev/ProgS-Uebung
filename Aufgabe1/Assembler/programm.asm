.386
.model flat, stdcall
option casemap:none

; These are just prototypes for Windows API calls
; They have (almost) nothing to do with the exercise
GetStdHandle PROTO STDCALL :DWORD
WriteConsoleA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadConsoleA PROTO STDCALL :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
ExitProcess PROTO STDCALL :DWORD

STD_INPUT_HANDLE EQU -10
STD_OUTPUT_HANDLE EQU -11
ASCII_OFFSET EQU 48

; Static data allocated globally
.data
  errMsg db "Ungueltige Eingabe. Versuchen Sie es erneut!", 10, 0
  prompt db "Geben Sie eine Zahl (0-9) ein : "
  input db 20 DUP(0)
  outputMsg db "Das Ergebnis ist: "
  outputVal db 10 DUP(0)
  inHandle dd ?
  outHandle dd ?
  nBytesRW dd ?

.code

start:
  ; Get handles for input / output
  push STD_OUTPUT_HANDLE
  call GetStdHandle
  mov outHandle, eax
  push STD_INPUT_HANDLE
  call GetStdHandle
  mov inHandle, eax

  ; Output message
  push 0
  push offset nBytesRW
  push sizeof prompt
  push offset prompt
  push outHandle
  call WriteConsoleA

  ; Read input
  push 0
  push offset nBytesRW
  push sizeof input
  push offset input
  push inHandle
  call ReadConsoleA

  ; Need to manually convert the ASCII characters to numbers
  ; Hence, this will consider only 1 digit (0-9) to keep the implementation simple
  mov ecx, nBytesRW
  sub ecx, 2 ; Remove CR LF
  cmp ecx, 2 ; >= 2 chars is an error
  jb continueLabel
  jmp errLabel

continueLabel:
  xor eax, eax
  mov BYTE PTR al, [input]
  sub eax, ASCII_OFFSET ; Input as int -> eax

  ; Algorithm start
  test eax, eax
  jnz continueLabel2
  jmp algoEnd

continueLabel2:
  sub eax, 1
  jnz continueLabel3
  add eax, 1
continueLabel3:
  mov ecx, eax

  xor edx, edx
  mov ebx, 1

algoLoop:
  mov eax, edx
  add eax, ebx
  mov edx, ebx
  mov ebx, eax
  loop algoLoop

algoEnd:
  ; Algroithm end. Result is in eax

  ; Now we need to convert the resulting value
  ; to an ASCII representation.
  ; Fortunately, we know, that for the resticted
  ; input, the maximum number of output digits
  ; will be 2 ;-)
  pushf
  mov edi, offset outputVal
  add edi, 2 ; we will need only two digits
  push eax
  pushf
  pop eax
  xor eax, 400h
  push eax
  popf
  pop eax
  xor ebx, ebx

convertToInt:
  mov ebx, 10
  cdq
  div ebx
  add edx, ASCII_OFFSET
  push eax
  mov eax, edx
  stosb
  pop eax
  cmp eax, 0
  je  finished
  jmp convertToInt
finished:
  popf

  ; Output the result
  push 0
  push offset nBytesRW
  push sizeof outputMsg
  push offset outputMsg
  push outHandle
  call WriteConsoleA

  push 0
  push offset nBytesRW
  push 3 ; two digits + 0
  push offset outputVal
  push outHandle
  call WriteConsoleA

  jmp exitLabel
errLabel:
  push 0
  push offset nBytesRW
  push sizeof errMsg
  push offset errMsg
  push outHandle
  call WriteConsoleA
exitLabel:
  push 0
  call ExitProcess
end start
