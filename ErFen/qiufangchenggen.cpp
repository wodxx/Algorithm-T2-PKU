#include <iostream>
#include <cmath>
using namespace std;
double EPS = 1e-6;                   //10的负6次方               

double f(double x){
  return x*x*x - 5*x*x + 10*x -80;   //方程为单调递增函数，在[0,100]内有且只有一个根
}

int main(){
  double root, x1 = 0, x2 = 100, y;
  root = x1 + (x2 - x1) / 2;
  int triedTimes = 1;                //尝试次数
  y = f(root);                       //由于要先计算一遍y的值，即root要先算出来一次，不写在while下面

  while(fabs(y) > EPS){             //要求根结果的绝对值小于等于1e-6
    if(y > 0){                      //二分改变根的边界
      x2 = root;
    } else {
      x1 = root;
    }
    root = x1 + (x2 - x1) / 2;
    y = f(root);
    triedTimes++;
  }

  cout<<root<<endl;
  cout<<triedTimes<<endl;
  
  return 0;
}