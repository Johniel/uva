#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

inline
int conv(string s)
{
  char c = s[0];
  if(isdigit(c))return c - '0';
  return 10;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    vector<string> p, h;
    string s;
    for(int i=25; i--; ){
      cin >> s;
      p.push_back(s);
    }
    for(int i=52-25; i--; ){
      cin >> s;
      h.push_back(s);
    }
    reverse(h.begin(), h.end());
    reverse(p.begin(), p.end());
    int y = 0;
    for(int i=3; i--; ){
      int x = conv(p[0]);
      y += x;
      p.erase(p.begin(), p.begin() + (10 - x) + 1);
    }
    for(int i=0; i<p.size(); ++i)h.push_back(p[i]);
    reverse(h.begin(), h.end());    
    cout << "Case " << ++cnt << ": " << h[y-1] << endl;    
  }
  return 0;
}
