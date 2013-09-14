#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
  int tc;
  scanf("%d", &tc);
  while(tc--){
    int n, m;
    scanf("%d%d", &n, &m);
    int l = m - 1;
    int bit = 1 << (n - 2);
    int sum = 0;
    while(0 < l){
      if(l & 1)sum |= bit;
      bit >>= 1;
      l >>= 1;
    }
    printf("%d\n", sum + (1 << (n - 1)));
  }
  return 0;
}
