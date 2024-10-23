
fn outer() -> i32 {
  let a = 1;
  let second = || a;

  let first = || {
    let a = 2;
    second()
  };

  first()
}

fn main() {
  println!("{:?}", outer());
}
