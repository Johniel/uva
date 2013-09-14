#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  int n;
  string name[10 + 1];  
  bool flg = true;
  while(cin >> n){
    if(flg)flg = false;
    else cout << endl;
    for(int i=0; i<n; ++i){
      cin >> name[i];
    }
    map<string, int> sum;
    for(int i=0; i<n; ++i){
      string s, t, u;
      cin >> s;
      int a, m;
      cin >> a >> m;   
      if(m)sum[s] -= ((a/m)*m);
      for(int j=0; j<m; ++j){
        cin >> t;     
        sum[t] += a / m;
      }      
    }
    for(int i=0; i<n; ++i){
      cout << name[i] << ' ' << sum[name[i]] << endl;
    }
  }
  return 0;
}
