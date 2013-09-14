//uva 164
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int DEL = 0, INS = 1, CNG = 2, COPY = 3;

int dp(string a, string b)
{
  const int n = a.size();
  const int m = b.size();
  int path[n+1][m+1];
  int t[n+1][m+1];
  fill(&t[0][0], &t[n][m+1], (1 << 22));
  for(int i=0; i<=n; ++i){
    t[i][0] = i;
    path[i][0] = DEL;
  }
  for(int i=0; i<=m; ++i){
    t[0][i] = i;
    path[0][i] = INS;
  }
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      int del = t[i-1][j] + 1;
      int ins = t[i][j-1] + 1;
      int cng = t[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
      int mn = min(cng, min(ins, del));
      t[i][j] = mn;
      // for path building
      if(mn == cng && a[i-1] == b[j-1])path[i][j] = COPY;
      else if(mn == del)path[i][j] = DEL;
      else if(mn == ins)path[i][j] = INS;
      else if(mn == cng && a[i-1] != b[j-1])path[i][j] = CNG;
    }
  }
  vector< pair<string, int> > v;
  int p = n, q = m;
  while(0 < p || 0 < q){
    if(path[p][q] == DEL){
      string tmp = "D"; tmp += a[p-1];
      v.push_back( make_pair(tmp, p) );
      --p;
    }
    else if(path[p][q] == INS){
      string tmp = "I"; tmp += b[q-1];
      v.push_back( make_pair(tmp, p) );
      --q;
    }
    else{
      if(path[p][q] == CNG){
        string tmp = "C"; tmp += b[q-1];
        v.push_back( make_pair(tmp, p) );
      }
      --p;
      --q;
    }
  }
  reverse(v.begin(), v.end());
  int del = 0, ins = 0;
  for(int i=0; i<v.size(); ++i){
    if(v[i].first[0] == 'D')++del;
    if(v[i].first[0] == 'I')++ins;
    int idx = v[i].second;
    if(v[i].first[0] == 'D')idx += ins - del + 1;
    else if(v[i].first[0] == 'I')idx += ins - del;
    else idx += ins - del;
    printf("%s%02d", v[i].first.c_str(), idx);
  }
  puts("E");
  return t[n-1][m-1];
}

int main(void)
{
  for(string s, t; cin >> s >> t && s != "#"; dp(s, t));
  return 0;
}
