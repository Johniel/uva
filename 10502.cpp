#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int inf = 1 << 23;
  int a[100][100], b[100][100];
  int h, w;
  while( cin >> h >> w ){
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        char c;
        cin >> c;
        a[i][j] = b[i][j] = c - '0';
      }
    }
    int sum = 0;
    for(int i=0; i<h; ++i){
      int cnt = 0;
      for(int j=0; j<w; ++j){
        if( a[i][j] )++cnt;
        else cnt = 0;
        a[i][j] = cnt;
      }
    }
    for(int j=0; j<w; ++j){
      int cnt = 0;
      for(int i=0; i<h; ++i){
        if( b[i][j] )++cnt;
        else cnt = 0;
        b[i][j] = cnt;
      }
    }

    //cout << endl;
    /*
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cout << a[i][j] << ' ';
      }
      cout << endl;
    }
    */
    /*
    cout << endl;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        cout << b[i][j] << ' ';
      }
      cout << endl;
    }
    */
    for(int j=0; j<w; ++j){
      for(int i=0; i<h; ++i){
        int cnt = 0, mn = inf;
        for(int k=i; k<h; ++k){
          mn = min(mn, a[k][j]);
          sum += mn;
        }
      }
    }
    cout << sum << endl;
    for(int i=0; i<h; ++i){

    }
  }
  return 0;
}
