
fn newton_sqrt(x : f32) -> f32 {
    let percision = 0.0000001;
    let mut xn = 1.0;
    while (xn * xn - x).abs() > percision {
        xn = 0.5*(xn + x/xn);
    }
    return xn;
}
fn main(){
    let mut line = String::new();
    println!("Bitte gib ein Zahl ein ");
    std::io::stdin().read_line(&mut line).unwrap();
    println!("{}" ,line);
    let num = line.trim().parse::<f32>().expect("Keine Zahl");
    println!("Die Wurzel aus {} ist: {}", num , newton_sqrt(num));
}