#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key){
  int left = 0;
  int right = n - 1;
  while(left <= right){
    int mid = left + (right - left) / 2;
    if(arr[mid] == key){
      return mid;
    } else if(arr[mid] > key){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int main(){

  return 0;
}