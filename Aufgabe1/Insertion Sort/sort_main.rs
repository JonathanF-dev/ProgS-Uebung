
fn main(){
    let mut x = [4,30,2,3,6,99,8,11,23];
    for i in 0..x.len() {
        print!("{}, ", x[i]);
    }
    println!();
    sort::insertion_sort(&mut x);
    for i in 0..x.len() {
        print!("{}, ",x[i]);
    }   
}