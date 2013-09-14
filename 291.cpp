#include <iostream>
#include <algorithm>

using namespace std;

static const int N = 5;

//                  0  1  2  3  4
int field[N][N] = {{0, 1, 1, 0, 1}, //0
		   {1, 0, 1, 0, 1}, //1
		   {1, 1, 0, 1, 1}, //2
		   {0, 0, 1, 0, 1}, //3
		   {1, 1, 1, 1, 0}};//4
int n = 0, p = 0;
char re[7];
int main(void)
{
  if(count(&field[0][0], &field[N-1][N], 1) == 0)
    cout << 1 << re << endl;
  for(int i=0; i<N; i++){
    if(field[n][i]){
      field[n][i] = 0;
      field[i][n] = 0;
      re[p++] = '1' + i;
      int tmp = n;
      n = i;
      main();
      n = tmp;
      p--;
      field[n][i] = 1;
      field[i][n] = 1;
    }
  }
  if(n == 0)return 0;
}
