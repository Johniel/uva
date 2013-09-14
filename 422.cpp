#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100 + 1;

char g[N][N];

const pair< pair<int, int>, pair<int, int> > fail = make_pair( make_pair(-1, -1), 
                                                               make_pair(-1, -1) );

pair< pair<int, int>, pair<int, int> > 
solve(int n, string s)
{
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if( s[0] == g[i][j] ){
        int cnt, ni, nj;
        cnt = 0;
        for(int l=0; l<s.size(); ++l){
          ni = i + l;
          nj = j + 0;
          if(ni < 0 || nj < 0)break;
          if(n <= ni || n <= nj)break;
          if( s[l] != g[ni][nj] )break;
          ++cnt;                  
        }
        if( cnt == s.size() ){
          pair<int, int> a = make_pair(i+1, j+1);
          pair<int, int> b = make_pair(ni+1, nj+1);
          return make_pair(a, b);
        }
        cnt = 0;
        for(int l=0; l<s.size(); ++l){
          ni = i + 0;
          nj = j + l;
          if(ni < 0 || nj < 0)break;
          if(n <= ni || n <= nj)break;
          if( s[l] != g[ni][nj] )break;
          ++cnt;                  
        }
        if( cnt == s.size() ){
          pair<int, int> a = make_pair(i+1, j+1);
          pair<int, int> b = make_pair(ni+1, nj+1);
          return make_pair(a, b);
        }
      }
    }
  }
  return fail;
}

int main(void)
{
  int n;
  if( cin >> n && n ){    
    while( true ){
      for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
          cin >> g[i][j];
        }
      }
      while(true){
        string s;
        if( !(cin >> s) )return 0;        
        if( isalpha( s[0] ) ){
          pair< pair<int, int>, pair<int, int> > r = solve(n, s);
          if( r == fail ){
            reverse( s.begin(), s.end() );
            r = solve(n, s);
            swap( r.first, r.second );
          }
          if( r == fail )cout << "Not found" << endl;
          else{            
            cout << r.first.first << ',' << r.first.second << ' ' 
                 << r.second.first << ',' << r.second.second << endl;
          }
        }
        else{
          n = atoi( s.c_str() );
          break;
        }
      }
    }    
  }
  return 0;
}
