#include <iostream>
#include <queue>

#define N 100+1
#define BLANK 'Z'
#define SPACE '.'

using namespace std;

char field[N][N];
int si, sj;
int gi, gj;

const int zi[8] = {-2, -2, -1, -1, 1,  1, 2,  2};
const int zj[8] = { 1, -1,  2, -2, 2, -2, 1, -1};
const int ki[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int kj[8] = {-1,  0,  1, -1, 1, -1, 0, 1};


void input(void)
{
  int n, m;
  fill(&field[0][0], &field[N-1][N], BLANK);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> field[i][j];
      if(field[i][j] == 'A'){
	si = i;
	sj = j;
      }
      else if( field[i][j] == 'B'){
	gi = i;
	gj = j;
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(field[i][j] == BLANK){
	for(int k=0; k<8; k++){
	  int ni = i+zi[k], nj = j+zj[k];
	  if( ni >= 0 && nj >= 0 && ni < N && nj < N && field[ni][nj] != BLANK)
	    field[ni][nj] = 'z';
	}
      }
    }
  }
  field[gi][gj] = SPACE;
  return ;
}

int compute(void)
{
  int step[N][N];
  queue< pair<int,int> > que;
  fill(&step[0][0], &step[N-1][N], 0);
  que.push(make_pair(si, sj));

  while( !que.empty() ){
    pair<int, int> now;
    now = que.front();
    //cout << now.first << ' ' <<  now.second << endl;
    if(now.first == gi && now.second == gj )return step[gi][gj];
    int ni, nj;
    for(int i=0; i<8; i++){
      ni = now.first + ki[i];
      nj = now.second + kj[i];
      if( ni >= 0 && nj >= 0 && ni < N && nj < N ){
	if( field[ni][nj] == SPACE && step[ni][nj] == 0 ){
	  que.push(make_pair(ni, nj));
	  step[ni][nj] = step[now.first][now.second] + 1;
	}
      } 
    }
    que.pop();
  }

  return -1;
}

void test(void){
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      cout << field[i][j];
    }
    cout << endl;
  }
}

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    input();
    //test();
    int result = compute();
    if( result < 0 )
      cout << "King Peter, you can't go now!" << endl;
    else
      cout << "Minimal possible length of a trip is " << result << endl;
  }
  return 0;
}


