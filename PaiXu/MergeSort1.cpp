#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &array, int left, int mid, int len, vector<int> &temp){
  int pleft = left;
  int pright = mid + 1;
  int ptemp = 0;

  while(pleft <= mid && pright <= len){                                         //分好的两半比大小放进临时数组
    if(array[pleft] < array[pright]){
      temp[ptemp++] = array[pleft++];
    } else {
      temp[ptemp++] = array[pright++];
    }
	}

  while(pleft <= mid){                                                          //处理没分进去的半组
    temp[ptemp++] = array[pleft++];
  }

  while(pright <= len){
    temp[ptemp++] = array[pright++];
  }

  int c = 0;
  for(int i = left; i <= len; ++i){                                             //函数里面的循环和条件语句要用传进来的实参
    array[i] = temp[c++];                                                       //这里的i不能从c或1开始，有该从实参left开始
  }
}

void MergeSort(vector<int> &array, int left, int len, vector<int> &temp){       //数组半分下去
  if(left < len){                                                               //数组里不只有一个数
    int mid = left + (len - left) / 2;
    MergeSort(array, left, mid, temp);
    MergeSort(array, mid + 1, len, temp);
    Merge(array, left, mid, len, temp);
  }
}

int main(){
  vector<int> array = {10, 9, 3, 4, 5, 33, 22, 44, 55, 46};
  int len = array.size() - 1;
  vector<int> temp(array.size());
  cout<<"Befor MergeSort : "<<endl;
  for(int i : array) cout<< i << " ";
  cout<<endl;
  MergeSort(array, 0, len, temp);
  cout<<"After MergeSort : "<<endl;
  for(int i : array) cout<< i << " ";

  return 0;
}

