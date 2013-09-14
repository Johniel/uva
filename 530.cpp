#include<iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  lli n, k;
  while(cin >> n >> k && (n | k)){
    lli r = 1;
    if(n / 2 < k)k = n - k;
    for(lli i=0; i<k; ++i){
      r *= (n-i);
      r /= (i + 1);
    }
    cout << r << endl;
  }
  return 0;
}
