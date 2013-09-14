#include <iostream>
#include <algorithm>

using namespace std;

const int NODE = 100 + 1;

int main(void)
{  
  bool adj[NODE][NODE];
  int degree[NODE];
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    fill(degree, degree + n, 0);
    fill(&adj[0][0], &adj[n-1][n], false);
    if(n % 2 || n < 4){
      cout << "Impossible" << endl;
      continue;
    }
    for(int i=0, j=1; i<n; ++i){
      while(degree[i] < 3){
	if(j == n)j = i+1;
	for(; j<n; ++j){
	  if(degree[i] == 3)break;
	  if((j != n-1 && degree[j] < 2) || 
	     (j == n-1 && degree[j] < 3)){
	    adj[i][j] = adj[j][i] = true;
	    ++degree[i];
	    ++degree[j];
	  }
	}
      }
    }
    cout << n * 3 / 2 << endl;
    for(int i=0; i<n; ++i){
      for(int j=i+1; j<n; ++j){
	if(adj[i][j]){
	  cout << i + 1 << ' ' << j + 1 << endl;
	}
      }
    }
  }
  return 0;
}
