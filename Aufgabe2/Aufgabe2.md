# 2.1 Reguläre Ausdrücke

Geben Sie für die folgenden Token die zugehörigen
regulären Ausdrücke an:

  * Kommentare in Pascal: diese werden in (* und *) oder { und }
    eingeschlossen und dürfen beliebige Zeichen enthalten.
  * Numerische Integerkonstanten in C: diese können oktale, dezimale
    oder hexadezimale Werte sein. Oktale Integerwerte beginnen mit
    einer 0 und dürfen nur die Ziffern 0-7 enthalten. Hexadezimale
    Integerwerte beginnen mit 0x oder 0X und dürfen die Ziffern 0-9
    und die Buchstaben a/A-f/F enthalten. Dezimale Integerwerte
    dürfen nicht mit 0 beginnen. Integerwerte können am Ende optional
    die Zeichen U oder u ("unsigned") und/oder L oder l ("long") oder
    LL oder ll ("long long") enthalten.

# 2.2 Grammatik I

Gegeben ist folgende Grammatik ("e" bezeichnet die leere Eingabe):

    S -> aSbS | bSaS | e

**a)** Zeigen Sie, dass die Grammatik nicht eindeutig ist.

**b)** Konstruieren Sie eine Rechtsableitung für den Satz *abab*.

**c)** Zeichnen Sie die Ableitungsbäume Ihrer Ableitungen.

# 2.3 Grammatik II

Lua ist eine kleine, sehr einfache Skriptsprache. Die vollständige Syntax in
EBNF-Form finden Sie in der [Dokumentation](https://www.lua.org/manual/5.4/).

**a)** Zeichnen Sie für folgende Codebeispiele anhand der EBNF jeweils den
zugehörigen Ableitungsbaum:

Beispiel 1:

    local function fac(n)
      if n == 0 then return 1
      else return n*fac(n-1)
      end
    end

Beispiel 2:

    for line in io.lines()
      io.write(line)
    end

Beispiel 3:

    opnames = { ["+"] = "add", ["-"] = "sub", ["*"] = "mul", ["/"] = "div" }

Beispiel 4:

    local i = 1
    while a[i] do
      print(a[i])
      i = i + 1

**b)** Welche Eigenschaften der Sprache können Sie aus dieser Aufgabe ableiten?

# 2.4 Grammatik III

Gegeben ist folgende Grammatik ("e" bezeichnet die leere Eingabe):

    S -> aSa | bB
    B -> bB | e

und folgender, einfacher Recursive-Descent-Parser dafür:

    enum Token { a, b, EndOfFile }

    class abbaParser {
    //...
    // Get lookahead
    Token LookAhead { get => scanner.Current; }

    // Check and consume lookahead
    void matchToken(Token token) {
      if (LookAhead == token)
        scanner.MoveNext();
      else
        throw new Exception();
    }

    //S -> aSa | B
    public void parseS() {
      switch (LookAhead) {
      case Token.a:
        matchToken(Token.a);
        parseS();
        matchToken(Token.a);
        break;
      case Token.b:
        parseB();
        break;
      case Token.EndOfFile:
        break;
      default:
        throw new Exception();
      }
    }

    //TODO: B -> bB | e

Ergänzen Sie die Methode `public void parseB()`.

# 2.5 Grammatik IV

Betrachten Sie folgenden Ausschnitt aus der Grammatik
einer Programmiersprache:

    IfStatement -> if ( Expression ) Statement | if ( Expression ) Statement else Statement
    Statement -> Assignment | IfStatement | Block
    Block -> { Statements }
    Statements -> Statements Statement | Statement

Angewendet wird die Grammatik auf dieses Codestück:

    if (x < 0)
      if (y < 0) y = y-1;
      else y = 0;

Welches Problem ergibt sich für das Parsen dieses Codefragments mit der zugehörigen
Grammatik? Kann man die Grammatik so umschreiben, dass sich das Problem umgehen lässt?

# 2.6 Scanner

Gegeben sind folgende reguläre Ausdrücke ((T) markiert terminale Produktionen):

    integer  -> digit digit*
    digit    -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 (T)

    id       -> letter letter*
    letter   -> a | b | c ... | z | A | B | ... | Z (T)

    add_op  → + | - (T)
    mult_op → * | / (T)

Schreiben Sie einen Scanner in der Sprache C (oder C++), der als Eingabe eine oder
mehrere beliebige Zeichenketten erhält und diese, sofern möglich in die entsprechenden
Token der Grammatik zerlegt. Die gefundenen Token sollen mit Attributen auf der Konsole
ausgegeben werden.

Beispiel:

Eingabe:

    42 + abc / 2

Ausgabe:

    integer(42)
    add_op(+)
    id(abc)
    mult_op(/)
    integer(2)

Falls die Eingabezeichen nicht den regulären Ausdrücken entsprechen soll ein Fehler ausgegeben werden.

# 2.7 Parser

Zusätzlich zu den regulären Ausdrücken aus Aufgabe 2.6 betrachten wir folgende Grammatik aus
der Vorlesung:

    expr    → term | expr add_op term
    term    → factor | term mult_op factor
    factor  → id | number | - factor | ( expr )

Können Sie zu dieser Grammatik einen Recursive-Descent Parser (LL(1)) schreiben,
der als Eingabe eine Zeichenkette erhält und als Ausgabe angibt, ob die Eingabe
sich nach der Grammatik ableiten lässt?

Falls ja, implementieren Sie einen solchen Parser. Falls nein, warum nicht?
Was müssen Sie ändern, um einen solchen Parser implementieren zu können?


