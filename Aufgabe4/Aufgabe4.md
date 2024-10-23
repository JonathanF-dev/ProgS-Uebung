
# 4.1 Closures in Javascript

Untersuchen Sie das Programm **Javascript/a4_1.js**.

* An welchen Stellen im Programm entstehen Closures? Welche Variablen werden jeweils gefangen?
* Skizzieren Sie, wie der Stack und der Heap des Programms in Zeile 8 aussehen müsste.
* Übersetzen Sie das gegebene Programm nach C++.
* Übersetzen Sie das gegebene Programm nach Python.
* Sind die Ausgaben der drei Programme gleich? Falls nein, warum nicht?

# 4.2 Speicherverwaltung

Untersuchen Sie das Programm **CSharp/a4_2.cs**.

* Was ist die Ausgabe des Programms?
* Werden nach einem Aufruf der Methode "pop()" der Klasse IntStack
  die entsprechenden Instanzen der Klasse IntStackItem wieder richtig
  freigegeben? Überlegen Sie sich, wie Sie dies überprüfen können (Tipp: MSDN!).
* Zeichnen Sie den Stack und den Heap des Programms während der Ausführung an
  der Stelle (1) (Hinweis: mit Stack ist hier der Stack der VM gemeint, nicht die Datenstruktur *IntStack*).
* Geben Sie eine äquivalente und korrekte Implementierung in C++ ohne(!) Verwendung der STL (z.B. std::vector, std::shared_ptr, etc.) an.

# 4.3 Closures in C++

Untersuchen Sie das Programm **CPP/a4_3.cpp**.

* Beschreiben Sie, was das Programm tut. Was ist die Ausgabe?
* An welchen Stellen im Programm entstehen Closures?
* Was macht das Schlüsselwort "auto"?
* Welchen konkreten Typ haben die Variablen milesToKm, poundsToKg und fahrenheitToCelsius?
* Zeichnen Sie den Stack und den Heap des Programms an der Stelle (1).
  Hinweis: Überlegen Sie sich, wie Closures vom C++ Compilern implementiert werden.
* Geben Sie eine Implementierung des Programms in JavaScript an.
* Geben Sie eine Implementierung des Programms in Python an.
* Beschreiben Sie die wesentlichen Unterschiede der Implementierungen (falls vorhanden).

# 4.4 Closures in Rust

Untersuchen Sie die Programme **Rust/a4_4_1.rs** und **Rust/a4_4_2.rs**.

* Geben Sie an, was die Ausgabe der beiden Programme ist.
* Kompilieren beide Beispiele erfolgreich?
* Falls nein, erklären Sie, was genau das Problem ist.
* (**Achtung Spoiler**) Wie können Sie a4_2_2.rs so anpassen, dass das Beispiel kompiliert und
  die richtige Ausgabe liefert, _ohne_ Rusts Lambdaausdrücke zu verwenden?


# 4.5 Zusatzaufgabe: Stacklayout in C++ (für Fortgeschrittene)

Implementieren Sie in C++ ein Programm, welches Ihnen das konkrete Stack Layout lokaler Variablen einer von Ihnen selbst definierten Funktion anzeigt. Überlegen Sie sich dazu, welche Sprachmittel Sie nutzen können, um das Ziel zu erreichen und wie Sie Ihre Implementierung überprüfen können (Hinweis: Zeigertypen(__*__) und Adressoperator (__&__)!).

Testen Sie Ihr Programm mit verschiedenen Compilern (z.B. MSVC, Clang, GCC). Erzeugen alle Compiler das gleiche Layout für Ihre Funktion? Falls nein, welche Unterschiede gibt es?
