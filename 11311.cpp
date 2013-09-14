#include <iostream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int h, w;
    int a, b;
    cin >> h >> w >> a >> b;
    int u = a;
    int d = h - a - 1;
    int l = b;
    int r = w - b - 1;
    int nim = u ^ d ^ l ^ r;
    string G = "Gretel";
    string H = "Hansel";
    cout << (nim? G : H) << endl;
  }
  return 0;
}
