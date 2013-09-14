#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int LIM = 5000000;

lli p(lli n, int m)
{
  if(m == 0)return 1;
  if(m == 1)return n;
  lli r = p(n, m/2);
  return m % 2 ? r * r * n : r * r;
}

int main(void)
{
  int tc;
  lli l[40 + 1];
  for(cin >> tc; tc--; ){
    int size = 0;
    while(cin >> l[size] && l[size]){
      ++size;
    }
    sort(l, l + size);
    reverse(l, l + size);
    lli sum = 0;    
    for(int i=0; i<size; ++i){
      lli tmp = p(l[i], i + 1);
      if(LIM < tmp || LIM < 2 * tmp || LIM < sum || sum < 0){
	sum = LIM + 1;
	break;
      }
      sum += 2 * tmp;
    }
    if(LIM < sum)cout << "Too expensive" << endl;
    else cout << sum << endl;
  }
  return 0;
}
