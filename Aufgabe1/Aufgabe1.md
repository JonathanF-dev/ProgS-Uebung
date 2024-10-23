
# 1.1 "Hallo Welt"

Implementieren Sie ein "Hallo Welt" Programm in den Sprachen

  - C++
  - Python
  - Rust
  - Haskell
  - ECMAScript (Javascript)

Welche Unterschiede gibt es, die in den einzelnen Sprachen vom Quellcode
zum ausführbaren Programm führen?

Geben Sie für jede Sprache an, was nun genau mit dem "ausführbaren
Programm" gemeint ist.

# 1.2 Quadratwurzel

Um die Quadratwurzel einer Zahl zu bestimmen, verwendet man häufig das
[Newton-Verfahren](https://en.wikipedia.org/wiki/Newton%27s_method).

Schreiben Sie eine Funktion *newton_sqrt* in den Sprachen C++, Python,
Rust, Haskell und ECMAScript, die den Algorithmus implementiert und
damit die Quadratwurzel einer Zahl berechnet. Erstellen Sie dazu ein
vollständiges Beispielprogramm, welches eine Ein-/Ausgabemöglichkeit
durch/an den Benutzer enthält und die Anwendung der Funktion demonstriert.

# 1.3 Insertion Sort

Implementieren Sie den [Insertion-Sort](https://en.wikipedia.org/wiki/Insertion_sort)
Algorithmus in den Sprachen C++, Python, Rust, Haskell und ECMAScript. Erstellen Sie
dazu jeweils eine Funktion *insertion_sort*, die das Verfahren umsetzt, sowie ein
kleines Beispielprogramm, das ihre Anwendung demonstriert.

# 1.4 Strukturierung des Quellcodes / Module

Teilen Sie die, in Aufgaben 1.2 und 1.3 implementierten Programme, jeweils in zwei
Teile auf:

  * Eine Datei, die den entsprechenden Quellcode der Implementierung des Verfahrens
    enthält (newton_sqrt, insertion_sort), sowie
  * eine zweite Datei, die das Hauptprogramm enthält.

Welche Schritte sind notwendig, um die verschiedenen Dateien in den jeweiligen
Sprachen zu einem ausführbaren Programm zusammenzuführen?

Gibt es wesentliche Unterschiede in der Durchführung dieser Aufteilung zwischen den
einzelnen Sprachen? Welche?

# 1.5 C#

Bisher scheint nun klar zu sein: Programme compilierter Sprachen
benötigen einen designierten Einstiegspunkt (meist eine Variation
von "main"). Aktuelle Implementierungen des Microsoft .NET C#
Compilers unterstützen allerdings ein Feature namens "Top-Level
Statements". Damit scheint es für C# Programme kein "Main" mehr
zu geben?

- Benötigen C# Programme tatsächlich keinen designierten Einstiegspunkt mehr?
- Falls nein, warum nicht? Falls doch, wo ist er hin?
- Welche weiteren Implikationen ergben sich für C# Programme durch
die Verwendung der "Top-Level-Statements"?

# Zusatzaufgabe - Assembler vs. Hochsprachen

Untersuchen Sie das Programm **Assembler/programm.asm**.

Sie können das Programm mit folgendem Befehl auf der Kommandozeile
(Visual Studio **x86** Native Tools Command Prompt) assemblieren:

    ml.exe programm.asm /link /subsystem:console kernel32.lib

Als Ergebnis erhalten Sie eine Binärdatei "programm.exe", welche Sie
in der Konsole ausführen können.

Versuchen Sie herauszufinden, was das Programm tut und geben Sie eine
äquivalente Implementierung in einer Hochsprache Ihrer Wahl an.
Vergleichen Sie diese mit der Assemblerimplementierung.
