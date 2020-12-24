#include <iostream>
#include <vector>
#include <string>

using namespace std;

int merge(vector<int> &arr, int start1, int len1, int start2, int len2){
    
    std::vector<int> tmp_arr1(len1);
    std::vector<int> tmp_arr2(len2);
     
    for (int i = 0; i < len1; ++i) tmp_arr1[i] = arr[i + start1];
    for (int i = 0; i < len2; ++i) tmp_arr2[i] = arr[i + start2];
    
    int arr_start = start1;
    int i = 0;
    int j = 0;
    
    for (; (i < tmp_arr1.size()) && (j < tmp_arr2.size()) && (arr_start < (len1 + len2 + arr_start)); ++arr_start) {
        if (tmp_arr1[i] < tmp_arr2[j]) {
            arr[arr_start] = tmp_arr1[i];
            i++;
        } else {
            arr[arr_start] = tmp_arr2[j];
            j++;
        }
    }
    
    for (;i < tmp_arr1.size(); ++i, ++arr_start) arr[arr_start] = tmp_arr1[i];
    for (;j < tmp_arr2.size(); ++j, ++arr_start) arr[arr_start] = tmp_arr2[j];
}
int Merge_sort(vector<int> &arr, int start, int size ) {
   
    if (size < 2)
        return 0;
        
    int index = size/2;
   
    Merge_sort(arr, start, index);
    Merge_sort(arr, start + index, (size - index));
    merge(arr, start, index, start + index, (size - index));
  
    return 0;
}

int main(void){
    string input;
    vector<int> arr;
    
    while (cin >> input) {
      if (input == "#") break;
        arr.push_back(std::stoi(input));
    }
    std::cout << "Input:" << std::endl;    
    for (int i = 0; i < arr.size(); ++i) std::cout << arr[i] << " "; 
    std::cout << std::endl;
    
    auto ret = Merge_sort(arr,  0, arr.size());

    std::cout << "Output:" << std::endl;
    for (int i = 0; i < arr.size(); ++i) std::cout << arr[i] << " "; 
    std::cout << std::endl;
    
    return 0;
}