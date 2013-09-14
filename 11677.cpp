#include <iostream>

using namespace std;

int main(void)
{
  while(true){    
    int h1, m1, h2, m2, total = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
      break;
    if(h2 < h1)
      h2 += 24;
    total += (h2 - h1) * 60;
    total += (m2 - m1);
    if(total < 0)total += 24 * 60;
    cout << total << endl;
  }
  return 0;
}
