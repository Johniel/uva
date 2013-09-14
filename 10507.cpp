#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
  int node, edge;
  while(cin >> node >> edge){
    string s, t;
    vector<int> e[node];
    map<char, int> name;
    set<int> vis;
    int no = 0, bit = 0, y = 0, ans = (1 << node) - 1;
    int cnt[node];
    cin >> s;
    //cout << "node,edge : " << node << ',' << edge << endl;
    for(int i=0; i<edge; ++i){
      cin >> t;
      //cout << i << ' ' << edge << "   " << flush; cout << "edge : " << t << endl;
      if(name.find(t[0]) == name.end())name[t[0]] = no++;
      if(name.find(t[1]) == name.end())name[t[1]] = no++;
      int a = name[ t[0] ];
      int b = name[ t[1] ];
      e[a].push_back(b);
      e[b].push_back(a);
    }
    for(int i=0; i<s.size(); ++i){
      if(name.find(s[i]) == name.end())name[s[i]] = no++;
      bit |= 1 << name[ s[i] ];
    }
    /*
    cout << endl;
    cout << "s : " << s << endl;
    cout << "bit : " << bit << endl;
    cout << "ans : " << ans << endl;
    */
    vis.insert(bit);
    while( bit != ans ){
      fill(cnt, cnt + node, 0);
      for(int i=0; i<node; ++i){
        if(bit & (1 << i)){
          ++cnt[i];
          for(int j=0; j<e[i].size(); ++j){
            ++cnt[ e[i][j] ];
          }
        }
      }
      int tmp = bit;
      for(int i=0; i<node; ++i){
        if(3 <= cnt[i])tmp |= 1 << i;
      }
      bit = tmp;
      ++y;
      if(vis.count(bit))break;
      if(bit == ans)break;
      vis.insert(bit);
    }
    if(bit == ans)cout << "WAKE UP IN, " << y << ", YEARS" << endl;
    else cout << "THIS BRAIN NEVER WAKES UP" << endl;
  }
  return 0;
}
