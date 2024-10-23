
fn main() {
  let mut y = String::from("Hello");
 
  let a = &y;
  let b = &y;
  // Variante 1
  let c = &mut y;

  println!("a = {}", a);
  println!("b = {}", b);
  
  // Variante 2
  // let c = &mut y;
  println!("b = {}", c);
  
  print!("x = {}", y);
}
