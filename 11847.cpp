#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  while(true){
    double n;
    cin >> n;
    if(n == 0)break;
    cout << (int)floor(log2(n)) << endl;
  }
  return 0;
}
