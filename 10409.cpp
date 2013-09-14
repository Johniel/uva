#include <iostream>

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
  void toUp(void){
    int tmp = num[TOP];
    num[TOP] = num[FRONT];
    num[FRONT] = num[BOTTOM];
    num[BOTTOM] = num[BACK];
    num[BACK] = tmp;
  }
  void toDown(void){
    toUp();
    toUp();
    toUp();
  }
};

int main(void)
{
  for(int n; cin >> n; ){
    if(n == 0)break;
    Dice d;
    for(; n--; ){
      string s;
      cin >> s;      
      if(s == "north")d.toUp();
      if(s == "south")d.toDown();
      if(s == "east")d.toRight();
      if(s == "west")d.toLeft();
    }
    cout << d.num[TOP] << endl;
  }
  return 0;
}
