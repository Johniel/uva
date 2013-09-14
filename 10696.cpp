#include <iostream>

using namespace std;

int main(void)
{
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    printf("f91(%d) = ", n);
    if(n>=101)printf("%d\n", n-10);
    else printf("91\n");
  }
  return 0;
}
