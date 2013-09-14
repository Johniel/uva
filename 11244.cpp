#include <iostream>
#include <vector>

#define C 101
#define R 101

using namespace std;

bool field[R][C];
int r, c;

void input(void)
{
  //cout << r << c << endl;
  //exit(1);
  fill(&field[0][0], &field[R-1][C], false);
  cin.ignore();
  for(int i=0; i<r; i++){
    string s;
    getline(cin, s);
    //cout << s << endl;
    //exit(1);
    for(int j=0; j<c; j++){
      if(s[j] == '*')
	field[i][j] = true;
    }
  }
  return ;
}

bool yoizon(int y, int x)
{
  //cout << y << ' '<< x << endl;
  const int ni[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
  const int nj[8] = {-1,  0,  1, -1, 1, -1, 0, 1}; 
  for(int i=0; i<8; i++){
    if( y+ni[i] < r && y+ni[i] >=0 && x+nj[i]<c && x+nj >= 0){
      if( field[y+ni[i]][x+nj[i]] == true ){
	return false;
      }
    }
  }
  return true;
}

int compute(void)
{
  int cnt = 0;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(field[i][j] == true){
	if( yoizon(i,j) == true){
	  cnt++;
	}
      }
    }
  }
  return cnt;
}

int main(void)
{
  while(true){
    cin >> r >> c;
    //cout << r << c << endl;
    //exit(1);
    if(r == 0 && c == 0)
      break;
    input();
    cout << compute() << endl;
  }
  return 0;
}
