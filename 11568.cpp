#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cassert> 

#define EAST 0
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define X 4

#define REP(i, n) for(int i=0; i<n; ++i)

using namespace std;

static const int MAX = 10 + 1;

static const int ROB = 2;

static const int MOVE = 5;
static const int DIR = 4;

static const int ni[MOVE] = {0, -1, 1,  0, 0};
static const int nj[MOVE] = {1,  0, 0, -1, 0};

static const char dir[MOVE] = {'E', 'N', 'S', 'W', 'X'};
static const int toRight[DIR] = {SOUTH, EAST, WEST, NORTH};

//static const char death[] = 

static const int Qsize = 20000;

static const int MOD = 1000007;

class obj{
public:
  int i, j, d;
  bool operator < (const obj o)const{
    if(i != o.i)return i < o.i;
    if(j != o.j)return j < o.j;
    return d < o.d;
  }
};

class state{
public:
  int mi, mj;
  obj rob[ROB];
  string path;
  bool operator < (const state s)const{
    if(rob[0].i != s.rob[0].i)return rob[0].i < s.rob[0].i;
    if(rob[0].j != s.rob[0].j)return rob[0].j < s.rob[0].j;
    if(rob[0].d != s.rob[0].d)return rob[0].d < s.rob[0].d;
    if(rob[1].i != s.rob[1].i)return rob[1].i < s.rob[1].i;
    if(rob[1].j != s.rob[1].j)return rob[1].j < s.rob[1].j;
    if(rob[1].d != s.rob[1].d)return rob[1].d < s.rob[1].d;
    if(mi != s.mi)return mi < s.mi;
    return mj < s.mj;
  }
};

template<class T>
class queue{
public:
  //int size;
  queue(){head = tail = 0;}
  void push(const T &t){
    //assert(!((tail+1)%Qsize == head));
    array[tail++] = t;
    if(tail>=Qsize) tail %= Qsize;
    //size++;
  }
  const T& front(void){return (array[head]);}
  void pop(void){++head; if(head>=Qsize) head %= Qsize;}//--size;}
  bool empty(void){return head == tail;}
private:
  T array[Qsize];
  int head, tail;
};

char field[MAX][MAX];

int sepR[MAX][MAX], sepC[MAX][MAX];

bool visited[MOD];

int makeHash(state *p)
{
  int result = 0;
  result += p->mi; result *= 13; result %= MOD;
  result += p->mj; result *= 13; result %= MOD;
  result += p->rob[0].i; result *= 13; result %= MOD;  
  result += p->rob[0].j; result *= 13; result %= MOD;  
  result += p->rob[0].d; result *= 13; result %= MOD;  
  result += p->rob[1].i; result *= 13; result %= MOD;  
  result += p->rob[1].j; result *= 13; result %= MOD;  
  result += p->rob[1].d; result *= 13; result %= MOD;  
  return result;
}

string BFS(const state ini, const int size)
{
  queue<state> Q = queue<state>();
  fill(visited, visited + MOD, false);
  state next;
  for(Q.push(ini); !Q.empty(); Q.pop()){
    //cout << Q.size << endl;
    REP(i, MOVE){
      //next = *(new state());
      next = Q.front();
      int si = next.mi + ni[i], sj = next.mj + nj[i];

      if((next.rob[0].i == si && next.rob[0].j == sj) || 
	 (next.rob[1].i == si && next.rob[1].j == sj) ||
	 field[si][sj] == '#')continue;

      if(field[si][sj] == 'T')return (next.path + dir[i]);

      next.mi = si, next.mj = sj;
      
      REP(k, ROB){//rob
	if(next.mi == next.rob[k].i && sepR[next.mi][next.mj] == 
	   sepR[next.rob[k].i][next.rob[k].j])
	  next.rob[k].d = (next.mj < next.rob[k].j)? WEST : EAST;
	else if(next.mj == next.rob[k].j && sepC[next.mi][next.mj] == 
		sepC[next.rob[k].i][next.rob[k].j])
	  next.rob[k].d = (next.mi < next.rob[k].i)? NORTH : SOUTH;
	while(true){
	  si = next.rob[k].i + ni[next.rob[k].d];
	  sj = next.rob[k].j + nj[next.rob[k].d];
	  if(field[si][sj] == ' ')break;
	  next.rob[k].d = toRight[next.rob[k].d];
	}
	next.rob[k].i = si, next.rob[k].j = sj;//go forward
      }

      if((next.rob[0].i == next.mi && next.rob[0].j == next.mj) || 
	 (next.rob[1].i == next.mi && next.rob[1].j == next.mj) )continue;
      
      if(!(next.rob[0] < next.rob[1]))swap(next.rob[0], next.rob[1]);
      
      int h = makeHash(&next);

      if(visited[h]){
	//cout << next.mi << ' ' << next.mj << ' ' << next.path << endl;
	continue;
      }
      //cout << next.mi << ' ' << next.mj << ' ' << next.path << endl;
      next.path += dir[i];
      Q.push(next);
      visited[h] = true;
    }
  }
  return  "You can't escape...";
}

int main(void)
{
  //bool flg = true;
  while(true){
    int n;
    scanf("%d", &n);
    if(n == 0)break;
    //if(flg)flg = false;
    //else printf("\n");
    state ini;
    int r = 0;
    getchar();
    REP(i, n){
      gets(field[i]);
      int length = strlen(field[i]);
      REP(j, length){
	if(field[i][j] == 'X'){
	  ini.mi = i;
	  ini.mj = j;
	  field[i][j] =' ';
	}
	else if(field[i][j] == 'E' || field[i][j] == 'N' || 
		field[i][j] == 'S' || field[i][j] == 'W'){
	  ini.rob[r].i = i;
	  ini.rob[r].j = j;
	  ini.rob[r].d = distance(dir, find(dir, dir + DIR, field[i][j]));
	  r++;
	  field[i][j] = ' ';
	}
      }
    }
    REP(i, n){
      int col = 0;
      REP(j, n){
	if(field[i][j] != ' '){
	  sepR[i][j] = -1;
	  col++;
	}
	sepR[i][j] = col;
      }
    }
    REP(j, n){
      int col = 0;
      REP(i, n){
	if(field[i][j] != ' '){
	  sepC[i][j] = -1;
	  col++;
	}
	sepC[i][j] = col;
      }
    } 
    
    //cout << n << endl;REP(i, n){REP(j, n)cout << field[i][j] << ' ' ; cout << endl;}return 0;

    if(!(ini.rob[0] < ini.rob[1]))swap(ini.rob[0], ini.rob[1]);
    //printf("%s\n", BFS(ini, n));
    cout << BFS(ini, n) << endl;
  }
  return 0;
}
