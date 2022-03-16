#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
  string s1 = "abcdfgtd";
  string s2 = "abcfdduti";
  int len1 = s1.size();
  int len2 = s2.size();

  vector<int> a(len1 + 1, 0);
  vector<vector<int>> b(len2 + 1, a);
  cout<< s1[len1 - 1] <<endl;                       //已知条件：b[i][0] = b[0][j] = 0 ,即第0行和第0列均为0

  for(int i = 1; i <= len2; i++){
    for(int j = 1; j < len1; j++){
      if(s2[i - 1] == s1[j - 1]){
        b[i][j] = b[i - 1][j - 1] + 1;             //两种情况：1）两字符串前i个和前j个相等时，其公共子序列长度等于求出前一个再加一
      } else {
        b[i][j] = max(b[i - 1][j], b[i][j - 1]);   //2) 不等时在其左边和右边两个中取最大
      }
    }
  }

  cout<< b[len2 - 1][len1 - 1] <<endl;             //把所有公共子序列的可能存储在一个二维数组里，最后输出最后一个
  return 0;
}