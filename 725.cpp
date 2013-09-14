#include <iostream>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

void geterator(set<string> S[])
{
  string s = "0123456789";
  sort(s.begin(), s.end());
  do{
    string m = s.substr(0, 5), n = s.substr(5, 5);
    int a, b;
    a = atoi(m.c_str());
    b = atoi(n.c_str());
    if(a % b == 0 && a/b < 79 && 1 < 79){
      //cout << m + " / " + n + " = " << a/b<< endl;
      S[a/b].insert(m + " / " + n + " = ");
    }
  }while(next_permutation(s.begin(), s.end()));
  return ;
}

int main(void)
{
  bool flg = true;
  set<string> S[80];
  geterator(S);
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    if(flg)flg = false;
    else cout << endl;
    if(S[n].size()){
      FOR(i, S[n])cout << *i << n << endl;
    }
    else cout << "There are no solutions for " << n << "." << endl;
  }
  return 0;
}
