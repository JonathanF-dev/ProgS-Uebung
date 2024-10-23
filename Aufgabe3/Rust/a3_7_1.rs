#![allow(non_snake_case)]

fn doSth(val : Vec<i32>) -> i32 {
  val[2]
}

fn main() {

  let x = vec![0, 1, 2, 3, 4];
  let y = doSth(x);

  println!("value = {}", x[2]);

}