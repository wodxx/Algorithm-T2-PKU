#include <iostream>                       //棋盘上摆放N个皇后使之相互不能攻击的方法
#include <cmath>
using namespace std;
int N;
int queenpos[100];

void NQueen(int k){                      //在0～k行皇后已经摆好的情况下，摆第k行及其以后的皇后
  int i;
  if(k == N){                            //第N个皇后已经摆好
    for(i = 0; i < N; i++){
      cout<< 1 + queenpos[i]<<"  ";      //queenpos[i]表示第i行皇后的列数
    }
    cout<<endl;
    return;
  }

  for(i = 0; i < N; i++){                 //列数
    int j;
    for(j = 0; j < k; j++){
      if(queenpos[j] == i || abs(queenpos[j] - i) == abs(k - j)){
        break;                           //第j行皇后的列数queenpos[]是否等于i，或者是否在对角线上
      }
    }

    if(j == k){                          //当前选的位置i不冲突
      queenpos[k] = i;                   //第k行的皇后放在第i列
      NQueen(k + 1);
    }                                    
  }
}

int main(){
  cin>>N;
  NQueen(0);
  return 0;
}
