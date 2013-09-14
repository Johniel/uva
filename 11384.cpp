#include <iostream>

using namespace std;

int main(void)
{
  int n;
  while(cin >> n){
    int sum = 0;
    int m = 1;
    int cnt = 0;
    while(sum < n){
      sum += m;
      m += m;
      ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}
