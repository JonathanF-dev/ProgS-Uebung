
function makeUnevenIterator(a, b) {

  let nextValue = a;

  const unevenIterator = {
    next() {
      while (nextValue <= b) {
        if ((nextValue % 2) != 0) {
          let rValue = nextValue;
          nextValue += 1;
          return { value: rValue, done: false };
        }
        nextValue += 1;
      }
      return { value: nextValue, done: true };
    },

    [Symbol.iterator]() { return this; }
  };
  return unevenIterator;
}

function* makeUnevenIteratorWithGenerator(a, b) {
  let nextValue = a;
  while (nextValue <= b) {
    if ((nextValue % 2) != 0) {
      yield nextValue;
    }
    nextValue += 1;
  }
  return nextValue;
}

it = makeUnevenIterator(1,10);

for (v of it) {
  console.log(v);
}

console.log("*")

it2 = makeUnevenIteratorWithGenerator(1,10);

for (v of it2) {
  console.log(v);
}
