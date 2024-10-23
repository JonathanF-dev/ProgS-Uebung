# Lösungsvorschläge bzw. Hinweise zu Aufgabe 5

# 5.1 Closures in C++

Untersuchen Sie das Programm **CPP/a5_1.cpp**.

* Erklären Sie, was das Programm tun soll.
 - Das Programm erzeugt eine Closure in
   der eine benutzerdefinierte Instanz
   der Klasse Integer, die einen int-Wert
   repräsentiert, gefangen wird und 
   der Parameter dieser Closure zu dem
   gespeicherten Wert addiert werden soll. 
* Welchen Typ hat x?
 - int
* Welchen Typ hat f?
 - std::function<int (int)>
* Was erwarten Sie als Ausgabe des Programms?
 - 4
* Kompiliert das Programm? Falls ja, führen Sie es aus.
* Erklären Sie genau, was bei der Ausführung passiert.
 - Integer speichert den zugehörigen int
   Wert auf dem Heap (new im Konstruktor)
 - Der Destrukor gibt den Speicher wieder
   frei
 - In getAdder wird eine Instanz dieser 
   Klasse erzeugt und eine Kopie(!) davon
   in der zurückgegebenen Closure gespeichert
 - Da die Klasse keinen Kopierkonstruktor implementiert wird der Zeiger auf den gespeicherten int bitweise kopiert
 - Beim Verlassen der Funktion getAdder
 wird die Instanz i zerstört, der Destruktor wird aufgerufen und der Speicher für den Integer freigegeben
 - Der Zeiger in der Kopie (Closure) wird 
 im Funktionsobjekt f in main weiterverwendet
 - Der Aufruf f(x) greift bereits auf gelöschten
 Speicher zu (Kopie von i_ aus getAdder) ->
 Undefiniertes Verhalten
 - Beim Beenden von Main wird das Closure-Objekt
 Zerstört und ebenso das eingebettete Integer-Objekt. Dort wird wieder der Destruktor
 aufgerufen und versucht den bereits freigegeben Speicher von i noch einmal freizugeben

# 5.2 C++

Untersuchen Sie das Programm **CPP/a5_2.cpp**.

* Was erwarten Sie als Ausgabe des Programms?
 - 2
* Was ist die tatsächliche Ausgabe?
 - Möglicherweise 42, aber das ist undefiniertes
 Verhalten
* Erklären Sie das Verhalten des Programms.
 - foo gibt eine Referenz(! -> Speicheradresse) auf eine lokal im Stack alloziierte Variable zurück.
 - Nach foo() ist x also eine dangling Reference
 - Wenn 42 die Ausgabe ist: bar überschreibt
 den Speicherslot auf den x zeigt zufällig mit 
 den eigenen stacklokalen Variablen.

# 5.3 Noch mehr C++

Untersuchen Sie das Programm **CPP/a5_3.cpp**.

* Erklären Sie den Unterschied zwischen einem L-Value und einem R-Value.
 - L-Value: Ausdruck der einen Speicherplatz liefert (i.d.R. Variable) 
 - R-Value: Ausdruck der einen Wert liefert

* Compilieren Sie das Programm. Erklären Sie für jede Ausgabe genau, wie diese zustande kommt.

- Hier sollte man sich die Unterschiede klar
machen zwischen 
  - Konstruktion von Objekten
  - Konstruktion von Objekten aus einer Kopie
  - Zuweisung
  - Zuweisung und Konstruktion aus unbenannten Objekten

# 5.4 Wieder C++

Untersuchen Sie das Programm **CPP/a5_4.cpp**.

* Kompilieren Sie das Programm. Erklären Sie genau was passiert.
* Offensichtich gibt es mit dem Programm ein Problem. Geben Sie eine Lösung dafür an.

 - Wikipedia: "Most vexing parse"

# 5.5 Stack in C++

Untersuchen Sie das Programm **CPP/a5_5.cpp**.

* Sehen Sie sich nur den Quellcode des Programm an. Fällt Ihnen ein Fehler auf?
* Kompilieren Sie das Programm. Kompiliert es ohne Fehler und/oder Warnungen?
* Was ist die Ausgabe des Programms?

* Zeichnen Sie ein Abbild des Stacks und des Heaps des Programms. Können Sie
anhand dessen die Ausgabe erklären?

- In dem Beispiel geht es um das Überschreiten
von Array-Grenzen (wieder undefiniertes verhalten). Die Ausgabe und das Verhalten hängen vom konkreten Stacklayout ab, welches der Compiler erzeugt (Array auf dem Stack, Position von x, Rücksprungadresse). 

# 5.6 Typen in JavaScript I 

Gegeben ist folgender Javascript Code:

    function sumit(a, first, n) {
      var sum = 0;
      var i;
      for (i = first; i < first+n; i++) {
        sum += a[i];
      }
      return sum;
    }

    var f = sumit([ 1, 2, 3, 4 ], 1, '3');

    console.log(f);

* Was ist die Ausgabe des Programms?
- NaN

* Erklären Sie, was passiert.
first+n wird zu 1+'3', JavaScript konvertiert
die 1 in '1' und hängt die Zeichen zu '13' 
zusammen, die dann in die Zahl 13 konvertiert
werden. Folge: die Arraygrenzen werden überschritten. Mit starker Typisierung wäre
das (hoffentlich) nicht passiert.

# 5.7 Typen in JavaScript II

Javascript-Objekte kennen die Methoden *toString()* und *valueOf()*.

* Erklären Sie, in welchem Zusammenhang die beiden Methoden stehen und wie bzw. wann diese  verwendet werden.

- Nachlesen unter https://ecma-international.org/publications-and-standards/standards/ecma-262/