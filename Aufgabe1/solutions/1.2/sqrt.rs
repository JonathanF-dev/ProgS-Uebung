
#![allow(non_snake_case)]

use std::io;
use std::io::Write;

fn sqrt_newton(x :f64) -> f64 {
  let mut y = 1.0;
  while (y*y-x).abs() > 0.0000001 {
    y = 0.5*(y + x/y);
  }
  y
}

fn main() {
  let mut xStr = String::new();

  print!("Bitte geben Sie eine Zahl ein: ");
  io::stdout().flush().unwrap();
  io::stdin().read_line(&mut xStr).expect("Fehler beim lesen der Eingabe!");

  let x = xStr.trim().parse::<f64>().expect("Ich kann die Eingabe nicht zu einer Zahl konvertieren!");

  println!("Die Wurzel aus {} ist {}", x , sqrt_newton(x));
}
