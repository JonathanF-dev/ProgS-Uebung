# 7.1 Noch mehr Closures (in C#)

Untersuchen Sie das Programm **CSharp/a7_1.cs**.

* Was ist *Predicate<T>*?

  Ein Funktionstyp (Delegate), der
  einen boolschen Wert zurückliefert.

* Was tut die Funktion *And*?

  Sie verknüft zwei Predicates
  mit einem logisch UND (&&).

* Verwenden Sie die Funktion *And*, um in *MakeIntervalTest* die Prüfung *min <= x <= max* zu implementieren.

  return And<double>(notLessMin, notGreaterMax);

* An welchen Stellen im Programm werden Closures erzeugt?

  Zeile 8, 9 und 15

* Welche Variablen oder Parameter werden jeweils von den Closures gefangen?

  min, max aus Main von notLessMin und notGreaterMax
  notLessMin und notGreaterMax von And

* Wie viele Closures werden im gesamten Programmablauf gebildet?

  3

* Wie viele Variablen oder Parameter werden im gesamten Programmablauf gefangen?

  4

# 7.2 Closures in C++

Untersuchen Sie das Programm **CPP/a7_2.cpp**.

* Was wird von dem Programm ausgegeben?

  1.5

* Was bewirkt der Aufruf von *std::transform*?

  Läuft über alle Elemente des std::vectors
  und ändert diese (zu 1/n)

* Was bewirkt der Aufruf von *std::accumulate*?

  Läuft über alle Elemente des std::vectors
  und akkumuliert diese (akku + elem).
  Liefert einen einzigen Wert zurück.

* An welchen Stellen im Programm werden Closures gebildet?

  Z. 12 (bis 16) und 18 (bis 22)

* Welche Variablen oder Parameter werden von den Closures jeweils gefangen?

  Closure Z. 12 fäng stacklokale Variable i
  per Referenz. Closure Z. 18 fängt nichts.

* Implementieren Sie eine Version des Programms, das **ohne** Lambdaausrücke auskommt.

  Siehe a7_2.cpp in solutions

# 7.3 Closures in Javascript

Untersuchen Sie das Programm **Javascript/a7_3.js**.

* Was ist die Ausgabe des Programms?

  9
  9

* An welchen Stellen im Programm werden Closures erzeugt?

  Z. 4, 8, 14

* Wie viele Closures werden im Programmablauf insgesamt erzeugt?

  5 (3x Num, 2x Plus)

* Welchen Wert liefert *Num(4)* zurück?

  Ein Funktionsobjekt(!).
  Wenn das aufgerufen wird liefert
  es die Number 4 zurück.

* Wie viele Additionen werden insgesamt ausgeführt?

  2

* Formulieren Sie *Num* und *Plus* als C++ Funktionen mit Lambdaausdrücken.

template<typename T>
std::function<T (T)> Num(T a) {
  return [a] => { return a; };
}

template<typename T>
std::function<T (T)> Plus(std::function<T (T)> b, std::function<T (T)> c) {
  return [b, c] => { return b() + c(); };
}
