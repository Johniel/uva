#include <iostream>
#include <algorithm>

using namespace std;

const int H = 3;
const int W = H * 9;

char s[H][W];

int calc(int d[])
{
  int sum = 0;
  for(int i=0; i<9; ++i){
    sum += d[i] * (9 - i);
  }
  return sum % 11;
}

string D[] = {" _     _  _     _  _  _  _  _ ",
              "| |  | _| _||_||_ |_   ||_||_|",
              "|_|  ||_  _|  | _||_|  ||_| _|"};

bool change(int a, int b)
{
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      if(s[i][j + a * 3] != ' ' && D[i][j + b * 3] == ' ')return false;
    }
  }
  return true;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    fill( &s[0][0], &s[H-1][W], ' ' );
    for(int i=0; i<H; ++i){
      for(int j=0; j<W; ++j){
        s[i][j] = cin.get();
        if(s[i][j] == '\n'){
          s[i][j] = ' ';
          cin.unget();
          break;
        }
      }      
      cin.ignore();
    }

    /*
    cout << "#####################################" << endl;
    for(int i=0; i<H; ++i){
      for(int j=0; j<W; ++j){
        cout << s[i][j];
      }
      cout << endl;
    }
    cout << "#####################################" << endl;
    */

    int d[9];
    for(int idx = 0; idx < 9; ++idx){
      int num = -1;
      for(int n = 0; n < 10; ++n){
        bool flg = true;
        for(int i = 0; i < 3; ++i){
          for(int j = 0; j < 3; ++j){
            if( D[i][n * 3 + j] == s[i][idx * 3 + j] )continue;
            i = j = 1 << 24;
            flg = false;
          }
        }
        if(flg){
          num = n;
          break;
        }
      }
      d[idx] = num;
    }
    
    //for(int i=0; i<9; ++i)cout << d[i] << ' '; cout << endl;
    
    int miss = -1;
    for(int i=0; i<9; ++i){
      if(0 <= d[i])continue;
      miss = i;
      break;
    }
    
    const string F = "failure";
    const string M = "ambiguous";
    if( 1 < count(d, d + 9, -1) )cout << F << endl;
    else if(miss == -1){
      int cnt = 0, idx, r;
      for(int i=0; i<9; ++i){
        int tmp = d[i];
        for(int j=0; j<10; ++j){
          if( !change(i, j) )continue;
          d[i] = j;
          if( calc( d ) == 0 ){
            ++cnt;
            idx = i;
            r = j;
          }
        }
        d[i] = tmp;
      }
      if(cnt == 0)cout << F << endl;
      else if(cnt == 1){
        d[idx] = r;
        for(int i=0; i<9; ++i)cout << d[i]; cout << endl;
      }
      else cout << M << endl;
    }
    else{
      int cnt = 0, r;
      for(int i=0; i<10; ++i){
        if( !change(miss, i) )continue;
        d[miss] = i;
        if( calc(d) == 0 ){
          ++cnt;
          r = i;
        }
      }
      if(cnt == 0)cout << F << endl;
      else if(cnt == 1){
        d[miss] = r;
        for(int i=0; i<9; ++i)cout << d[i]; cout << endl;
      }
      else cout << M << endl;
    }
  }
  return 0;
}