/*
typedef struct{
  bool field[N][N];
  int x;
  int y;
  int step;
}state;

pair<int,int> Z[N];
int Zposi = 0;
int gx, gy;
state in;
void input()//state in)
{
  int n,m;
  in.step = 0;
  Zposi = 0;
  fill(&in.field[0][0], &in.field[N-1][N], false);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char c;
      cin >> c;
      if( c == '.' ){
	in.field[i][j] = true;
      }
      else if( c == 'Z' ){
	Z[Zposi].first = i;
	Z[Zposi].second = j;
	Zposi++;
      }
      else if( c == 'A' ){
	in.x = i;
	in.y = j;
      }
      else if( c == 'B' ){
	in.field[i][j] = true;
	gx = i;
	gy = j;
      }
    }
  }
}

void knight()//state in)
{
  for(int a=0; a<Zposi; a++){
    int i = Z[a].first;
    int j = Z[a].second;
    if( i-2 >=0 ){
      if( j-1 >=0 ){
	if( gx != i-2 || gy != j-1 )in.field[i-2][j-1] = false;
      }
      if( j+1 < N ){
	if( gx != i-2 || gy != j+1 )in.field[i-2][j+1] = false;
      }
    }
    if( i-1>=0){
      if( j-2 >=0 ){
	if( gx != i-1 || gy != j-2 )in.field[i-1][j-2] = false;
      }
      if( j+2 < N ){
	if( gx != i-1 || gy != j+2 )in.field[i-1][j+2] = false;
      } 
    }
    if( i+1>=0){
      if( j-2 >=0 ){
	if( gx != i+1 || gy != j-2 )in.field[i+1][j-2] = false;
      }
      if( j+2 < N ){
	if( gx != i+1 || gy != j+2 )in.field[i+1][j+2] = false;
      } 
    }
    if( i+2 >=0 ){
      if( j-1 >=0 ){
	if( gx != i+2 || gy != j-1 )in.field[i+2][j-1] = false;
      }
      if( j+1 < N ){
	if( gx != i+2 || gy != j+1 )in.field[i+2][j+1] = false;
      }
    }
  }
}

int compute()//state in)
{
  queue<state> que;
  //bool visited[N][N] = in.field;
  que.push(in);
  //cout << "g " << gx << ',' << gy << endl;
  while( !que.empty() ){
    state now = que.front();
    int i = now.x;
    int j = now.y;
    //cout << i << ',' << j << endl;
    if( gx == now.x && gy ==now.y )return now.step;
    if( i-1 >= 0){
      if( j-1 >= 0){
	if( now.field[i-1][j-1] ){//&& visited[i-1][j-1]){
	  now.field[i][j] = false;
	  now.x = i-1;
	  now.y = j-1;
	  now.step++;
	  que.push(now);
	  now = que.front();
	}
      }
      if( j+1 < N){
	if( now.field[i-1][j+1] ){// && visited[i-1][j+1]){
	  now.field[i][j] = false;
	  now.x = i-1;
	  now.y = j+1;
	  now.step++;
	  que.push(now);
	  now = que.front();
	}
      } 
      if( j >= 0){
	if( now.field[i-1][j] ){// && visited[i-1][j]){
	  now.field[i][j] = false;
	  now.x = i-1;
	  now.y = j;
	  now.step++;
	  que.push(now);
	  now = que.front();
	}
      }
    }
    if( i+1 >= 0){
      if( j-1 >= 0){
	if( now.field[i+1][j-1] ){// && visited[i-1][j-1]){
	  now.field[i][j] = false;
	  now.x = i+1;
	  now.y = j-1;
	  now.step++;
	  que.push(now);
	  now = que.front();
	}
      }
      if( j+1 < N){
	if( now.field[i+1][j+1] ){// && visited[i-1][j+1]){
	  now.field[i][j] = false;
	  now.x = i+1;
	  now.y = j+1;
	  now.step++;
	  que.push(now);
	  now = que.front();
	}
      } 
      if( j >= 0){
	if( now.field[i+1][j] ){// && visited[i-1][j]){
	  now.field[i][j] = false;
	  now.x = i+1;
	  now.y = j;
	  now.step++;
	  que.push(now);
	  now = que.front();
	}
      }
    }
    //cout << "test" << endl;
    if( j-1 >= 0){
      if( now.field[i][j-1] ){// && visited[i-1][j-1]){
	  now.field[i][j] = false;
	  now.x = i;
	  now.y = j-1;
	  now.step++;
	  que.push(now);
	  now = que.front();
      }
    }
    if( j+1 < N){
      if( now.field[i][j+1] ){// && visited[i-1][j+1]){
	  now.field[i][j] = false;
	  now.x = i;
	  now.y = j+1;
	  now.step++;
	  //cout << "move right " << now.x << ',' << now.y << endl;
	  que.push(now);
	  now = que.front();
      }
    }
    que.pop();
  }
  return -1;
}

void test(void)
{
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if( in.field[i][j] )
	cout << '.' ;
      else
	cout << 'Z';
    }
    cout << endl;
  }
}

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    input();//in);
    //cout << "end of input" << endl;
    //test();cout << endl;
    knight();//in);
    //cout << "end of knight" << endl;
    //test();
    int result = compute();//in);
    //cout << "end of compute" << endl;
    if( result != -1)
      cout << "Minimal possible length of a trip is " << result << endl;
    else
      cout << "King Peter, you can't go now!" << endl;
  }
  return 0;
}
*/
