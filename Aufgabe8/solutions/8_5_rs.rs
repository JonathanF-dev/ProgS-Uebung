#[allow(non_snake_case)]

struct Fibonacci {
  nextValue: i32,
  prevValue1: i32,
  prevValue2: i32
}

impl Fibonacci {
  fn new() -> Fibonacci {
    Fibonacci { nextValue: 1, prevValue1: 0, prevValue2: 0 }
  }
}

impl Iterator for Fibonacci {
  type Item = i32;

  fn next(&mut self) -> Option<Self::Item> {
    let curr = self.nextValue; // Caution: order is important here!
    self.prevValue1 = self.nextValue;
    self.nextValue = self.prevValue1 + self.prevValue2;
    self.prevValue2 = self.prevValue1;
    Some(curr)
  }
}

fn main() {
  let it = Fibonacci::new();
  let mut cnt = 0;
  for v in it {
    println!("{v}");
    cnt += 1;
    if cnt >= 20 {
      break;
    }
  }
}
