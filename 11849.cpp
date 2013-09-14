#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main(void)
{
  while(true){
    int n, m;
    set<int> s;
    scanf("%d %d", &n, &m);
    if(n == 0 && m == 0)break;
    for(int i=0; i<n + m; ++i){
      int cd;
      scanf("%d", &cd);
      s.insert(cd);
    }
    printf("%d\n", m + n - (int)s.size());
  }
  return 0;
}
