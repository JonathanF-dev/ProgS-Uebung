#include <vector>
void insertion_sort(std::vector<int>& v){
    int item;
    int temp;
    int k;
    int kleinstes;
    for(int i = 0; i < v.size(); i++){
        item = v.at(i);
        k = i+1;
        while(k < v.size()){
            if(v.at(k) < item){
                item = v.at(k);
                kleinstes = k;
            }
            k++;
        }
        if(item < v.at(i)){
            temp = v.at(i);
            v.at(i) = item;
            v.at(kleinstes) = temp;
        }
    }
}
