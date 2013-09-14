#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void)
{
  string s;
  for(int n; ; ){
    cin >> n;
    if(n == 0)break; 

    printf("5 %d\n", n);
    puts("0 1 1 1 R");// enter

    puts("1 0 9 0 R");// fin
    puts("1 1 2 1 R");// next

    puts("2 0 2 0 R");// ml
    puts("2 1 1 1 L");// tl
    

    for(int i=0; i<n; ++i){
      cin >> s;
      if(s == "AC")puts("1 1");
      else if(s == "WA")puts("1 9");
      else if(s == "MLE")puts("2 9");
      else if(s == "TLE")puts("3 9");
    }
  }
  return 0;
}
