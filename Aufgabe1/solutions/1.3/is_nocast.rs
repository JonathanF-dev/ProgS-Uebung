#![allow(non_snake_case)]

// This avoids casting by slightly altering the loop
fn insertionSort(a :Vec<i32>) -> Vec<i32> {
  let mut res: Vec<i32> = a.to_vec();

  for i in 1..res.len() {
    let mut j = i;
    let k = res[i];

    while j > 0 && k < res[j-1] {
      res[j] = res[j-1];
      j = j - 1;
    }

    res[j] = k;
  }
  res
}

fn main() {

  let array = vec![4,30,2,3,6,99,8,11,23];

  let sorted_array = insertionSort(array);

  print!("Sorted: [");
  for n in 0..sorted_array.len()-1 {
    print!("{}, ", sorted_array[n]);
  }
  print!("{}", sorted_array[sorted_array.len()-1]);
  println!("]");

}
