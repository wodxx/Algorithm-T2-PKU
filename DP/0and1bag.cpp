#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[5][9] = {{0}};
int w[5] = {0, 2, 3, 4, 5};
int v[5] = {0, 3, 4, 5, 6};
int bagv = 8;

int beibao(){
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= bagv; i++){
      if(w[i] > j){
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i] + v[i]]);
      }
    }
  }
  return dp[4][8];
}

int main(){
  cout<<dp[4][8]<<endl;
  return 0 ;
}