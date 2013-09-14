#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
  int t[77];
  t[0] = 0;
  t[1] = t[2] = 1;
  for(int i=3; i<77; ++i){      
    t[i] = t[i-2] + t[i-3];
  }
  for(int n; cin >> n; cout << t[n-1] + t[n] << endl);
  return 0;
}
