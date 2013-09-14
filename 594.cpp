#include <iostream>

using namespace std;

//int conv(unsigned int n)
int conv(int n)
{
  unsigned int b = 0;
  for(int i=0; i<4; ++i){
    if(i){
      b <<= 8;
      n >>= 8;
    }
    b = b | ( ((1 << 8) - 1) & n);
  }
  return b;
}

int main(void)
{
  for(int n; cin >> n; ){
    cout << n << " converts to " << conv(n) << endl;
  }  
  return 0;
}
