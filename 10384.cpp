#include <iostream>
#include <queue>
//#include <algorithm>
#include <set>

#define N 2 
#define E 4
#define S 8 
#define W 1

#define exist true
#define no_exist false

using namespace std;

class state{
public:
  bool line[5][6];
  bool row[4][7];

  bool operator<(const state &s) const {
    for(int i=0; i<5; i++)
      for(int j=0; j<6; j++)
	if( s.line[i][j] != line[i][j])
	  return s.line[i][j] > line[i][j];
    for(int i=0; i<4; i++)
      for(int j=0; j<7; j++)
	if( s.row[i][j] != row[i][j])
	  return s.row[i][j] > row[i][j];
    return false;
  }
};
  	
class wall_position{
public:
  state st;
  int x;
  int y;
  bool visited[4][6];
  vector<char> rout;

  void clear(void)
  {
    for(int i=0; i<4; i++)
      for(int j=0; j<6; j++)
	visited[i][j] = true;
  }
};

wall_position wall;

void test(void)
{
  static int cnt = 1;

  for(int i=0; i<4; i++){
    for(int j=0; j<6; j++){
      if( wall.st.line[i][j] == exist)
	cout << " --" ;
      else
	cout << "   " ;
    }
    cout << endl;
    for(int j=0; j<6; j++){
      if( wall.st.row[i][j] == exist)
	cout << "|" ;
      else 
	cout << " " ; 
      if(i == wall.y && wall.x == j)
	cout << "¡ü";
      else if(wall.visited[i][j])
	cout << "¡û" ;
      else
	cout << "¡ß";
    }
    if( wall.st.row[i][6])
      cout << "|  " << endl;
    else
      cout << endl;
  }
  for(int i=0; i<6; i++)
    if( wall.st.line[4][i] )
      cout << " --" ;
    else
      cout << "   ";
  cout << endl;
  cout << cnt << "²óÌÜ" << endl;
  cnt++;
}

void initialize(void)
{
  for(int i=0; i<5; i++)
    for(int j=0; j<6; j++)
      wall.st.line[i][j] =no_exist;
  for(int i=0; i<4; i++)
    for(int j=0; j<7; j++)
      wall.st.row[i][j] = no_exist;
  wall.clear();
  wall.rout.clear();
}

void input(void)
{
  initialize();

  for(int i=0; i<4; i++){
    for(int j=0; j<6; j++){
      int in;
      cin >> in;
      if( in & W )
	wall.st.row[i][j] = exist;
      if( in & E )
	wall.st.row[i][j+1] = exist;
      if( in & S )
	wall.st.line[i+1][j] = exist;
      if( in & N )
	wall.st.line[i][j] = exist;
    }
  }
}

