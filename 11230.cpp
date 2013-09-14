#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int n, m, h, w;
  while(cin >> n >> m >> h >> w && (n | m | h | w)){
    char a[n][m];
    char b[n][m];
    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
        cin >> a[i][j];
        b[i][j] = '0';
      }
    }
    int cnt = 0;
    for(int i=0; i+h<=n; ++i){
      for(int j=0; j+w<=m; ++j){
        if(a[i][j] == b[i][j])continue;
        ++cnt;
        for(int k=0; k<h; ++k){
          for(int l=0; l<w; ++l){
            b[i+k][j+l] = b[i+k][j+l] == '1' ? '0' : '1';
          }
        }
      }
    }
    bool flg = true;
    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
        flg = flg && a[i][j] == b[i][j];
      }
    }
    cout << (flg? cnt : -1) << endl;
  }
  return 0;
}
