#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{  
  const int N = 'Z' + 1;
  int tc, cnt = 0; 
  int frq[N];
  cin >> tc;
  while(tc--){
    int h, w, f, s, sum = 0;
    cin >> h >> w >> f >> s;
    fill(frq, frq + N, 0);
    for(int i=0; i< h * w; ++i){
      char c; 
      cin >> c;
      sum = max(sum, ++frq[c]);
    }
    int tmp = 0;
    for(int i=0; i<N; ++i){
      if(sum == frq[i])tmp += frq[i];
    }
    cout << "Case " << ++cnt << ": " 
	 << f * tmp + (h * w - tmp) * s << endl;
  }
  return 0;
}
