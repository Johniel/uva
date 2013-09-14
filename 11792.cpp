#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int NODE = 10000 + 2;
const int ADJ = 100 + 2;
const int INF = 1 << 20;
const int LINE = 100;

int adj[ADJ][ADJ], cnt[NODE], name[NODE], rev[NODE];
int pos[LINE][NODE];

int main(void)
{
  int tc, node, line;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d%d", &node, &line);
    fill(cnt, cnt + node, 0);
    for(int i=0; i<line; ++i){
      fill(pos[i], pos[i] + node, -1);
      int j = 0;
      while(true){
	int n;
	scanf("%d", &n);
	if(n == 0)break;
	--n;
	pos[i][n] = j;
	++cnt[n];
	++j;
      }
    }
    int size = 0;
    for(int i=0; i<node; ++i){
      if(1 < cnt[i]){
	name[i] = size;
	rev[size] = i;
	++size;
      }
    }
    for(int i=0; i<size; ++i){
      for(int j=i+1; j<size; ++j){
	if(i == j)adj[i][j] = 0; 
	else{
	  int mn = INF;
	  for(int k=0; k<line; ++k){
	    int src = rev[i], dst = rev[j];
	    if(pos[k][src] != -1 && pos[k][dst] != -1){
	      int c = abs(pos[k][src] - pos[k][dst]) * 2;
	      if(mn > c){
		mn = c;
	      }
	    }
	  }
	  adj[i][j] = adj[j][i] = mn;
       }
      }
    }
    for(int k=0; k<size; ++k){
      for(int i=0; i<size; ++i){
	for(int j=i+1; j<size; ++j){
	  int c = adj[i][k] + adj[k][j];
	  if(adj[i][j] > c){
	    adj[i][j] = adj[j][i] = c;
	  }
	}
      }
    }
    int result, dist = INF;
    for(int i=0; i<size; ++i){
      int sum = 0;
      for(int j=0; j<size; ++j){
	sum += adj[i][j];
      }
      if(sum < dist){
	result = i;
	dist = sum;
      }
    }
    printf("Krochanska is in: %d\n",rev[result]+1);
  }
  return 0;
}
