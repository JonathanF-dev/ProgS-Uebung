#include <iostream>
#include <string>
#include <math.h>

using namespace std;

float newton_sqrt(float num){
    float percison = 0.00000001;
    int maxiter = 1000;
    int iter = 1;
    float xn = 1.0;
    while(::fabs(xn * xn - num) > percison && iter < maxiter){
        xn = 0.5*(xn + (num/xn));
        iter++;
    }
    return xn;
}

int main(){ 
    float num = 1;
    std::cin >> num;
    std::cout << "berechne Wurzel von {} ..." , num;
    float xn = newton_sqrt(num);
    std::cout << "Die Wurzel von " + to_string(num) + " ist: " + to_string(xn) << endl;
    return 0;
}