#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

enum{K, G};

int main(void)
{
  for(int k, g, n; ; ){
    cin >> g >> k >> n;
    if(k + g + n == 0)break;
    vector<int> v;
    REP(i, g)v.push_back(G);
    REP(i, k)v.push_back(K);
    //--n;
    int p = -1;
    REP(i, k+g-1){
      //FOR(j, v)cout << *j << ' ' ; cout << endl;
      
      p = (p + n) % v.size();
      int tmp = v[p];
      v.erase(v.begin() + p);

      //FOR(j, v)cout << *j << ' ' ; cout << endl;      

      p = (p + n) % v.size();
      v[p] = (tmp == v[p])? G : K;

    }
    cout << (v[0] == K? "Keka" : "Gared") << endl;
  }
  return 0;
}
