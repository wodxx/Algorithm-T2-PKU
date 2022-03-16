#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &array, int left, int len){
  if(left >= len) return;
  int k = array[left];
  int s = left, e = len;

  while(left < len){                                                 //首先找到第一个元素k的位置
    while(left < len &&array[len] >= k) --len;
    swap(array[left], array[len]);
    while(left < len && array[left] < k) ++left;
    swap(array[left], array[len]);
  }

  QuickSort(array, s, left - 1);                                     //在元素k的两边分治，递归排序
  QuickSort(array, left + 1, e);                                     //这里注意left=len，即k的位置，传入参数指针时要排除k的位置
}

int main(){
  vector<int> array = {3, 3, 2, 5, 33, 22, 22, 22, 11, 223, 342};
  int len = array.size() - 1;
  cout<<"Befor QuickSort : " <<endl;
  for(int i : array) cout<< i << " ";
  cout<<endl;
  QuickSort(array, 0, len);
  cout<<"After QuickSort : " <<endl;
  for(int i : array) cout<< i <<" ";

  return 0;
}

