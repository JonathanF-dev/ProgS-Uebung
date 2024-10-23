
"use strict";

function Num(a) {
  return (function() { return a });
}

function Plus(b, c) {
  return (function() { return b() + c() });
}

var d = 2;
var e = 3;
var f = Plus(Num(d), Plus(Num(e), Num(4)));

console.log(f());
e = 5;
console.log(f());
