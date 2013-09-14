#include <iostream>

using namespace std;

int main(void)
{
  int n, m;
  while(cin >> n >> m){
    cout << n + (n-1)/(m-1) << endl;
  }
  return 0;
}
