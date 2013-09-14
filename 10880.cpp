#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  const int N = 2000000000;
  int p[5000], size = 0;

  p[size++] = 2;
  for(int i=3; i*i<N; i+=2){
    bool flg = true;
    for(int j=0; j<size; ++j){
      if(i % p[j] == 0){
	flg = false;
	break;
      }
    }
    if(flg)p[size++] = i;
  }

  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int c, r;
    cin >> c >> r;
    cout << "Case #" << ++cnt << ":";
    if(c == r){
      cout << " 0" << endl;
      continue;
    }
    int n = c - r;
    set<int> S, T, R;
    for(int i=0; i<size; ++i){
      if(n % p[i] == 0){
	S.insert(p[i]);
	n /= p[i];	
      }
    }

    if(r < n)S.insert(n);
    if(r == 0)S.insert(1);
    R = T = S;    

    for(int tmp = c - r;;){
      FOR(i, S){
	FOR(j, S){
	  int num = *i * *j;
	  if(tmp % num == 0){
	    R.insert(num);
	    R.insert(tmp/num);
	  }
	}
      }
      if(R.size() == S.size())break;      
      S = R;
    }    

    FOR(i, R){
      if(r < *i)cout << " " << *i;
    }
    cout << endl;
  }
  return 0;
}
