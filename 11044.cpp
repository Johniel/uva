#include <iostream>
using namespace std;

int main(void)
{
  int t;

  cin >> t;
  while(t--){
    int n,m,i,j;
    cin >> n >> m;
    i = (n-2)/3;
    j = (m-2)/3;
    if((n-2)%3 != 0)
      i++;
    if((m-2)%3 != 0)
      j++;
    cout << i*j << endl;
  }
  return 0;
}
