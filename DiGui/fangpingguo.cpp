#include <iostream>
using namespace std;

int f(int m, int n){
  if(n == 0) return 0;                    //没有盘子的放法为0
  if(m == 0) return 1;                    //没有苹果的方法为1

  if(n > m) return f(m, m);               //盘子多，必有盘子为空，相当于把m个苹果放入的m个盘子的放法
  return f(m, n - 1) + f(m - n, n);       //(m >= n)苹果多，分为有空盘的情况和无空盘的情况，求二者和
}

int main(){                               //递归：问题细分 + 边界条件
  int m, n, t;
  cin >> t;

  while(t--){
    cin >> m >> n;
    cout<< f(m, n) << endl;
  }

  return 0;
}