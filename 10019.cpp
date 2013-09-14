//hex to bin , dec to bin
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int cntOne(int in)
{
  int sum = 0;
  while(in){
    if(in%2)sum++;
    in /= 2;
  }
  return sum;
}


int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n, m;
    string in;
    cin >> in;
    istringstream iss(in);
    iss.setf(ios::hex);
    iss.unsetf(ios::dec);
    iss >> m;
    iss.setf(ios::dec);
    n = atoi(in.c_str());
    cout << cntOne(n) << ' ' << cntOne(m) << endl;
  }
  return 0;
}
