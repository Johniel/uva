#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int S = 100000;

char s[S];
string msg[] = {"SIMPLE", 
                "FULLY-GROWN", 
                "MUTAGENIC", 
                "MUTANT"};

int parse(int b, int e, int d)
{
  int len = strlen(s);
  if(len % 2 == 0)return 3;
  if(len == 1){
    if(s[0] == 'A')return 0;
    else return 3;
  }
  if(s[len-2] == 'A' && s[len-1] == 'B')return 1;
  if(s[0] == 'B' && s[len-1] == 'A')return 2;
  return 3;
}
//BBAAABABAABAB
int main(void)
{  
  int tc;
  scanf("%d\n", &tc);
  while(tc--){
    scanf("%s\n", s);
    int len = strlen(s);
    printf("%s\n", msg[parse(0, len-1, 0)].c_str());
  }
  return 0;
}
