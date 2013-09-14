#include <iostream>

using namespace std;

bool not_div(int m, int num[], int d, int cnt[])
{
  int c = 0;
  for(int i=0; i<d; ++i){
    int t = 1;
    for(int j=0; j<cnt[i]; ++j, t *= 10);
    c = (num[i] + c * t) % m;
  }
  return c;
}

int main(void)
{  
  const int N = 10000, M = 5;
  string s;
  int tc, n, num[N], cnt[N], m, tmp;
  for(cin >> tc; tc--; ){
    cin >> s;
    int d = 0;
    for(int i=0; i<s.size(); ++d){
      tmp = cnt[d] = 0;
      for(int j=0; j < M && i < s.size(); ++j, ++i){
	if(j)tmp *= 10;
	tmp += s[i] - '0';
	++cnt[d];
      }
      num[d] = tmp;
    }
    bool flg = true;    
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> m;
      flg = flg && !not_div(m, num, d, cnt);
    }
    cout << s << " - " << (flg? "Wonderful." : "Simple.") << endl;
  }
  return 0;
}
