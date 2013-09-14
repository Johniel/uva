#include <iostream>

using namespace std;

typedef long long int lli;

inline
lli labs(lli i)
{
  return i < 0 ? -i : i;
}

int main(void)
{
  const int N = 100000;
  lli wine[N];
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    for(int i=0; i<n; ++i){
      cin >> wine[i];
    } 
    lli sum = labs(wine[0]), trade = wine[0];
    for(int i=1; i<n; ++i){
      wine[i] += trade;
      sum += labs(wine[i]);
      trade = wine[i];
    }
    cout << sum << endl;
  }
  return 0;
}
