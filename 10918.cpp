#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  int t[31];
  fill(t, t + 31, 0);
  t[0] = 1;
  t[2] = 3;
  for(int i=4; i<31; i+=2){
    t[i] = t[i-2] * 3;    
    for(int j=4; ; j+=2){
      if(i - j >= 0){
	int k = j / 2;
	t[i] += t[i-j] * 2;
      }
      else break;
    }
  }

  for(int n; ; ){
    cin >> n;
    if(n == -1)break;
    cout << t[n] << endl;
  }
  return 0;
}
