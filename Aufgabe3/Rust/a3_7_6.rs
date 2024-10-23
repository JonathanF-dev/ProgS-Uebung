
fn main() {
  let y = String::from("Hello");
  // Probieren Sie alle drei Varianten aus!
  let x = y;
  // let x = &y;
  // let x = &mut y;
  
  print!("x = {}", y);
}
