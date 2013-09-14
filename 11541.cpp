#include <iostream>
#include <sstream>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

int main(void)
{
  int tc;
  int cnt = 0;
  cin >> tc;
  cin.ignore();
  while(tc--){
    string in;
    cin >>  in;
    istringstream iss(in);
    char c;
    int num;
    cout << "Case " << ++cnt << ": ";
    while(iss >> c >> num)
      REP(i, num)cout << c;
    cout << endl;
  }
  return 0;
}
