#include <iostream>
#include <math.h>
#include <map>

using namespace std;

const int N = 1000000;

int M[N];

int x(int i)
{
  if(i <= 0)return 1;
  if(M[i])return M[i];
  double s = sin(i);
  return M[i] = (x(i - sqrt(i)) + x(log(i)) + x(i * s * s)) % N;
}

int main(void)
{
  fill(M, M + N, 0);
  while(true){
    int n;
    cin >> n;
    if(n == -1)break;
    cout << x(n) << endl;
  }
  return 0;
}
