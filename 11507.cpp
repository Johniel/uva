#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const string dir[] = {"+x", "-x", "+y", "-y", "+z", "-z"};
const int PX = 0, NX = 1, PY = 2, NY = 3, PZ = 4, NZ = 5;

class Space{
public:
  int d[6];
  Space(){
    for(int i=0; i<6; ++i)d[i] = i;
  }
  void pY(void){
    int tmp = d[PX];
    d[PX] = d[PY];
    d[PY] = d[NX];
    d[NX] = d[NY];
    d[NY] = tmp;
  }
  void nY(void){
    pY();
    pY();
    pY();
  }
  void pX(void){
  }
  void nX(void){
  }
  void pZ(void){
    int tmp = d[PX];
    d[PX] = d[PZ];
    d[PZ] = d[NX];
    d[NX] = d[NZ];
    d[NZ] = tmp;
  }
  void nZ(void){
    pZ();
    pZ();
    pZ();
  }
};

#include <vector>

char v[100000 + 1][2];

int main(void)
{
  for(int n; ; ){
    scanf("%d\n", &n);
    if(n == 0)break;
    Space space;
    int i = 0;
    for(; i<n-1; ++i){
      scanf("%c %c\n", &v[i][0], &v[i][1]);
    }
    for(; i--;){
      char s = v[i][0], d = v[i][1];
      if(s == '+'){
	if(d == 'x')space.pX();
	if(d == 'y')space.pY();
	if(d == 'z')space.pZ();
      }
      else if(s == '-'){
	if(d == 'x')space.nX();
	if(d == 'y')space.nY();
	if(d == 'z')space.nZ();
      }
    }
    printf("%s\n", dir[space.d[0]].c_str());
  } 
  return 0;
}
