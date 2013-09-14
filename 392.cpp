#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int n[9];
  while(true){
    int cnt = 0;
    for(int i=0; i<9; ++i){
      if(!(cin >> n[i]))return 0;
      if(n[i])++cnt;
    }
    bool flg = true;
    int tmp = 0;
    for(int i=0; i<9; ++i){
      if(n[i]){
	++tmp;
	if(flg){
	  if(i == 8)
	    cout << n[i];	  
	  else{
	    if(abs(n[i]) != 1)
	      cout << n[i];
	    else if(n[i] == -1)
	      cout << '-';
	  }
	  flg = false;
	}
	else{
	  cout << ((n[i] < 0)? "- " : "+ "); 
	  if(abs(n[i]) != 1 || i == 8)
	    cout << abs(n[i]);
	}
	if(i <= 7){
	  cout << "x";
	  if(i != 7)
	    cout << "^" << 8-i;
	}
	if(tmp != cnt)cout << ' ';
	else cout << endl;
      }
    }
    if(cnt == 0)cout << 0 << endl;
  }
  return 0;
}
