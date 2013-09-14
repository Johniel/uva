#include <iostream>

using namespace std;

int main(void)
{
  long long int n;
  while(true){
    cin >> n;
    if(n < 0)break;
    if(n == 1ll)cout << "0%" << endl;
    else cout << n * 25 << "%" << endl;
  }
}
