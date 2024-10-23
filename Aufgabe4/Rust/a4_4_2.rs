
fn outer() -> i32 {
  let a = 1;

  fn second() -> i32 {
    a
  }

  fn first() -> i32 {
    let a = 2;
    second()
  };

  first()
}

fn main() {
  println!("{:?}", outer());
}
