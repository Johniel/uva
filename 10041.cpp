#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int num[500], sum[500];
  int tc;
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> num[i];
      sum[i] = 0;
    }
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	sum[i] += abs(num[i] - num[j]);
      }
    }
    int result, dist = 1 << 30;
    for(int i=0; i<n; ++i){
      if(dist > sum[i]){
	dist = sum[i];
	result = i;
      }
    }
    cout << sum[result] << endl;
  }
  return 0;
}
