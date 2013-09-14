#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

char s[4][12+1];
int idx[4];

int main(void)
{
  const int size = 12;
  int mx, tmp;
  int a, b, c, d, e, f;
  while( scanf("%s %s %s %s", s[0], s[1], s[2], s[3]) == 4 ){
    idx[0] = 0;
    idx[1] = 1;
    idx[2] = 2;
    idx[3] = 3;
    mx = 0;
    do{
      for(a=1; a+1<size; ++a){
        for(b=a+1; b+1<size; ++b){
          for(c=1; c+1<size; ++c){
            if(s[idx[0]][a] != s[idx[1]][c])continue;
            for(d=1; d+1<size; ++d){
              if(s[idx[0]][b] != s[idx[2]][d])continue;
              for(e=1; c+e+1<size && d+e+1<size; ++e){
                for(f=1; f+1<size; ++f){
                  if(f+b-a <= 0 || 11 <= f+b-a)continue;
                  if(s[idx[1]][c+e] != s[idx[3]][f])continue;
                  if(s[idx[2]][d+e] != s[idx[3]][f+b-a])continue;
                  tmp = (e-1) * (b-a-1);
                  if(tmp > mx)mx = tmp;
                }
              }
            }
          }
        }
      }
    }while( next_permutation(idx, idx + 4) );
    printf("%d\n", mx);
  }
  return 0;
}
