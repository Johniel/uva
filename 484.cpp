#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

class data{
public:
  int order;
  int cnt;
  long long n;
};

bool cmp(const data& a, const data& b)
{
  return a.order < b.order;
}

int main(void)
{
  map<long long, data> M;
  int cnt = 0;
  long long n;
  while(cin >> n){
    if(M.count(n))M[n].cnt++;
    else{
      data in;
      in.cnt = 1;
      in.order = cnt;
      in.n = n;
      M.insert( make_pair(n, in) );
    }
    cnt++;
  }
  data *re;
  re = new data[M.size()];
  map<long long, data> :: iterator itr;
  for(itr = M.begin(), cnt = 0; itr != M.end(); itr++, cnt++)
    re[cnt] = (*itr).second;
  sort(re, re + M.size(), cmp);
  REP(i, M.size()){
    cout << re[i].n << ' ' << re[i].cnt ;
    cout << endl;
  }
  return 0;
}
