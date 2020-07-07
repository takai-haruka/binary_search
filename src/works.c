#include <stdio.h>

int n;
int k;
int A[100000];

/*
  j番目の人に仕事量が0以上x以下でできるだけ仕事を配分する
  このように配分したときすべての時間の仕事が配分できるとき
  一番仕事量が多い人の仕事量がxとなるように仕事配分ができる
*/
int p(unsigned int x){
  int i = 0;
  int j = 0; /* 仕事を割り当てた人数 */
  int y;  /* 割り当てられた仕事量 */
  while (j < k){  
    y = 0;
    while (y + A[i] <= x && i < n){
      y = y + A[i];
      i++;
    }
    j++;
  }
  return i == n;
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
