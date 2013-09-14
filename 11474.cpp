#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

const static int N = 100 + 1;
const static int M = 10 + 1;

int m;
bool visited[N];
bool G[N][N];
pair<int, int> point[N][M];

bool edge(pair<int, int> a, pair<int, int> b, int d)
{
  int ax = a.first, ay = a.second, bx = b.first, by = b.second;
  //cout << ax << ' ' << ay << ' ' << bx << ' ' << by << endl;
  if((double)d >= sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) ) )
    return true;
  return false;
}

void connect(int a, int b, int lima, int limb, int dis)
{
  for(int i=0; i<lima; i++){
    for(int j=0; j<limb; j++){
      if(edge(point[a][i], point[b][j], dis) == true){
	G[a][b] = true;
	G[b][a] = true;
      }
    }
  }
}

bool dfs(int name)
{
  //cout << name << endl;
  if(name == 0)
    return true;
  visited[name] = true;
  for(int i=0; i<N; i++){
    if(G[name][i] == true && visited[i] == false){
      if(dfs(i) == true)
        return true;
    }
  }
  return false;
}

int main(void)
{
  int tc;
  cin >> tc;
  //cout << D_MAX << endl;
  while(tc--){
    int n, d, k;
    cin >> n >> m >> k >> d;
    fill(&G[0][0], &G[N-1][N], false);
    fill(visited, visited+N, false);   
    int num[N];
    for(int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      point[0][i] = make_pair(a, b);
    }

    for(int i=0; i<n; i++){
      cin >> num[i];
      for(int j=0; j<num[i]; j++){
        int a, b;
        cin >> a >> b;
        point[i+1][j] = make_pair(a, b);
      }
    }

    for(int i=0; i<n; i++){
      connect(0, i+1, m, num[i], d);
    }

    for(int i=0+1; i<n+1-1; i++){
      for(int j=i+1; j<n+1; j++){
	connect(i, j, num[i-1], num[j-1], k);
      }
    }
    /*
    for(int i=0; i<m+n; i++){
      for(int j=0; j<m+n; j++){
	if(G[i][j])cout << 1 << ' ' ;
	else cout << 0 << ' ' ;
      }
      cout << endl;
    }
    */

    if(dfs(1) == true)
      cout << "Tree can be saved :)" << endl;
    else
      cout << "Tree can't be saved :(" << endl;        
  }
  return 0;
}






