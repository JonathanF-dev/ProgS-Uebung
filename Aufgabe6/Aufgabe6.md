
# 6.1 Typinferenz in C#

Untersuchen Sie das Programm **CSharp/a6_1.cs**.

* Compiliert das Programm? Falls ja, was ist die Ausgabe des Programms? Falls nein,
  was genau ist der Fehler? Wie kann man diesen beheben?
* Welchen statischen Typ haben die Objekte in der ArrayList "al"? Welchen dynamischen Typ?
* Welchen Typ hat die Variable s in Zeile 25?
* Erklären Sie, was in Zeile 30 passiert?

# 6.2 Strukturen und Arrays I

Gegeben ist folgende Deklaration einer Struktur in C++:

    struct A {
      short s;
      char c;
      int t;
      char d;
      double f;
      int i;
    };

Es sollen folgende Größen für Datentypen gelten: 'char' 1-byte, 'short' 2-bytes, 'double' 8-bytes, 'int' 4-bytes.
Weiterhin soll für das Alignment gelten, dass alle primitiven Datentypen ihrer Größe entsprechend im Speicher ausgerichtet
sein sollen (d.h. 'char' an vielfachen von 1-byte Adressen, 'short' an vielfachen von 2 usw.). Es handelt sich um eine 64-bit
Architektur.

* Welche Gesamtgröße hat eine Instanz dieser Struktur in Bytes?
* Welche Größe ergibt sich für ein Array mit 10 Elementen dieser Struktur?
* Wenn es erlaubt wäre, die Elemente der Struktur umzuordnen, um den Speicherbedarf zu optimieren, wie sähe die
  optimale Anordnung der Strukturelemente aus? Wie verändert sich der Speicherbedarf (z.B. auch bzgl. eines Arrays
  mit mehreren Elementen der Struktur)?

# 6.3 Strukturen und Arrays II

Gegeben ist folgende Deklaration in C++:

    struct {
      int n;
      char c;
    } A[10][10];

Sei die Speicheradresse des Elements A[0][0] gleich 1000 (dezimal). Welche Adresse hat das Element A[3][7]?

# 6.4 Strukturen und Arrays III

Gegeben ist folgendes C# Programm:

    namespace Aufgabe9 {

      struct A {
        public string str;
        public short s;
      }

      struct B {
        public int  a;
        public bool b;
        public A    c;
      }

      class Program {

        public static void foo() {
            int    i = 2;
            double j = 1.0;

            B k;
            k.a     = 1;
            k.b     = true;
            k.c.str = "Hi";
            k.c.s   = 255;

            B[] l = new B[3];
            l[0] = k;
            l[1] = l[0];
            l[2] = l[1];
            /* a) */
        }

        public static void Main(string[] args) {
            foo();
        }
      }
    }

Es gelten folgende Datentypgrößen und Alignments: bool 1-byte, short 2-byte, int 4-byte, double 8-byte,
Referenzen 8-byte (64-bit Architektur). Weiterhin sei im folgenden **F** die Anfangsadresse des Stackframes von *foo*.

* Zeichnen Sie ein Abbild des Speichers an der mit **a)** gekennzeichneten Stelle. Beschriften Sie die Stackframes
  mit den Namen der Prozeduren, Variablen und Werte, soweit diese bekannt sind. Verwaltungsinformationen können sie weglassen.
* Geben Sie einen vereinfachten Ausdruck an, mit dem zur Laufzeit der Wert von *k.b* erhalten werden kann (Adresse relativ zum Anfang des Stackframes).
* Geben Sie einen vereinfachten Ausdruck an, mit dem zur Laufzeit die Adresse des Strings *l[2].c.str* erhalten werden kann.
* Das Array *l* enthält zusätzliche Verwaltungsinformationen. Welche Größen sind das, wozu dienen sie, und welche Werte haben sie für *l*?
* Die Größe und das Alignment der Zeichen in einem String sind nicht angegeben. Wie groß sind diese in modernen Sprachen wie C# oder Java?
* In C# kann man auch das Null-Zeichen als **\0** in einen String einbetten, ohne dass der String dadurch terminiert wird. Wie kann das Laufzeitsystem
  dennoch die Größe eines Strings feststellen, also wie kann die Property *Length* diese liefern?

# 6.5 Strukturen und Arrays IV

Gegeben sind folgende C++ Definitionen:

    struct {
      short s;
      float f;
    } array_of_structs[4][3];

    struct {
      short s[4][3];
      float f[4][3];
    } struct_of_arrays;

