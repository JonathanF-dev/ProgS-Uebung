
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& v) {

  for (int i = 1; i < v.size(); ++i) {
    int k = v[i];
    int j = i-1;

    while (j >= 0 && v[j] > k) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = k;
  }
}

int main() {
  std::vector<int> a{4,30,2,3,6,99,8,11,23};

  insertionSort(a);

  std::cout << "Sorted: [";
  for (int i = 0; i < a.size()-1; ++i) {
    std::cout << a[i] << ", ";
  } 
  std::cout << a[a.size()-1] << "]" << std::endl;

  return 0;
}
