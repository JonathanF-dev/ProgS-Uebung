
fn main() {
  let mut x = 1;

  {
    let y = &mut x;
    *y += 1;
  }

  println!("x = {}", x);
}