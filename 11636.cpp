#include <iostream>

using namespace std;

int main(void)
{
  int tc = 0;
  int n, sum;
  while(true){
    sum = 0;
    scanf("%d", &n);
    if(n < 0)
      break; 
    while(n != 1){
      n += n & 1;
      ++sum;
      n >>= 1;
    }
    printf("Case %d: %d\n", ++tc, sum);
  }
  return 0;
}
