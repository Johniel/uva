// 11959
#include <iostream>
#include <set>

using namespace std;

enum{TOP = 0, BOTTOM = 1, LEFT = 2, RIGHT = 3, FRONT = 4, BACK = 5};

class Dice{
public:
  int num[6];
  Dice(){
    num[TOP] = 1;
    num[FRONT] = 5;
    num[LEFT] = 3;
    num[RIGHT] = 4;
    num[BACK] = 2;
    num[BOTTOM] = 6;
  }
  void toRight(void){
    int tmp = num[TOP];
    num[TOP] = num[LEFT];
    num[LEFT] = num[BOTTOM];
    num[BOTTOM] = num[RIGHT];
    num[RIGHT] = tmp;
  }
  void toLeft(void){
    toRight();
    toRight();
    toRight();
  }
  void toTop(void){
    int tmp = num[TOP];
    num[TOP] = num[FRONT];
    num[FRONT] = num[BOTTOM];
    num[BOTTOM] = num[BACK];
    num[BACK] = tmp;
  }
  void toBottom(void){
    toTop();
    toTop();
    toTop();
  }
  void toCW(void){
    int tmp = num[FRONT];
    num[FRONT] = num[RIGHT];
    num[RIGHT] = num[BACK];
    num[BACK] = num[LEFT];
    num[LEFT] = tmp;
  }
  void toCCW(void){
    toCW();
    toCW();
    toCW();
  }
};

inline
bool operator < (const Dice &a, const Dice &b)
{
#define DEF(n) if(a.num[n] != b.num[n])return a.num[n] < b.num[n];
  DEF(0);
  DEF(1);
  DEF(2);
  DEF(3);
  DEF(4);
  DEF(5);
  return false;
}

inline
Dice make_dice(string s)
{
  Dice d;
  d.num[TOP]    = s[0] - '0';
  d.num[BOTTOM] = s[1] - '0';
  d.num[FRONT]  = s[2] - '0';
  d.num[LEFT]   = s[3] - '0';
  d.num[BACK]   = s[4] - '0';
  d.num[RIGHT]  = s[5] - '0';
  return d;
}

int main(void)
{
  int tc;
  cin >> tc;
  while( tc-- ){
    string s, t;
    cin >> s >> t;
    Dice a = make_dice(s);
    Dice b = make_dice(t);  
    set<Dice> vis;
    const int N = 8;
    for(int i=0; i<N; ++i){
      a.toTop();
      for(int j=0; j<N; ++j){
        a.toLeft();
        for(int k=0; k<N; ++k){
          a.toCW();
          vis.insert(a);
        }
      }
    }
    bool flg = true;
    for(int i=0; i<N; ++i){
      b.toTop();
      for(int j=0; j<N; ++j){
        b.toLeft();
        for(int k=0; k<N; ++k){
          b.toCW();
          flg = flg && vis.count(b);
          if(!flg)i = j = k = N;
        }
      }
    }
    cout << (flg ? "" : "Not ") << "Equal" << endl;
  }
  return 0;
}
