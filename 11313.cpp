#include <iostream>

using namespace std;

int main(void)
{
  const string msg = "cannot do this";
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    cin >> n >> m;
    if((n-1)%(m-1))cout << msg << endl;
    else cout << (n-1)/(m-1) << endl;
  }
  return 0;
}
