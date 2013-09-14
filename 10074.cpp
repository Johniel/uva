//maximum sum 2d
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int N = 101;
  int t[N][N];
  int n, w, h;
  while(cin >> h >> w && (h | w)){
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cin >> t[i][j];
      }
    }
    for(int i=0; i<h; ++i){
      int sum = 0;
      for(int j=w-1; 0<=j; --j){
        if(t[i][j] == 0)++sum;
        else sum = 0;
        t[i][j] = sum;
      }
    }

    /*
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cout << t[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;
    */

    int mx = 0;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        if(t[i][j] == 0)continue;
        int tmp = t[i][j];
        mx = max(mx, tmp);
        for(int k=i+1, l=2; k<h; ++k, ++l){
          if(t[k][j] == 0)break;
          tmp = min(tmp, t[k][j]);
          mx = max(mx, tmp * l);
        }
      }
    }
    cout << mx << endl;
  }
  return 0;
}
