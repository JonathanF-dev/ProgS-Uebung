using System;
using System.Collections;

namespace Aufgabe8 {

  class Shape {
    public string draw() { return "Generic Shape"; }
  }

  class RoundShape {
    public string draw()  { return "Round Shape"; }
  }

  public class Bindungen {

    public static void Main() {

      ArrayList al = new ArrayList();

      al.Add(new RoundShape());
      al.Add(new Shape());
      al.Add(new RoundShape());
      al.Add(new Shape());

      foreach (var s in al) {
        System.Console.WriteLine(s.draw());
      }

      foreach (var s in al) {
        System.Console.WriteLine(((Shape)s).draw());
      }

    }
  }
}
