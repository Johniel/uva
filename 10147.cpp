#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cfloat>

using namespace std;

const static int N = 751;
const static double INF = DBL_MAX;

double field[N][N];
int root[N];

double prim(int Fsize)
{
  double sum = 0;
  double cost[Fsize];
  bool visited[Fsize];
  fill(visited, visited + Fsize, false);
  fill(cost, cost + Fsize, INF);
  cost[0] = 0;
  root[0] = -1;
  while(true){
    int next = -1;
    double choice = DBL_MAX;
    for(int i=0; i<Fsize; i++){
      if(choice > cost[i] && visited[i] == false){
	next = i;
	choice = cost[i];
      }
    }
    if(choice == DBL_MAX || next == -1)
      break;
    sum += choice;
    visited[next] = true;
    for(int i=0; i<Fsize; i++){
      if(field[next][i] >= INF || visited[i] == true)
	continue;
      if(cost[i] > field[next][i]){
	root[i] = next;
	cost[i] = field[next][i];
      }
    }
  }
  return sum;
}

double dist(pair<double, double> a, pair<double, double> b)
{
  return sqrt( (a.first - b.first) * (a.first - b.first) + 
	       (a.second - b.second) * (a.second - b.second) );
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    if(n == 0)
      break;
    fill(&field[0][0], &field[N-1][N], INF);
    fill(&root[0], &root[N], -1);
    pair<double, double> point[n];
    for(int i=0; i<n; i++){
      cin >> point[i].first;
      cin >> point[i].second;
    }
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        field[i][j] = dist(point[i], point[j]);
        field[j][i] = field[i][j];
      }
    }
    int m;
    cin >> m;
    for(int i = 0; i<m; i++){
      int a, b;
      cin >> a >> b;
      a--;b--;
      field[a][b] = 0;
      field[b][a] = 0;
    }
    double re = prim(n);
    if(re == 0){
      cout << "No new highways need" << endl;
      continue;
    }
    
    for(int i=0; i<n; i++){
      if(root[i] == -1)continue;
      if(field[i][root[i]] == 0)continue;
      cout << i+1 << ' ' << root[i]+1 << endl;
    }
    if(tc)cout << endl;
  }
  return 0;
}
