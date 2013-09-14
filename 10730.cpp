#include <iostream>

using namespace std;

int main(void)
{
  const int N = 10000;
  int pos[N], num[N], n;
  while(cin >> n){
    if(n == 0)break;
    char c;
    cin >> c;
    for(int i=0; i<n; ++i){
      int m; 
      cin >> m; 
      pos[m] = i;
    }    

    bool flg = false;
    for(int i=0; i<n; ++i){
      for(int j=1; i + j + j < n; ++j){	
	if(pos[i] < pos[i + j] && pos[i + j] < pos[i + j + j]){
	  flg = true;
	  break;
	}
      }
      if(flg)break;
      for(int j=1; 0 <= i - j - j; ++j){
	if(pos[i] < pos[i - j] && pos[i - j] < pos[i - j - j]){
	  flg = true;
	  break;
	}
      }
      if(flg)break;
    }
    cout << (!flg? "yes" : "no") << endl;
  }
  return 0;
}
