#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BigM(vector<int> &array, int l, int r, int m){          //快排
  int s = l,  e = r;                                         //先存储两个边界
  int p = array[l];
  while(l < r){
    while(p <= array[r]) --r;
    swap(array[l], array[r]);
    while(l < r && array[l] < p) ++l;
    swap(array[l], array[r]);
  }

  int c = e - l + 1;
  if(c == m) return;
  else if(c < m) BigM(array, s, l - 1, m - c);
  else BigM(array, l + 1, e, m);
}

void BigM1(vector<int>&a, int l, int r, int m){              //优先级队列 堆排序                                                              
	priority_queue <int, vector<int>, greater<int>>res;
	for (int i = l; i <= r; ++i){
		if (res.size() >= m){
			int min = res.top();
			if (a[i] > min){ 
				res.pop();
				res.push(a[i]);
			}
		}
		else res.push(a[i]);
	}
	while (!res.empty()){
		cout << res.top() << " ";
		res.pop();
	}

}

int main(){
  vector<int> array = {34, 3, 32, 55, 22, 33, 2222, 22233, 5532};
  int r = array.size() - 1;
  int m = 5;
  for(int i : array) cout<< i <<" ";
  cout<<endl;
  BigM(array, 0, r, m);
  for(int i : array) cout<< i <<" ";
  cout<<endl;
  for(int i = 0; i < m; ++i){
    cout<< array[r - i] <<" ";
  }
  cout<<endl;
  BigM1(array, 0, r, m);

  return 0;
}