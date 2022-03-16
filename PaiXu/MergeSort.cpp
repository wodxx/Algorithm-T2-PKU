#include <iostream>
using namespace std;


void Merge(int left, int right, int mid, int arr[], int temp[]){         //分治排序后在合并
  int pleft = left; 
  int pright = mid + 1;
  int ptemp = 0;

  while(pleft <= mid && pright <= right){
    if(arr[pleft] <= arr[pright]){
      temp[ptemp++] = arr[pleft++];
    } else {
      temp[ptemp++] = arr[pright++];
    }
  }

  while(pleft <= mid){
    temp[ptemp++] = arr[pleft++];
  }

  while(pright <= right){
    temp[ptemp++] = arr[pright++];
  }

  int c = 0;
  for(int i = left; i <= right; ++i){                                     //临时数组赋值给原数组
    arr[i] = temp[c++];                                                   //这里注意更换临时数组的指针
  }

}

void MergeSort(int left, int right, int arr[], int temp[]){              //归并分治
  if(left < right){                                                      //不是只有一个元素时才排序
    int mid = left + (right - left) / 2;
    MergeSort(left, mid, arr, temp);
    MergeSort(mid + 1, right, arr, temp);
    Merge(left, right, mid, arr, temp);
  }
}

int main(){
  int arr[10] = {13, 27, 19, 2, 8, 12, 2, 8, 30, 89};
  int temp[10];
  int right = sizeof(arr) / sizeof(int) - 1;
  MergeSort(0, right, arr, temp);
  for(int i = 0; i <= right; i++){
    cout<< arr[i] << " ";
  }

  return 0;
}