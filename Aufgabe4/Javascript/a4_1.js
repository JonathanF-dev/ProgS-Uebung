function main() {
  var arr = new Array();

  for (var i = 0; i < 10; ++i) {
    var j=0;
    arr[i] = function() { j++; console.log(j); }
  }

  arr.forEach(function(a) { a(); });
}

main();
