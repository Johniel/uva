#include <iostream>

using namespace std;

static const int M = 60000;

int sumF(int n, int p[], int cnt)
{
  int sum = 0;
  for(int i=1; i<n; ++i){
    if(n % i == 0){
      sum += i;
    }
  }
  //cout << n << ' ' << sum << endl;
  return sum;
}

int main(void)
{
  bool isp[M];
  int p[M], cnt = 0;
  fill(isp, isp + M, true);
  isp[0] = isp[1] = false;
  for(int i=2; i*i<M; ++i)
    for(int j=2; i * j < M; ++i)
      isp[i * j] = false;
  for(int i=0; i<M; ++i)
    if(isp[i])p[cnt++] = i;
  printf("PERFECTION OUTPUT\n");  
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    int f = sumF(n, p, cnt);
    printf("%5d  ", n);
    if(n == f)printf("PERFECT\n");
    else if(n < f)printf("ABUNDANT\n");
    else if(n > f)printf("DEFICIENT\n");
    else printf("\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
