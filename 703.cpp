#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100 + 1;
int g[N][N];

struct S{
  int a, b, c;
  S(){}
  S(int _a, int _b, int _c){
    a = _a;
    b = _b;
    c = _c;
  }
};

int main(void)
{
  int n;  
  while( cin >> n ){
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        cin >> g[i][j];
      }
    }
    vector<S> v;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
        for(int k=0; k<n; ++k){
          if(i == j)continue;
          if(i == k)continue;
          if(j == k)continue;
          if( ((i > j && j > k) || (i < j && j < k)) && 
              g[i][j] && g[j][k] && g[k][i]){
            v.push_back( S(i, j, k) );
          }
          else if(i < j && j < k && 
                  g[i][j] == 0 && g[j][i] == 0 &&
                  g[i][k] == 0 && g[k][i] == 0 &&
                  g[k][j] == 0 && g[j][k] == 0 ){
            v.push_back( S(i, j, k) );
          }
        }
      }
    }
    cout << v.size() << endl;
    for(int i=0; i<v.size(); ++i){
      cout << v[i].a+1 << ' ' << v[i].b+1 << ' ' << v[i].c+1 << endl;
    }
  }
  return 0;
}
