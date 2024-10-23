
function sqrt_newton(x) {
  const EPSILON  = 0.000001;
  const MAX_ITER = 10000;

  let iter     = 0;
  let estimate = 1.0;

  while (Math.abs(estimate*estimate - x) > EPSILON && iter < MAX_ITER) {
    estimate = 0.5*(estimate + x/estimate);
    ++iter;
  }

  return estimate;
}

// Node.js stuff
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Bitte geben Sie eine Zahl ein:', (x) => {
  console.log(`Die Wurzel aus ${x} ist ${sqrt_newton(x)}`);
  rl.close();
});