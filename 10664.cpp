#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int num[20 + 1], n, sum;
bool state[20 + 1];

bool BT(int d)
{
  if(d == n){
    int tmp = 0;
    for(int i=0; i<n; ++i){
      if(state[i])tmp += num[i];
    }
    return sum == tmp * 2;
  }
  else{
    state[d] = true;
    if(BT(d + 1))return true;
    state[d] = false;
    if(BT(d + 1))return true;
  }
  return false; 
}

int main(void)
{
  int tc;
  cin >> tc;
  for(cin.ignore(); tc--; ){
    string s;
    getline(cin, s);
    istringstream iss(s);
    sum = n = 0;
    for(n = 0; iss >> num[n]; ++n)sum += num[n];
    if(sum % 2)cout << "NO" << endl;
    else cout <<  (BT(0)? "YES" : "NO") << endl;
  }
  return 0;
}
