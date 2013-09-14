#include <iostream>

using namespace std;

typedef long long int lli;

inline lli sum(lli n)
{
  return (n % 2)? (n+1)/2*n : n/2*(n+1);
}

int main(void)
{
  lli n;
  while(cin >> n){
    lli r = 0, l = 1000000000ll, c, tmp;
    while(r < l){
      c = (r + l) / 2;
      tmp = sum(c);
      if(tmp < n)r = c + 1;
      else l = c;
    }
    tmp = sum(r) - n + 1;
    ++r;
    if(r%2 == 0)cout << "TERM " << n << " IS " << tmp << "/" << r - tmp << endl;
    else cout << "TERM " << n << " IS " << r - tmp << "/" << tmp << endl;
  }
  return 0;
}
