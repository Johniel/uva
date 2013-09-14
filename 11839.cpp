#include <iostream>

using namespace std;

int main(void)
{
  for(int n; cin >> n && n; ){
    for(int i=0; i<n; ++i){
      int sheet = 0;
      for(int j=0; j<5; ++j){
	int m;
	cin >> m;
	if(m <= 127)sheet += 1 << j;
      }
      if(sheet == (1 << 0))cout << 'A' << endl;
      else if(sheet == (1 << 1))cout << 'B' << endl;
      else if(sheet == (1 << 2))cout << 'C' << endl;
      else if(sheet == (1 << 3))cout << 'D' << endl;      
      else if(sheet == (1 << 4))cout << 'E' << endl;      
      else cout << '*' << endl;
    }
  }
  return 0;
}
