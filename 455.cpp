#include <iostream>
#include <string>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

static const int M = 80 + 1;

bool check(char *str, int size)
{
  //cout << "len =>" << size << endl;
  int p = 0;
  char sub[size + 1];
  sub[size] = '\0';
  REP(i, size)sub[i] = str[i];
  while(p != strlen(str)){
    char tmp[size + 1];
    tmp[size] = '\0';
    REP(i, size)tmp[i] = str[p + i];
    //printf("%s : %s\n", sub, tmp);
    if(strcmp(sub, tmp))return false;
    p += size;
  }
  return true;
}

int main(void)
{
  int tc;
  cin >> tc;
  cin.ignore();
  while(tc--){
    cin.ignore();
    char str[M];
    REP(i, M)str[i] = '\0';
    gets(str);
    int divide = 1, re = strlen(str);
    int len = strlen(str);
    while(len/divide > 0){
      if(len%divide);
      else if( check(str, len / divide) ){
	re = len / divide;
      }
      divide++;
    }
    cout << re << endl;
    if(tc)cout << endl;
  }
  return 0;
}
