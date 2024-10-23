
# 8.1 Exceptions in C++

Die [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) tragen
einen Satz von Regeln - "Best Practices" - für die Verwendung der C++ Programmiersprache zusammen.

Regel E.15 sagt aus: "Catch exceptions from a hierachy by reference".

Erklären Sie, weshalb die Regel dies empfiehlt.

# 8.2 Exceptions in C++ (II)

Betrachten Sie folgenden Codeausschnitt:

    void f() {
      // ...
      try {
            // ...
      }
      catch (Base& b) { /* ... */ }
      catch (Derived& d) { /* ... */ }
      catch (...) { /* ... */ }
      catch (std::exception& e){ /* ... */ }
    }

Erklären Sie, was an diesem Code problematisch ist.

# 8.3 Iteratoren

Implementieren Sie einen Iterator bzw. Generator, der nur die ungeraden Zahlen innerhalb eines
vom Benuter spezifizierten Intervalls \[a,b\] zurückliefert. Erstellen Sie eine Implementierung
in den Sprachen

* Rust
* Javascript
* Python
* Haskell

Vergleichen Sie die Implementierungen. Welche Unterschiede gibt es?

Wie müssten Sie vorgehen, wenn Sie einen solchen Iterator in C++ implementieren müssten?

# 8.4 Rekursion

Implementieren Sie ein Programm in Haskell, welches die [Fibonacci](http://de.wikipedia.org/wiki/Fibonacci-Folge)-Zahl
zu einer gegebenen Benutzereingabe ausrechnet und ausgibt. Ist die von Ihnen implementierte Variante rest-rekursiv?

Geben Sie eine rest-rekursive Implementierung an.

# 8.5 Generatoren

Implementieren Sie die Fibonacci-Folge als Generator in einer von Ihnen gewählten Programmiersprache. Geben
Sie dazu ein vollständiges Beispielprogramm an.

# 8.6 C++ Operatoren

Untersuchen Sie das Programm **CPP/a8_6.cpp**.

* Das Programm verwendet in Zeile 6 einen ungewöhnlichen Operator (-->). Geben Sie an, um
  welchen Operator es sich dabei handelt und erklären Sie genau, was dieser tut.

# 8.7 C++ Operatoren II

Seit C++ gibt es den sogenannten *Spaceship-Operatpor* (<=>). Erklären Sie, wozu dieser gut ist.

# 8.8 Promises in Javascript

Die HTML5 fetch-API verpackt eine asynchrone HTTP Anfrage und liefert eine Promise zurück.
Ursprünglich wurde für asynchrone HTTP Anfragen die XMLHttpRequest-API verwendet. Schreiben
Sie eine Funktion

    myfetch(url)

in Javascript, die einen klassischen XMLHttpRequest kapselt und eine Promise zurückliefert,
die sich entsprechend verhält.

# 8.9 Nochmal Promises in Javascript

Erklären Sie den Unterschied zwischen den folgenden vier Promises:

    doSomething().then(function () {
      return doSomethingElse();
    });

    doSomething().then(function () {
      doSomethingElse();
    });

    doSomething().then(doSomethingElse());

    doSomething().then(doSomethingElse);

# 8.10 Promise vs. Future

C++ und Rust kennen sowohl für Promises als auch für Futures
eigene Typen. Geben Sie an, welche dies sind und erklären Sie
den Unterschied.

Implementieren Sie jeweils ein eigenes Beispielprogramm in C++
und Rust, welches Promises und Futures verwendet. Erklären Sie,
was Ihr Programm tut. Vergleichen Sie es mit einer Javascript
Implementierung.

# 8.11 Rekursion

Implementieren Sie eine rest-rekursive Berechnung der Fakultätsfunktion n! in Haskell.
