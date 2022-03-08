#include <iostream>
using namespace std;

void Hanoi(int n, char src, char mid, char dest){

  if(n == 1) {
    cout<< src << "-->" << dest <<endl;        //只有一个盘子
    return;
  }

  Hanoi(n - 1, src, dest, mid);               //多个盘子先将n-1个盘子移动到mid
  cout<< src << "-->" << dest <<endl;         //再将剩下的一个盘子移动到dest
  Hanoi(n - 1, mid, src, dest);               //最后将mid中的盘子移动到dest
  return;
}

int main(){
  int n;
  cin>>n;
  Hanoi(n, 'A', 'B', 'C');
  return 0;
}