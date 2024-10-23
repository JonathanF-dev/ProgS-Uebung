#!/usr/bin/env node

function asyncFunction(resolve, reject) {
  resolve(10);
  //reject("Mooh!");
}

function doSomethingElse() {
  console.log("Doing something else...");
  return 42;
}

function main() {

  let p = new Promise(asyncFunction);

  p.then(function() {
    return doSomethingElse();
  }).then((value) => console.log("(1) Wert: " + value));


  p.then(function() {
    doSomethingElse();
  }).then((value) => console.log("(2) Wert: " + value));

  p.then(doSomethingElse()).then(
    (value) => console.log("(3) Wert: " + value));


  p.then(doSomethingElse).then(
    (value) => console.log("(4) Wert: " + value));
}

main();
