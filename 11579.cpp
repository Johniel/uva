#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

double in[100000];

bool exist(double d, int size)
{
  int l = 0, r = size-1;
  while(l < r){
    
  }
  return false;
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    double result = -1;
    for(int i=0; i<n; i++)cin >> in[i];
    sort(in, in + n);
    for(int i=0; i<n-2; i++){
      for(int j=i+1; j<n-1; j++){
	for(int k=j+1; k<n; k++){
	  //cout << in[i] + in[j] << ' ' << in[k] << endl;
	  if(in[i] + in[j] > in[k])
	    result = max(result, 
			 in[i] * in[k] * sin( cos(in[i]/in[k]) ) / 2
			 );
	}
      }
    }
    printf("%.2lf\n", result);
  }
  return 0;
}
