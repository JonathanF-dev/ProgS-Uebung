
fn main() {
  let y: &i32;

  {
    let x = 5;
    y = &x;
  }

  print!("x = {}", y);
}
