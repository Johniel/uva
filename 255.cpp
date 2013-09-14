#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int no[8][8];
pair<int, int> rev[8 * 8];

const string msg[] = {"Illegal state",     //0
                      "Illegal move",      //1
                      "Move not allowed",  //2
                      "Continue",          //3
                      "Stop"};             //4
bool valid_num(int n)
{
  return 0 <= n && n <= 63;
}

const int dir = 4;
const int di[] = {0, 0, -1, 1};
const int dj[] = {-1, 1, 0, 0};

int solve(int a, int b, int c)
{
  if( a == b || !valid_num(a) || !valid_num(b) || !valid_num(c) ){
    return 0;
  }
  pair<int, int> s = rev[ a ];  
  pair<int, int> t = rev[ b ];  
  pair<int, int> u = rev[ c ];  
  
  /*
  cout << s.first << ' ' << s.second << endl;  
  cout << t.first << ' ' << t.second << endl;
  cout << u.first << ' ' << u.second << endl;
  */

  if( (t.first != u.first && t.second != u.second) || b == c || a == c ){
    return 1;  
  }
  bool flg = true;
  if( s.first == t.first && t.first == u.first ){
    if( (s.second < u.second && s.second < t.second) ||
        (s.second > u.second && s.second > t.second) );
    else flg = false;    
  }
  if( s.second == t.second && t.second == u.second ){
    if( (s.first < u.first && s.first < t.first) ||
        (s.first > u.first && s.first > t.first) );
    else flg = false;
  }
  if( !flg ){
    return 1;
  }
  
  for(int d=0; d<4; ++d){
    int ni = s.first + di[d];
    int nj = s.second + dj[d];
    if(ni < 0 || nj < 0)continue;
    if(8 <= ni || 8 <= nj)continue;
    if( no[ni][nj] == c )return 2;
  }  
  
  if( (a == 0  && c ==  9) || 
      (a == 7  && c == 14) || 
      (a == 56 && c == 49) || 
      (a == 63 && c == 54) )return 4;

  return 3;
}

int main(void)
{
  for(int i=0, cnt=0; i<8; ++i){
    for(int j=0; j<8; ++j){
      no[i][j] = cnt;
      rev[cnt] = make_pair(i, j);
      ++cnt;
    }
  }
  for(int a, b, c; cin >> a >> b >> c; cout << msg[ solve(a, b, c) ] << endl);
  return 0;
}
