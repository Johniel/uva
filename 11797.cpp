#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int name2id(string s)
{
  if(s == "Ja")return 0;
  if(s == "Sam")return 1;
  if(s == "Sha")return 2;
  if(s == "Sid")return 3;
  if(s == "Tan")return 4;
  return -1;
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int m, n, sum = 0, l, seat;
    string s, t;
    queue<int> q[5];
    int result[5];
    cin >> m >> n >> s;

    seat = name2id(s);
    REP(i, 5){
      result[i] = 0;
      cin >> l;
      REP(j, l){
	cin >> s;
	q[i].push(name2id(s));
      }
    }
    
    while(sum <= n){
      if(sum + m <= n){
	result[seat] += m;
	sum += m + 2;
      }
      else{
	result[seat] += n - sum;
	sum = 1 << 30;
      }
      int tmp = q[seat].front();
      q[seat].pop();
      q[seat].push(tmp);
      seat = tmp;
    }

    cout << "Case " << ++cnt << ":" << endl;
    cout << "Ja" << ' ' << result[name2id("Ja")] << endl;
    cout << "Sam" << ' ' << result[name2id("Sam")] << endl;
    cout << "Sha" << ' ' << result[name2id("Sha")] << endl;
    cout << "Sid" << ' ' << result[name2id("Sid")] << endl;
    cout << "Tan" << ' ' << result[name2id("Tan")] << endl;
  }
  return 0;
}
