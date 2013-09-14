#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

int gcd(int a, int b)
{
  if(a % b == 0)return b;
  else return gcd(b, a%b);
}

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)
      break;
    int num[n];
    for(int i=0; i<n; i++){
      cin >> num[i];
    }
    sort(&num[0], &num[n], greater<int>());
    int cnt = 0, p = 0;
    for(int i=0; i<n-1; i++){
      for(int j=i+1; j<n; j++){
	if(gcd(num[i], num[j]) == 1){
	  //cout << num[i] << ' ' << num[j] << endl;
	  cnt++;
	}
	p++;
      }
    }
    //cout << cnt << endl;
    if(cnt == 0)
      cout << "No estimate for this data set." << endl;
    else
      printf("%.6f\n", sqrt( (double)(6*p)/(double)cnt ));
  }
  return 0;
}
