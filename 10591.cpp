#include <iostream>
#include <set>

using namespace std;

typedef long long int lli;

bool calc(lli m)
{
  set<lli> S;
  while(true){
    int sum = 0;
    while(10 <= m){
      sum += (m % 10) * (m % 10);
      m /= 10;
    }
    sum += m * m;
    if(sum == 1)return true;
    m = sum;
    if(S.count(m))return false;
    S.insert(m);
  }
}

int main(void)
{
  int tc = 0, cnt = 0;
  for(cin >> tc; tc-- ; ){
    lli n; 
    cin >> n;
    cout << "Case #" << ++cnt << ": " << n << " is ";
    cout << (calc(n)? "a Happy" : "an Unhappy") << " number." << endl; 
  }
  return 0;
}
