

def makeConverter(f, o):
  return lambda i: (o+i) * f

def main():
  mtk = makeConverter(1.60936, 0.0)
  ptk = makeConverter(0.45460, 0.0)
  ftc = makeConverter(0.5556, -32.0)

  print(mtk(10))
  print(ptk(2.5))
  print(ftc(98))

main()