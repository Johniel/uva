#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

#include <map>
#include <cstdio>
int main(void)
{
  const int BASE =500, NUM = 501 * 2, MOD = 501;
  int tc, cnt = 0, n, m, num[NUM], tmp;
  for(scanf("%d\n", &tc); tc--; ){

    scanf("%d %d\n", &n, &m);

    fill(num, num + NUM, 0);
    vector<int> v[NUM];

    //set<int> s;
    map<int, int> s;
    int result = 0;

    for(int i=0; i<n; ++i){
      scanf("%d", &tmp);

      //if(s[tmp]){	
      if(s.count(tmp)){
	if(s[tmp] == 1 && (tmp*2)%m == 0)++result;
	continue;
      }
      //s.insert(tmp);
      s[tmp] = 1;
      ++num[tmp % m + BASE];
      v[tmp % m + BASE].push_back(tmp);
      //cout << tmp << ' ' << tmp % m << endl;
    }

    int test = 0;
    for(int i=0; i<NUM; ++i){
      if(num[i] == 0)continue;     

      //cout << num[i] << ' ' << i - BASE << endl;

      //if((i - BASE) * 2 % m == 0)result += num[i] * (num[i] - 1);

      for(int j=0; j<NUM; ++j){
	if(num[j] == 0)continue;
	tmp = (i - BASE) + (j - BASE);
	if(tmp % m)continue;
	FOR(a, v[i]){
	  FOR(b, v[j]){
	    if(a == b)continue;
	    //cout << test++ << ' ' << *a << ' ' << *b << ' ' << result << endl;
	    if(*a <= *b){
	      //cout << *a << ' ' << *b << " (a+b)%m= " << (*a+*b)%m << endl;
	      ++result;
	    }
	  }
	}
      }
    }
    printf("Case %d: %d\n", ++cnt, result);
    //cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ " << n << ' ' << m << endl;
  }
  return 0;
}
