#[allow(non_snake_case)]

struct UnevenIterator {
  nextValue: i32,
  maxValue: i32
}

impl UnevenIterator {
  fn new(a :i32, b :i32) -> UnevenIterator {
    UnevenIterator { nextValue: a, maxValue: b }
  }
}

impl Iterator for UnevenIterator {
  type Item = i32;

  fn next(&mut self) -> Option<Self::Item> {
    while self.nextValue <= self.maxValue {
      let current = self.nextValue;
      self.nextValue += 1;
      if current % 2 != 0 {
        return Some(current)
      }
    }
    None
  }
}

fn main() {

  let it = UnevenIterator::new(1,10);

  for v in it {
    println!("{v}");
  }
}
