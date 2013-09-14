#include <iostream>
#include <algorithm>

using namespace std;

int sum;
void rec(int i, int j, int lim_i, int lim_j, int k)
{
  if(k == 0)return;
  int i0 = i - k;
  int j0 = j - k;
  int i1 = i + k;
  int j1 = j + k;
  if(i0 <= lim_i && lim_i <= i1 && j0 <= lim_j && lim_j <= j1)++sum;
  if(lim_i <= i && lim_j <= j)rec(i0, j0, lim_i, lim_j, k/2);
  if(lim_i >= i && lim_j <= j)rec(i1, j0, lim_i, lim_j, k/2);
  if(lim_i <= i && lim_j >= j)rec(i0, j1, lim_i, lim_j, k/2);
  if(lim_i >= i && lim_j >= j)rec(i1, j1, lim_i, lim_j, k/2);
  return ;
}

#include <cstdio>
int main(void)
{
  int i, j, k;
  while(cin >> k >> i >> j && (i | j | k)){
    sum = 0;
    rec(1024, 1024, j, i, k);
    printf("%3d\n", sum);
  }
  return 0;
}
