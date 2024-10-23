

function makeConverter(f, o) {
  return (i) => (o+i) * f;
}

function main() {
  mtk = makeConverter(1.60936, 0.0)
  ptk = makeConverter(0.45460, 0.0)
  ftc = makeConverter(0.5556, -32.0)

  console.log(mtk(10))
  console.log(ptk(2.5))
  console.log(ftc(98))
}

main();