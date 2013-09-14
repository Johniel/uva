#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  int tc;
  int cnt = 0;
  const int N = 100 + 1;
  lli p[N][N];
  lli w[N][N][N];
  cin >> tc;
  while( tc-- ){
    int n, m, lim;
    cin >> n >> m >> lim;

    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
        cin >> p[i][j];
      }
    }

    fill( &w[0][0][0], &w[N-1][N-1][N], 0 );
    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
        w[i][j][j] = p[i][j];
        for(int k=j+1; k<m; ++k){
          w[i][j][k] = w[i][j][k-1] + p[i][k];
        }
      }
    }
    //#define TEST
    lli area = 0;
    lli cost = 1LL << 60;
    for(int j=0; j<m; ++j){
      for(int k=j; k<m; ++k){
        int begin = 0;
        int end = 0;
        lli sum = 0;
        lli a = 0, c = 1LL << 60;
#ifdef TEST
        cout << endl;
        cout << j << ' ' << k << endl;
#endif
        while(begin < n){
          while(end < n){
            sum += w[end++][j][k];
            if(lim < sum)break;
            lli tmp = (end - begin) * (k - j + 1);
            if(a < tmp)a = tmp, c = sum;
            if(a == tmp)c = min(c, sum);
#ifdef TEST
            cout << begin << ' ' << end << " : " << tmp << ' ' << sum << endl;
#endif
          } 
          if(end == n)break;
          while(begin < end){
            sum -= w[begin++][j][k];
            if(sum <= lim){
              lli tmp = (end - begin) * (k - j + 1);
              if(a < tmp)a = tmp, c = sum;
              if(a == tmp)c = min(c, sum);
#ifdef TEST
              cout << begin << ' ' << end << " : " << tmp << ' ' << sum << endl;
#endif
              break;
            }
          }
          if(end < begin)break;          
        }
        if(area < a)area = a, cost = c;
        if(area == a)cost = min(cost, c);
      }
    }
    cout << "Case #" << ++cnt << ": " << area << " " << cost << endl;
  }
  return 0;
}
