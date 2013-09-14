#include <iostream>

using namespace std;

int rec(int e, const int bw)
{  
  int f = e / 3;
  if(f == 0){
    return e==2 ? 1 : 0;
  }
  return f + rec(f + e % 3, bw);
}

int main(void)
{
  int n;
  while(cin >> n && n){
    cout << rec(n, 0) << endl;
  }  
  return 0;
}
