#include "sort.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> v = {4,30,2,3,6,99,8,11,23};
    insertion_sort(v);
    std::for_each(v.begin(), v.end(), [](const int n){std::cout << n << ' ';});
    return 0;
}