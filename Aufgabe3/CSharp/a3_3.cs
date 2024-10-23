using System;

namespace Scope {
  class Program  {
    const int j = 10;

    static void Main()  {
      int x = j;
      int j = 20;

      Console.WriteLine(x);
      Console.WriteLine(j);
    }
  }
}
