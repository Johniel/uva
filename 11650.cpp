//uva11650
#include <iostream>

using namespace std;

class Clock{
public:
  static 
  int diffM(int h1, int m1, int h2, int m2){
    int total = 0;
    if(h2 < h1)h2 += 24;
    total += (h2 - h1) * 60 + m2 - m1;
    if(total < 0)total += 24 * 60;
    return total;
  }
  static // int p can be both + and - 
  pair<int, int> pass(int h, int m, int p){
    static const int H = 24 * 60;
    p = (0 <= p)? p % H : p % H + H;
    m += h * 60 + p;
    m %= H;
    return make_pair(m/60, m%60);
  }
};

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int h1, m1, h2, m2;
    char c;
    cin >> h1 >> c >> m1;
    pair<int, int> ans = Clock::pass(12, 0, Clock::diffM(h1, m1, 12, 0));
    h2 = ans.first;
    m2 = ans.second;
    if(13 <= h2)h2 -= 12;
    printf("%02d:%02d\n", h2, m2);
  }
  return 0;
}
