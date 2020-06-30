#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x){
  unsigned int y = 0;
  int i;
  for(i = 0; i < n; i++){
    y = y + (A[i] + x - 1) / x;
  }
  return y <= k;
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
