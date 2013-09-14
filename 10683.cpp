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
  string input;
  const int P = 
  while(cin >> input){
    string h, m, s;
    h = input[0] + input[1];
    m = input[2] + input[3];
    s = input[4] + input[5];
    int a = atoi(h.c_str());
    int b = atoi(m.c_str());
    int c = atoi(s.c_str());
    c += 
  }
  return 0;
}
