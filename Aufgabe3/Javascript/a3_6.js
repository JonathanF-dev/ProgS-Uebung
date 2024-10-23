
function f1() {
  var a = 42;
  var x = "Bye";

  function f2(x) {
    a = "Hello";
    x = 27;

    function f3(a, x) {
      console.log(x);
      x = 3.14;
    }

    f3(x, a);
  }

  f2(x);
  console.log(a);
  console.log(x);
}

f1();
