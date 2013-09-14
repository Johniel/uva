#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

static const int N = 3;
static const int LIM1 = 1 << 20;
static const int LIM2 = 2 * 16;

class Puzzle{
public:
  string path;
  char num[N * N];
  long long int id;
  Puzzle(void){
    id = 0;
    path = "";
    num[0] = num[1] = num[2] = num[3] = num[4] = 
      num[5] = num[6] = num[7] = num[8] = num[9] = '0'; 
    return ;
  }
  void moveRight(int h){ 
    int p = h * 3;    
    char tmp = num[p + 2];
    num[p + 2] = num[p + 1];
    num[p + 1] = num[p + 0];
    num[p + 0] = tmp;
    path += 'H';
    path += (char)('1' + h);
    calcId();
    return ;
  } 
  void moveUp(int w){   
    int p = w;    
    char tmp = num[p + 0];
    num[p + 0] = num[p + 3];
    num[p + 3] = num[p + 6];
    num[p + 6] = tmp;
    path += 'V';
    path += (char)('1' + w);
    calcId();
    return ;
  } 
  void backRight(int h){
    int p = h * 3;    
    char tmp = num[p + 0];
    num[p + 0] = num[p + 1];
    num[p + 1] = num[p + 2];
    num[p + 2] = tmp;
    path = (char)('1' + h) + path;
    path = 'H' + path;
    calcId();
    return ;
  } 
  void backUp(int w){ 
    int p = w;    
    char tmp = num[p + 6];
    num[p + 6] = num[p + 3];
    num[p + 3] = num[p + 0];
    num[p + 0] = tmp;
    path = (char)('1' + w) + path;
    path = 'V' + path;
    calcId();
    return ;
  } 
  void calcId(void){
    id = 0;
    for(int i=0; i<9; ++i){
      id += num[i] - '0';
      id *= 10;
    }
    return ;
  }
};

inline
bool operator < (const Puzzle &a, const Puzzle &b)
{
  return a.id > b.id;
}

#define PREV(i)\
     q = p;\
      q.backRight(i);\
      if(S.count(q) == 0){\
	S.insert(q);\
	 Q.push(q);\
      }\
      q = p;\
      q.backUp(i);\
      if(S.count(q) == 0){\
	S.insert(q);\
	 Q.push(q);\
      }

inline
void makeDstSide(set<Puzzle> &S)
{
  queue<Puzzle> Q;
  Puzzle ini;
  int cnt = 0;
  for(int i=0; i<9; ++i)
    ini.num[i] = (char)('1' + i);
  ini.calcId();
  S.insert(ini);
  for( Q.push(ini); ! Q.empty();  Q.pop()){
    Puzzle p =  Q.front(), q;
    if(LIM1 <= p.path.size())continue;
    PREV(2);
    PREV(1);
    PREV(0);
  }  
  return ;
}

#define INPUT scanf(" %c", &c); ini.num[cnt++] = c;
int main(void)
{  
  set<Puzzle> S;
  makeDstSide(S);
  Puzzle ini;
  char c;
  while(true){
    int cnt = 0;
    for(int i=0; i<9; ++i){
      cin >> ini.num[cnt];
      if(ini.num[cnt++] == '0')return 0;
    }
    ini.calcId();
    set<Puzzle>::iterator itr = S.find(ini);
    if(itr == S.end())printf("Not solvable\n");
    else printf("%d %s\n", itr->path.size()/2, itr->path.c_str());
  }
  return 0;
}
