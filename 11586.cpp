#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string s;
    //cin >> s;
    getline(cin, s);
    istringstream iss(s);
    string p;
    int m = 0, f = 0, cnt = 0;
    while(iss >> p){
      cnt++;
      if(p[0] == 'M')m++;
      else f++;
      if(p[1] == 'M')m++;
      else f++;
    }
    if(cnt == 1 || f != m)cout << "NO LOOP" << endl;
    else cout << "LOOP" << endl;
  }
  return 0;
}
