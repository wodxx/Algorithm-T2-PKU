#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000;

vector<int > a = {1, 2, 5, 6, 8, 4, 2, 1, 3, 6, 9, 8, 44, 556, 1156, 4458, 1, 25, 5};
int main(){
  int len = a.size();
  vector<int> b(len, 1);

  for(int i = 1; i < len; i++){                          //以i终点的子序列的最长长度
    for(int j = 0; j < i; j++){                          //以j从0到i开始检查并储存以i为终点的最长子序列的长度
      if(a[i] > a[j]){
        b[i] = max(b[j] + 1, b[i]);                      //b[]储存了以每个元素为终点的子序列的长度
      }
    }
  }
  cout<< * max_element(b.begin(), b.end()) <<endl;      //max_element 求区间中的最大值，返回最大元素的迭代器
  
  return 0;
}