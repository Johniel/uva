#include <iostream>
#include <algorithm>

using namespace std;

#define N 100

int main(void)
{
  int n, determinant[N][N];
  cin >> n;
  fill(&determinant[0][0], &determinant[N-1][N], 0);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> determinant[i][j];
    }
  }
  int result = INT_MIN;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int m=n-1; m>=i; m--){
	for(int a=n-1; a>=j; a--){
	  if(n-j-a==n-m-i)continue;
	  int tmp = 0;
	  for(int k=0+i; k<n-m; k++){
	    for(int l=0+j; l<n-a; l++){
	      tmp += determinant[k][l];
	    }
	  }
	  result = max(result, tmp);
	}
      }
    }
  }
  cout << result << endl;
  return 0;
}
