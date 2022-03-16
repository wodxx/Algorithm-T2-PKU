// Node_path[];       //取节点总数即可
// int depth;

// bool dfs(v){
//   if(v为终点){
//     path[depth] = v;
//     return true;
//   } 

//   if(v为旧点){
//     return false;
//     将v标记为旧点；
//     path[depth] = v;
//     ++depth;
//   }

//   对和v相邻的每一个节点u{
//     if(dfs(u) = true) return true;
//     --depth;                           //该点无法到达终点，在path数组中删去
//     return false;
//   }
// }

// int main(){
//   将所有的点都标记为新点；
//   depth = 0;
//   if(dfs(起点)){
//     for(int i = 0; i <= depth; ++i){
//       cout<< path[i] <<endl;
//     }
//   }

//   return 0;
// }

