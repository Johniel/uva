#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const string T = "NO CONFLICT";
  const string F = "CONFLICT";
  const int N = 1000000 + 1;
  int n, m;
  static int cnt[N];
  while( cin >> n >> m && (n | m) ){
    fill(cnt, cnt + N, 0);
    while(n--){
      int begin, end;
      cin >> begin >> end;
      for(int i=begin; i<end; ++i){
        ++cnt[i];
      }
    }
    while(m--){
      int first, range, inter;
      cin >> first >> range >> inter;
      for(int i=0; i<N; i+=inter){
        if(N <= i + range)break;
        for(int j=first; j<range; ++j){
          ++cnt[i + j];
        }
      }
    }
    int mx = 0;
    for(int i=0; i<N; ++i){
      mx = max(mx, cnt[i]);
    }
    cout << (mx<2? T : F) << endl;
  }
  return 0;
}
