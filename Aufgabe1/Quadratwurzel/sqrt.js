const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });

  readline.question('Bitte gib ein Zahl ein', zahl =>{
    console.log(`Die Wurzel aus ${zahl} ist ${newton_sqrt(zahl)}`)
    readline.close();
  })
function newton_sqrt (x){
    percision = 0.000001;
    maxit = 1000;
    iter = 0;
    xn = 1;
    while(Math.abs(xn*xn - x) > percison && iter < maxit){
        xn = 0.5*(xn + x/xn);
    }
    return xn;
}