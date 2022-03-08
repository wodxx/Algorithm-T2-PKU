//在包含size个元素从大到小排序的int数组arr里查找比给定整数key小的，下标最大的元素。
#include <iostream>
using namespace std;

int LowBound(int arr[], int n, int key){
  int left = 0;
  int right = n - 1;
  int index = -1;

  while(left <= right){
    int mid = left + (right - left) / 2;
    if(key <= arr[mid]){
      right = mid - 1;                          //key值在左边       
    } else {
      index = mid;                              //key值在右边时，记录mid
      left = mid + 1;
    }
  }

  return index;
}

int main(){

  return 0;
}