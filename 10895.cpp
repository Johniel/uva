#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  const int E = 1001;
  int h, w, size, z;
  pair< pair<int, int>, int> elem[E];  
  while( cin >> h >> w ){
    size = 0;
    for(int i=0; i<h; ++i){
      for(int j=0; j<w; ++j){
        int n;
        cin >> n;
        if( n ){
          elem[ size++ ] = make_pair( make_pair(j, i), n );
        }
      }
    }

    for(int i=0; i<size; ++i){
      //cout << elem[i].first.first << "," << elem[i].first.second << ":";
      cout << elem[i].second;
      cout << " - ";
    }
    cout << endl;

    sort( elem, elem + size );

    for(int i=0; i<size; ++i){
      //cout << elem[i].first.first << "," << elem[i].first.second << ":";
      cout << elem[i].second;
      cout << " - ";
    }
    cout << endl;

    cout << w << ' ' << h << endl;
    size = 0;
    for(int j=0; j<w; ++j){
      bool flg = true;
      for(int i=0; i<h; ++i){
        if( elem[size].first.first == i && elem[size].first.second == j){
          if(flg)flg = false;
          else cout << ' ';
          cout << elem[size].second ;
        }
      }
      cout << endl;
    }
    cin >> z;
  }
  return 0;
}
