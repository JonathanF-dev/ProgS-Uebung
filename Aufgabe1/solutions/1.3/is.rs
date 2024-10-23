#![allow(non_snake_case)]

use std::convert::TryInto;

fn insertionSort(a :Vec<i32>) -> Vec<i32> {
  let mut res: Vec<i32> = a.to_vec();
  let mut i = 1;

  while i < res.len() {
    let k = res[i];
    let mut j: isize = (i - 1).try_into().unwrap();

    while j >= 0 && res[j as usize] > k {
      res[(j + 1) as usize] = res[j as usize];
      j = j - 1;
    }
    res[(j + 1) as usize] = k;

    i = i + 1;
  }
  res 
}

fn insertionSortInPlace(a :&mut Vec<i32>) {
  let mut i = 1;

  while i < a.len() {
    let k = a[i];
    let mut j: isize = (i - 1).try_into().unwrap();

    while j >= 0 && a[j as usize] > k {
      a[(j + 1) as usize] = a[j as usize];
      j = j - 1;
    }
    a[(j + 1) as usize] = k;

    i = i + 1;
  }
}

fn main() {
  /* Variante 1

  let array = vec![4,30,2,3,6,99,8,11,23];
 
  let sorted_array = insertionSort(array);
  print!("Sorted: [");
  for n in 0..sorted_array.len()-1 {
    print!("{}, ", sorted_array[n]);
  }
  print!("{}", sorted_array[sorted_array.len()-1]);
  println!("]");
  */

  /* Variante 2 */ 
  let mut array = vec![4,30,2,3,6,99,8,11,23];
 
  insertionSortInPlace(&mut array);
  print!("Sorted: [");
  for n in 0..array.len()-1 {
    print!("{}, ", array[n]);
  }
  print!("{}", array[array.len()-1]);
  println!("]");

}
