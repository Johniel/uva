#include <iostream>
#include <algorithm>

using namespace std;

const int DIR = 4;				
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

class Ball{
public:
  int dir, i, j, life, point;
  Ball(void){}
  Ball(int _i, int _j, int d, int l) 
    : i(_i), j(_j), dir(d), life(l), point(0) {}
  void rebound(int dmg){
    dir = (dir + 1) % DIR;
    life -= dmg;    
  }  
  void move(int _i, int _j){
    i = _i;
    j = _j;
  }
};

inline int conv(int d)
{
  if(d == 0)return 3;
  if(d == 1)return 2;//
  if(d == 2)return 1;
  if(d == 3)return 0;//
}

const int H = 51, W = 51;
const int EMPTY = 0, WALL = 1, BUMPER = 2;

class Game{
public:
  Ball ball;
  int sum, h, w;
  int cost[H][W], v[H][W], type[H][W];
  Game(){ run(); }
  void run(void){
    for(init(); getInput(); sim());
    cout << sum << endl;
  }
  void init(void){
    int bumper, wall;
    fill(&cost[0][0], &cost[H-1][W], 0);
    fill(&v[0][0], &v[H-1][W], 0);
    fill(&type[0][0], &type[H-1][W], EMPTY);
    
    cin >> h >> w >> wall >> bumper;

    for(int i=0; i<h; ++i){
      type[i][0] = type[0][i] = WALL;
      type[i][w-1] = type[h-1][i] = WALL;
      cost[i][0] = cost[0][i] = wall;
      cost[i][w-1] = cost[h-1][i] = wall;
    }

    for(int i=0; i<bumper; ++i){
      int a, b;
      cin >> a >> b;
      --a; --b;
      cin >> v[b][a] >> cost[b][a];
      type[b][a] = BUMPER;
    }
  }
  void sim(void){
    while(0 < ball.life){
      int bi = ball.i, bj = ball.j;
      int ni = bi + di[ball.dir];
      int nj = bj + dj[ball.dir];      
      
      //cout << bi << ' ' << bj << ' ' << ball.dir << endl;
      --ball.life;
      if(ball.life == 0)break;
      if(type[ni][nj]){
	if(type[ni][nj] == BUMPER){
	  ball.point += v[ni][nj];
	}
	ball.rebound(cost[ni][nj]);
	if(ball.life <= 0)break;
	ni = bi;
	nj = bj;
      }  
      ball.move(ni, nj);
    }
    sum += ball.point;
    cout << ball.point << endl;
  }
  bool getInput(void){
    int a, b, c, d;
    if(cin >> a >> b >> c >> d){
      ball = Ball(b-1, a-1, conv(c), d);
      return true;
    }
    else return false;
  }
};


int main(void)
{
  Game();
  return 0;
}
