#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;  

const int H = 500 + 1;

vector<int> build(int h)
{
  vector<int> v;
  int sum = 0;
  for(int i=1; sum<h; ++i){
    sum += i;
    v.push_back(i);
  }

  if(sum != h){
    int tmp = h - sum + v.back();
    v.pop_back();
    v.back() += tmp;
  }

  reverse(ALL(v));

  return v;
}

int main(void)
{
  int tc = 0;
  char t[H][H];
  for(int h; cin >> h;) {
    vector<int> v = build(h);
    fill(&t[0][0], &t[H-1][H], '.');
    int sum = 0, j = 0, k;
    for(int i=0; i<v.size(); ++i){
      for(k = 0; k < v[i]; ++k){
	t[sum + k][j] = '#';
      }
      t[sum + k - 1][++j] = '*';
      t[sum + k - 1][++j] = '*';
      sum += v[i];
    }

    reverse(ALL(v));
    int tmp = v.back();
    v.pop_back();
    v.back() += tmp;

    --sum;
    for(int i=0; i<v.size(); ++i){
      t[sum][++j] = '*';
      t[sum][++j] = '*';
      for(k = 0; k < v[i]; ++k){
	t[sum - k][j + 1] = '#';
	t[sum - k][j + 2] = '@';
      }
      sum -= v[i];
    }
    cout << "Tower #" << ++tc << endl;
    for(int i=h-1; i>=0; --i){
      bool flg = true;
      for(int j=0; j<H; ++j){
	if(t[i][j] == '@')break;
	if(t[i][j] != '.')flg = false;
	if(flg)cout << ' ';
	else cout << t[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
