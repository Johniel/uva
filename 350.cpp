#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  int z, i, m, l;
  int tc = 0;
  while(cin >> z >> i >> m >> l && (z | i | m | l)){
    map<int, int> vis;
    int r = -1;
    int cnt = 0;
    vis[l] = cnt++;
    while(true){
      l = (z * l + i) % m;
      if(vis.find(l) != vis.end()){
        r = cnt - vis[l];
        break;
      }
      else vis[l] = cnt++; 
    }
    cout << "Case " << ++tc << ": " << r << endl;
  }
  return 0;
}
