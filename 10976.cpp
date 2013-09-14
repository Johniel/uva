#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef long long int lli;

int main(void)
{
  for(lli a; cin >> a; ){
    set< pair<lli, lli> > S;
    const lli N = 1002000;
    for(lli b=a+1, c; b<N; ++b){
      if((a * b) % (b - a) == 0){
	if(c = (a * b) / (b - a))
	  S.insert(make_pair(min(b, c), max(b, c)));
      }
    }
    cout << S.size() << endl;
    set< pair<lli, lli> >::iterator itr;
    for(itr = S.begin(); itr != S.end(); ++itr){
      cout << "1/" << a << " = 1/" << itr->second << " + 1/" << itr->first << endl;
    }
  }
  return 0;
}
