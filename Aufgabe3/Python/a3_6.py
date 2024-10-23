
def f1():
  a = 42
  x = "Bye"

  def f2(x):
    a = "Hello"
    x = 27

    def f3(a, x):
      print(x)
      x = 3.14

    f3(x, a)

  f2(x)
  print(a)
  print(x)

f1()
