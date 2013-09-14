#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    map<string, int> conf;
    for(int i=0; i<n; ++i){
      string s;
      int t;
      cin >> s >> t;
      conf[s] = t;
    }
    int d;
    string s;
    cin >> d >> s;
    cout << "Case " << ++cnt << ": " << flush;
    if(conf.find(s) == conf.end())cout << "Do your own homework!" << endl;
    else if(conf[s] <= d)cout << "Yesss" << endl;
    else if(conf[s] <= d+5)cout << "Late" << endl;
    else cout << "Do your own homework!" << endl;
  }
  return 0;
}
