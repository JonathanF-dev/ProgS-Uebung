
var x = [4,30,2,3,6,99,8,11,23];
console.log(Object.values(x));
y = insertion_sort(x);
console.log(Object.values(y));


function insertion_sort(x){
    for(i = 1; i < x.length; i++ ){
        k = x[i];
        j = i - 1;
        while(j >= 0 && x[j] > k){
            x[j+1] =  x[j];
            j--;
        }
        x[j+1] = k;
    }
    return x;
}