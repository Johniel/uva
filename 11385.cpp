#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int lli;

int main(void)
{
  const int L = 1 << 31, N = 57;
  lli fib[100], m;
  fib[0] = fib[1] = 1;
  for(int i=2; i < N; ++i){
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  map<lli, int> M;
  for(int i=0; i<N; ++i){
    M[fib[i]] = i;
  }

  int tc, n;
  for(cin >> tc; tc--; ){
    cin >> n;
    vector<lli> v;
    for(int i=0; i<n; ++i){
      cin >> m;
      v.push_back(m);
    }
    cin.ignore();
    string s, t, r;
    getline(cin, s);
    int cnt = 0;
    t.resize(v.size(), ' ');

    r = s;    
    s = "";
    for(int i=0; i<r.size(); ++i)
      if(isalpha(r[i]) && isupper(r[i]))s += r[i];

    for(int i=0; i<v.size(); ++i){
      int p = M[v[i]];
      if(t.size() <= p)t.resize(p + 1, ' ');      
      t[p] = s[i];
    }
    for(int i=1; i<t.size(); ++i){
      cout << t[i];
    }
    cout << endl;
  }
  return 0;
}
