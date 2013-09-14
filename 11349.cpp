#include <iostream>

using namespace std;

int main(void)
{
  int tc, cnt = 0, size;
  long long int m[100][100];
  char c;
  cin >> tc;
  while(tc--){
    cin >> c >> c >> size;
    for(int i=0; i<size; ++i){
      for(int j=0; j<size; ++j)
	cin >> m[i][j];
    }
    bool flg = true;
    for(int i=0; i<size && flg; ++i){
      for(int j=0; j<size && flg; ++j)
	flg = 0 <= m[i][j] && m[i][j] == m[size-i-1][size-j-1];
    }
    cout << "Test #" << ++cnt << ": " << (flg? "S" : "Non-s") << "ymmetric."<< endl;
  }  
  return 0;
}
