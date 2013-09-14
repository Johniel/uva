#include <iostream>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

class Box{
public:
  int height, content;
  vector<Box> boxes;
  Box(){}
  Box(int h){
    height = h;
    content = 0;
    boxes.clear();
  }
  bool include(const Box &box){
    REP(i, boxes.size())
      if(boxes[i].include(box))return true;
    if(height - content < box.height)return false;
    boxes.push_back(box);
    content += box.height;
    return true;
  }
};

int main(void)
{
  int n, h;
  while(cin >> n){
    Box box(1 << 20);
    REP(i, n){
      cin >> h;
      box.include(Box(h));
    }
    cout << box.content << endl;
  }
  return 0;
}
