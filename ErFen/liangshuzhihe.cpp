#include <iostream>
#include <algorithm>
using namespace std;

int findtwonumber(int arr[], int n, int m){
  for(int i = 0; i < n - 1; i++){
    int temp = m - arr[i];                        //方法一：对数组中每一个值arr[i]，在数组中找m - arr[i]
    int left = i;
    int right = n;
 
    while(left <= right){                        //二分查找
      int mid = left + (right - left) / 2;
      if(temp == arr[mid]){
        cout<< arr[mid] << endl;
      } else if (temp > arr[mid]){
        left = mid + 1;
      } else {
        right == mid - 1;
      }
    }
  }

  return;
}

// int findtwonumber(int arr[], int n, int m){     //方法三：先对数组排序，赋左右指针i和j，判断arr[i] + arr[j]和m的大小
//   int i = 0;                                    //移动i和j指针，直至找到两个和为m的数
//   int j = n - 1;

//   while(i <= j){
//     if(arr[i] + arr[j] > m){
//       j--;
//     } else if(arr[i] + arr[j] < m){
//       i++;
//     } else {
//       cout<< arr[i] << " " << arr[j] << endl;
//     }
//   }

//   return;
// }

int main(){
  int n;
  int arr[100];
  sort(arr, arr + 100);                           //先对数组排序
  return 0;
}