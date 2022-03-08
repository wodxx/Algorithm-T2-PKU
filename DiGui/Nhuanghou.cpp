#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenpos[100];
void NQueen(int k);

void NQueen(int k){
  int i;
  if(k == N){
    for(i = 0; i < N; i++){
      cout<< 1 + queenpos[i]<<"  ";
    }
    cout<<endl;
    return;
  }

  for(i = 0; i < N; i++){
    int j;
    for(j = 0; j < k; j++){
      if(queenpos[j] == i || abs(queenpos[j] - i) == abs(k - j)){
        break;
      }
    }

    if(j == k){
      queenpos[j] = i;
      NQueen(k + 1);
    }
  }
}

int main(){
  cin>>N;
  NQueen(0);
  return 0;
}
