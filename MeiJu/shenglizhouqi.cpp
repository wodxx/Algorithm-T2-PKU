#include <iostream>
using namespace std;

//直接枚举法：
// int main(){
//   int p, e, i, d = 0;

//   cin>>p>>e>>i>>d;

//     for(int k = d + 1; k <= 21252; ++k){                         //从给定d后的每一天开始试
//       if((k - p)%23 == 0 && (k - e)%28 == 0 && (k - i)%33 == 0)
//       cout<<"Next peak may be "<<k - d<<"days !"<<endl;
//     }
     
//   return 0;
// }


//间隔枚举法：
int main(){
  int p, e, i, d; int caseNO = 0;

  while(cin >> p >> e >> i >> d && p != -1 && e != -1 && i != -1 && d != -1){  
    int k = 0;
    caseNO++;
    for(k = d + 1; (k - p)%23; k++);  //找到体力高峰
    for(; (k - e)%28; k += 23);       //找体力和情商双高峰的日子
    for(; (k - i)%33; k += 23 * 28);  //体力和情商出现日的公倍数日来找三高峰

    cout<<"Case"<<caseNO<<": "<<"The next triple peak occur in "<<k - d<<" days !"<<endl;
  }

  return 0;
}

// 试例：
// 203 301 203 40
// Case1: The next triple peak occur in 10789 days !

// 小结：
    //1.当写一个函数可以不断试例的时候可以写while循环
    //2.for循环后写冒号时的终止条件为第二条语句