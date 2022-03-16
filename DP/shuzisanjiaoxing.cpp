#include <iostream>                               
#define MAX 100
#include <algorithm>
#include <cmath>
using namespace std;

int D[MAX][MAX];                                   //定义第几行第几个数字的二位数组
int maxsum[MAX][MAX];                              //定义第几行第几个数字到三角形底部的最长和数组
int n;

int Maxsum(int i, int j){
  if(maxsum[i][j] != -1) return maxsum[i][j];      //和不为-1表示求出该数到底部的最大和

  if(i == n){
    return maxsum[i][j] = D[i][j];
  } else {
    int x = Maxsum(i + 1, j);                      //递归：求最值 + 分到最小
    int y = Maxsum(i + 1, j + 1);
    maxsum[i][j] = max(x, y) + D[i][j];
  }

  return maxsum[i][j];
}

int main(){
  cin >> n;
  int i, j;
  for(i = 1; i <= n; i++){
    for(j = 1; j <= i; j++){
      cin >> D[i][j];
      maxsum[i][j] == -1;                           //到底部的和为-1表示未求出来0
    }
  }
  cout<< Maxsum(1, 1) <<endl;
  return 0;
}