#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

static const int N = 11;
static const int M = 300 * 100 + 1;

int coin[N] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long cnt[M];

int main(void)
{
  //for(int i=0; i<N; i++)coin[i] /= 5;
  fill(cnt, cnt + N, 0);
  cnt[0] = 1;
  for(int j=0; j<N; j++){
    for(int i=coin[j]; i<M; i++){
      cnt[i] += cnt[i - coin[j]];
    }
  }
  while(true){
    double in;
    cin >> in;
    if(in == 0)
      break;
    int n = (int)(in * 100 + 0.5);
    //cout << n << endl;
    printf("%6.2lf%17lld\n", in, cnt[n]); 
  }
  return 0;
}