Nehmen Sie an, dass der Datentyp short 2- und der Datentyp float 4-byte Speicher benötigt. Weiterhin sollen
die Datentypen 2- bzw. 4-byte-aligned sein und Strukturen weder gepackt noch umgeordnet werden dürfen (64-bit Architektur).

* Zeichnen Sie das Speicherlayout von array_of_structs. Zeichnen Sie im Detail nur das erste Array-Element.
* Zeichnen Sie das Speicherlayout von struct_of_arrays. Zeichnen Sie im Detail nur das erste Array-Element.
* Geben Sie den Speicherbedarf von array of structs an.
* Geben Sie den Speicherbedarf von struct of arrays an.
* Geben sie eine Formel an, mit der sich die Adresse des Elements *array_of_structs[i][j].f* berechnen lässt.
* Geben sie eine Formel an, mit der sich die Adresse des Elements *struct_of_arrays.f[i][j]* berechnen lässt.
* Sind Arrays von Strukturen oder Strukturen von Arrays effizienter? Begründen Sie Ihre Antwort.

# 6.6 Smart-Pointer in C++

Gegeben ist folgendes C++ Programm:

    #include <iostream>
    #include <memory>

    int main(int argc, char* argv[]) {

      std::shared_ptr<int> s1(new int(2));
      std::shared_ptr<int> s2;
      std::unique_ptr<int> u1(new int(3));
      std::weak_ptr<int>   w1;
      std::shared_ptr<int> s3 = w1;

      {
        std::shared_ptr<int> s4(s1);
        s2 = s4;
        std::unique_ptr<int> u2(std::move(u1));
        std::shared_ptr<int> s5(new int(5));
        w1 = s5;
        std::unique_ptr<int> u3(u2);
        /**/
      }

      s1.reset();
      std::shared_ptr<int> s6 = w1.lock();

      std::cout << (s1 != nullptr ? *s1 : 0) << std::endl;
      std::cout << (s2 != nullptr ? *s2 : 0) << std::endl;
      std::cout << (u1 != nullptr ? *u1 : 0) << std::endl;
      std::cout << (s6 != nullptr ? *s6 : 0) << std::endl;
      return 0;
    }

* Geben Sie alle Zeilennummern an, die Compilerfehler auslösen. Aus welchem Grund entstehen diese Fehler?

In den folgenden Aufgaben sollen die entsprechenden Zeilen als gelöscht gelten.

* Was ist die Ausgabe des Programms?
* Zeichnen Sie den Stackframe von main() und alle Heap-Objekte an der Stelle /**/.
* Vor C++ 11 gab es in der STL die Klasse std::auto_ptr (aktuell ist diese "deprecated"). Warum eignet sich diese
  Implementierung semantisch nicht als Smart-Pointer?

# 6.7 Entweder-Oder Typen I

Zu Aufgabe 1.2 sollten Sie inzwischen eine Lösung für die Implementierung in Haskell und Rust haben.
Leider haben wir in der Aufgabenstellung die Fehlerbehandlung völlig außer Acht gelassen. So kann z.B.
der Benutzer negative Zahlen eingeben, für die die Quadratwurzel nicht definiert und der Algorithmus
damit nicht anwendbar ist.

Erweitern Sie die Haskell und die Rust Implementierung jeweils um einen neuen Datentyp *Opt*, der entweder
die Lösung der Quadratwurzelberechung enthält oder im Fehlerfall (z.B. falsche Eingabe) eine Fehlermeldung
als String. Die Funktion zur Berechnung der Quadratwurzel soll nun eine Instanz des *Opt*-Typen zurückliefern.
Im Hauptprogramm soll dieser Rückgabewert dann entsprechend verarbeitet werden und entweder ein Ergebnis oder
die Fehlermeldung auf dem Bildschirm ausgeben.

# 6.8 Entweder-Oder Typen II

Die Rust Standardbibliothek enthält bereits einen vordefinierten Datentyp *Option<T>*, um optionale Werte
zu speichern. Auf diesem Typ ist die Methode "unwrap()" definiert, die es dem Programmierer erlaubt, direkt den
im Datentyp gespeicherten Wert zu extrahieren, ohne ein Pattern Matching durchzuführen.

Lesen Sie sich die Rust Dokumentation zur *unwrap()* Methode durch. Wie müsste diese Methode implementiert sein?
Implementieren Sie eine Funktion *my_unwrap*, welche einen Parameter vom Typ *Option<T>* erhält und sich ansonsten
genauso verhält, wie die Methode *unwrap()* (selbstverständlich dürfen Sie diese für diese Aufgabe nicht verwenden!).

# 6.9 Entweder-Oder Typen III

Wie würde eine Lösung zu Aufgabe 6.7 in C++ aussehen?

