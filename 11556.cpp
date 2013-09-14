#include <iostream>

using namespace std;

typedef long long int lli;

int main(void)
{
  for(lli n, b; cin >> n >> b;){
    lli m = 1;
    if(++b > 20){
      b -= 20;
      m = m << 20;
    }
    m = (m << b) - 1;
    cout << (n <= m? "yes" : "no") << endl;
  }
  return 0;
}
