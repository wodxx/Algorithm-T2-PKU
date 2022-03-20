#include <iostream>
using namespace std;

int is_prime(int k){                //判断一个数k是不是素数
  for(int i = 2; i < k; i++){
    if(k % i == 0) break;
  }
}

int main(){                          //求小于N的最大素数
  int N;
  cin >> N;
  int k;
  for(k = N - 1; k >= 2; k--){      //从N的前一个数开始找最大的素数 
    if(is_prime(k)){
      cout<< k <<endl;
      break;
    }
  }

  return 0;
}
