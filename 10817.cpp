#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int APP = 100 + 1;
const int SER = 20;
const int SUB = 8;
const int INF = 1 << 22;

class T{
public:
  int cost;
  int sub[SUB], size;
  T() : size(0) {}
  T(int c) : cost(c), size(0) {}
  void add_sub(int s){
    sub[size++] = s;    
  }
};

int asign(int state, T t)
{
  REP(i, t.size){    
    int d = t.sub[i] * 2;
    if(state & (1 << d))++d;    
    state |= (1 << d);
  }
  return state;
}

int dp(T s[], int ser, T a[], int app, int sub)
{  
  const int BIT = 1 << 16;
  static int t[APP][BIT];
  fill(&t[0][0], &t[APP-1][BIT], INF);
  int sum = 0, ini = 0;  
  REP(i, ser){
    sum += s[i].cost;
    ini = asign(ini, s[i]);
  }
  t[0][ini] = sum;
  REP(i, app){
    REP(j, BIT){
      if(t[i][j] == INF)continue;
      int next = asign(j, a[i]);
      t[i + 1][next] = min(t[i + 1][next], t[i][j] + a[i].cost);
      t[i + 1][j] = min(t[i + 1][j], t[i][j]);
    }
  }
  int mn = INF;
  REP(i, app+1){
    mn = min(mn, t[i][(1 << (sub * 2)) - 1]);
  }
  return mn;
}

void input(T t[], int size)
{
  REP(i, size){
    string s;
    getline(cin, s);
    istringstream iss(s);
    iss >> t[i].cost;
    int tmp;
    while(iss >> tmp){
      t[i].add_sub(tmp - 1);
    }
  }
  return ;
}

int main(void)
{
  T s[SER], a[APP];
  for(int sub, ser, app; cin >> sub >> ser >> app && sub; ){
    cin.ignore();
    input(s, ser);
    input(a, app);    
    cout << dp(s, ser, a, app, sub) << endl;    
    fill(s, s + ser, T());
    fill(a, a + app, T());
  }
  return 0;
}
