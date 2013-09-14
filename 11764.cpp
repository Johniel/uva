#include <iostream>

using namespace std;

int main(void)
{
  const int N = 50;
  int tc, cnt = 0;
  int wall[N];
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> wall[i];
    }
    int h, l;
    h = l = 0;
    for(int i=1; i<n; ++i){
      if(wall[i-1] < wall[i])++h;
      if(wall[i-1] > wall[i])++l;
    }
    cout << "Case " << ++cnt << ": " << h << ' ' << l << endl;
  }
  return 0;
}
