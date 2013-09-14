#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long int u64;

int main(void)
{
  int tc;
  u64 n, k;
  for(cin >> tc; tc--; ){
    cin >> n >> k;
    set<u64> S;
    while(S.count(k) == 0){
      string s;
      //cout << "insert " << k << endl;
      S.insert(k);
      k *= k;
      //cout << "k * k = " << k << endl;
      while(k){
	s += (char)(k % 10 + '0');
	k /= 10;
      }
      reverse(s.begin(), s.end());
      s = s.substr(0, n);
      k = atoi(s.c_str());
    }
    cout << *max_element(S.begin(), S.end()) << endl;
  }
  return 0;
}
