
pub fn insertion_sort(x : &mut [i32]){
    let len = x.len();
    for i in 1..len {
        let k : i32 =  x[i];
        let mut j : usize =  i;
        while j > 0 && x[j - 1] > k {
            x[j] = x [j-1];
            j-=1;
        }
        x[j] = k;
    }
}