using System;

class Program {
  static Predicate<T> And<T>(Predicate<T> p1, Predicate<T> p2) {
    return (T t) => p1(t) && p2(t);
  }
  static Predicate<double> MakeIntervalTest(double min, double max) {
    Predicate<double> notLessMin = (double x) => min <= x;
    Predicate<double> notGreaterMax = (double x) => x <= max;
    return ... ; // 3. Teilaufgabe
  }
  static void Main(string[] args) {
    const double min = 0.0;
    const double max = 10.0;
    Predicate<double> IntervalTest = MakeIntervalTest(min, max);

    Console.WriteLine(IntervalTest(-5.0));
    Console.WriteLine(IntervalTest( 5.0));
    Console.WriteLine(IntervalTest(10.0));
    Console.WriteLine(IntervalTest(15.0));
  }
}
