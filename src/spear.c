#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x){ /* 単調減少 */
  unsigned int y = 0;
  int i;
  for(i = 0; i < n; i++){
    y = y + A[i] / x;
  }
  return y >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9 + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);
  return 0;
}