bool comput(int x, int y)
{
  queue<wall_position> que;
  set<state> past;

  wall_position tmp;

  wall.x = x;
  wall.y = y;

  past.insert(wall.st);
  que.push(wall);
  //test();
  while(1){
    tmp = que.front();
    //if(que.empty())return true;
    //move
    if(tmp.x >= 0){
      if( tmp.st.row[tmp.y][tmp.x] == no_exist ){
	tmp.x--;
	tmp.rout.push_back('W');
	if(tmp.x == -1)
	  break;
	if( tmp.visited[tmp.y][tmp.x] ){
	  tmp.visited[tmp.y][tmp.x] = false;
	  que.push(tmp);
	}
	tmp = que.front();
      }
    }
    if( tmp.x+1 < 7 ){
      if( !tmp.st.row[tmp.y][tmp.x+1] ){
	tmp.x++;
	tmp.rout.push_back('E');
	if(tmp.x+1 == 7)
	  break;
	if( tmp.visited[tmp.y][tmp.x] ){
	  tmp.visited[tmp.y][tmp.x] = false;
	  que.push(tmp);
	}
	tmp = que.front();
      }
    }
    if(tmp.y >= 0){
      if( !tmp.st.line[tmp.y][tmp.x] ){
	tmp.y--;
	tmp.rout.push_back('N');
	if( tmp.y == -1)
	  break;
	if( tmp.visited[tmp.y][tmp.x] ){
	  tmp.visited[tmp.y][tmp.x] = false;
	  que.push(tmp);
	}
	tmp = que.front();
      }
    }
    if( tmp.y+1 < 6 ){
      if( !tmp.st.line[tmp.y+1][tmp.x] ){
	tmp.y++;
	tmp.rout.push_back('S');
	if(tmp.y+1 == 5)
	  break;
	if( tmp.visited[tmp.y][tmp.x] ){
	  tmp.visited[tmp.y][tmp.x] = false;
	  que.push(tmp);
	}
	tmp = que.front();
      }
    }
    //push     

    if(0 <= tmp.x-1)
      if( tmp.st.row[tmp.y][tmp.x] == exist && tmp.st.row[tmp.y][tmp.x-1] == no_exist){
	tmp.st.row[tmp.y][tmp.x] = no_exist;
	tmp.st.row[tmp.y][tmp.x-1] = exist;
	tmp.rout.push_back('W');
	//cout << "Push to West" << endl;
	tmp.x--;
	tmp.clear();
	tmp.visited[tmp.y][tmp.x] = false;
	if(past.count(tmp.st)-1){
	  que.push(tmp);
	  past.insert(tmp.st);
	}
	tmp = que.front();
      }
    if( tmp.x+2 < 7 )
      if( tmp.st.row[tmp.y][tmp.x+1] == exist && tmp.st.row[tmp.y][tmp.x+2] == no_exist){

	//wall = tmp;test();

	tmp.st.row[tmp.y][tmp.x+1] = no_exist;
	tmp.st.row[tmp.y][tmp.x+2] = exist;
	//tmp.rout.push_back('e');
	tmp.rout.push_back('E');
	tmp.x++;
	tmp.clear();
	tmp.visited[tmp.y][tmp.x] = false;
	if( past.count(tmp.st) == 0 ){
	  que.push(tmp);
	  past.insert(tmp.st);
	}
	tmp = que.front();
      }
    if( 0 <= tmp.y-1)
      if( tmp.st.line[tmp.y][tmp.x] == exist && tmp.st.line[tmp.y-1][tmp.x] == no_exist){
	tmp.st.line[tmp.y][tmp.x] = no_exist;
	tmp.st.line[tmp.y-1][tmp.x] = exist;
	//tmp.rout.push_back('n');
	tmp.rout.push_back('N');
	tmp.y--;
	tmp.clear();
	tmp.visited[tmp.y][tmp.x] = false;
	if(past.count(tmp.st)-1){
	  que.push(tmp);
	  past.insert(tmp.st);
	}
	tmp = que.front();	
      }
    if( tmp.y+2 < 5){
      //cout << "test" << endl;
      if( tmp.st.line[tmp.y+1][tmp.x] == exist && tmp.st.line[tmp.y+2][tmp.x] == no_exist){
	tmp.st.line[tmp.y+1][tmp.x] = no_exist;
	tmp.st.line[tmp.y+2][tmp.x] = exist;
	//tmp.rout.push_back('s');
	//cout << "Push to South" << endl;
	tmp.rout.push_back('S');
	tmp.y++;
	tmp.clear();
	tmp.visited[tmp.y][tmp.x] = false;
	if(past.count(tmp.st)-1){
	  que.push(tmp);
	  past.insert(tmp.st);
	}
	tmp = que.front();
      }
    }
    que.pop();
    //wall = tmp;test();
    //cout << "i = " << tmp.y << ' '<<  "j = " << ' ' << tmp.x << endl; 
    //cout << "queue.size() = " << que.size() << endl;
    //cout << "set.size() = " << past.size() << endl;
    if(que.empty())return true;
  }

  //wall = tmp;test();
  for(int i=0; i<tmp.rout.size(); i++)
    cout << tmp.rout[i];
  cout << endl;

  return false;
}

int main(void)
{
  while(1){
    int x,y;
    cin >> x >> y;
    if( x==0 || y==0 )
      break;
    input();
    if( comput(x-1,y-1) )
      return 0;
  }
  return 0;
} 


