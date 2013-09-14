#include <cstdio>

using namespace std;

#define get12(p)\
    scanf("%d", p);\
    scanf("%d", p+1);\
    scanf("%d", p+2);\
    scanf("%d", p+3);\
    scanf("%d", p+4);\
    scanf("%d", p+5);\
    scanf("%d", p+6);\
    scanf("%d", p+7);\
    scanf("%d", p+8);\
    scanf("%d", p+9);\
    scanf("%d", p+10);\
    scanf("%d", p+11);
#define check(i)\
  if(n < r[i])printf("No problem. :(\n");\
  else{					 \
   printf("No problem! :D\n");\
   n -= r[i];\
  }	     \
  n += p[i];

static int p[12], r[12], tc = 0, n, i;

int main(void)
{
  scanf("%d", &n);
  if(n < 0)return 0;
  get12(p);
  get12(r);
  printf("Case %d:\n", ++tc);
  check(0);
  check(1);
  check(2);
  check(3);
  check(4);
  check(5);
  check(6);
  check(7);
  check(8);
  check(9);
  check(10);
  check(11);
  return main();
}
