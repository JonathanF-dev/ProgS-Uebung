
#![allow(non_snake_case)]

use std::io;
use std::io::Write;

enum Opt {
  Value(f64),
  Err(i32)
}

impl Opt {
  fn my_unwrap(self) -> f64 {
    match self {
      Opt::Value(x) => x,
      Opt::Err(_) => panic!("Invalid value")
    }
  }
}

fn sqrt_newton(x :f64) -> Opt {
  let mut y = 1.0;

  if x < 0.0 {
    return Opt::Err(-1);
  }

  while (y*y-x).abs() > 0.0000001 {
    y = 0.5*(y + x/y);
  }
  Opt::Value(y)
}

fn main() {
  let mut xStr = String::new();

  print!("Bitte geben Sie eine Zahl ein: ");
  io::stdout().flush().unwrap();
  io::stdin().read_line(&mut xStr).expect("Fehler beim lesen der Eingabe!");

  let x = xStr.trim().parse::<f64>().expect("Ich kann die Eingabe nicht zu einer Zahl konvertieren!");

  let r = sqrt_newton(x).my_unwrap();
  println!("{}", r);
  /*
  match r {
    Opt::Value(v) => println!("Die Wurzel aus {} ist {}", x , v),
    _ => println!("Mäh"),
    // Opt::Err(s) => println!("Fehler: {}", s)
  }
  */
}
