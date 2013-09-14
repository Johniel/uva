#include <iostream>
#include <algorithm>

using namespace std;

char takeGrade(int s)
{
  if(s >= 90)return 'A';
  if(s >= 80)return 'B';
  if(s >= 70)return 'C';
  if(s >= 60)return 'D';
  return 'F';
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int t1, t2, f, a, ct1, ct2, ct3;
    cin >> t1 >> t2 >> f >> a >> ct1 >> ct2 >> ct3;
    int tmp = ct1 + ct2 + ct3 - min(ct1, min(ct2, ct3));    
    cout << "Case " << ++cnt << ": " <<takeGrade(t1 + t2 + f + a + tmp / 2) << endl;
  }
  return 0;
}
