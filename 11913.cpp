#include <iostream>
#include <algorithm>

using namespace std;

struct S{
  int b, e, f;
  S(){}
  S(int _b, int _e, int _f) : b(_b), e(_e), f(_f) {}
};

bool operator < (const S &a, const S &b)
{
  return a.b < b.b;
}

const int N = 100 + 2;
S s[N];

int dp(int size)
{
  int t[N][N][N];
  int mx = -1;  
  fill(&t[0][0][0], &t[N-1][N-1][N], -1);
  ++size;
  sort(s, s + size);
  t[1][0][0] = 0;
  for(int i=1; i<size; ++i){
    for(int a=0; a<i; ++a){
      for(int b=0; b<i; ++b){
        if(t[i][a][b] == -1)continue;
        t[i+1][a][b] = max(t[i+1][a][b], t[i][a][b]);
        if(s[a].e <= s[i].b){
          t[i+1][i][b] = max(t[i+1][i][b], t[i][a][b] + s[i].f);
          mx = max(mx, t[i+1][i][b]);
        }
        if(s[b].e <= s[i].b){
          t[i+1][a][i] = max(t[i+1][a][i], t[i][a][b] + s[i].f);
          mx = max(mx, t[i+1][a][i]);
        }
      }
    }
  }
  return mx;
}

int main(void)
{
  int tc = 0;
  while(true){
    int a, b, n;
    char c;
    cin >> n;
    if(n == 0)break;
    s[0].b = s[0].e = -1;
    s[0].f = 0;
    for(int i=1; i<=n; ++i){
      cin >> a >> c >> b;
      s[i].b = a * 60 + b - 6 * 60;
      if(s[i].b < 0)s[i].b += 24 * 60;
      cin >> c;      
      cin >> a >> c >> b;
      s[i].e = a * 60 + b - 6 * 60;
      if(s[i].e < 0)s[i].e += 24 * 60;
      cin >> s[i].f;
      string t;
      getline(cin, t);
    }
    cout << "Case " << ++tc << ": " << dp(n) << endl;
  }
  return 0;
}
