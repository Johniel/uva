#include <iostream>
#include <algorithm>

using namespace std;

double dp(int k, int n)
{
  const int L = 1000 + 1;
  const int D = 10;
  static double t[L][D];  
  double sum = 0;
  fill(&t[0][0], &t[L-1][D], 0);
  ++k;
  for(int i=0; i<k; ++i){
    t[0][i] = 1;
  }
  for(int l=0; l<n; ++l){
    for(int d=0; d<k; ++d){
      if(t[l][d] != 0){
	for(int i=-1; i<=1; ++i){	  
	  int tmp = d + i;
	  if(0 <= tmp && tmp < k){
	    t[l+1][tmp] += t[l][d];
	  }
	}
      }
    }
  }
  for(int i=0; i<k; ++i){
    sum += t[n-1][i];
  }
  return sum; 
} 

#include <cstdio>
int main(void)
{
  for(int n, k; cin >> k >> n; ){
    double div = 1;
    for(int i=0; i<n; ++i){
      div *= (k+1);
    }
    printf("%.5lf\n", dp(k, n) / div * 100);
  }
  return 0;
}
