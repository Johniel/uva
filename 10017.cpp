#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

const int N = 250 + 1;

list<int> l[3];

void output(void)
{
  puts("");
  for(int j=0; j<3; ++j){    
    printf("%c=>", 'A' + j);
    if(l[j].size()){
      printf("   ");
      for(list<int>::iterator i=l[j].begin(); i!=l[j].end(); ++i){
        if(i != l[j].begin())printf(" ");
        printf("%d", *i);
      }
    }
    puts("");
  }
  return ;
}

int cnt;
bool hanoi(int n, int m, list<int> &x, list<int> &y, list<int> &z)
{
  if(n){
    if(hanoi(n-1, m, x, z, y))return true;
    output();
    y.push_back(x.back());
    x.pop_back();
    if(cnt++ == m)return true;
    if(hanoi(n-1, m, z, y, x))return true;
  }
  return false;
}
/*
hanoi(n, A, B, C)
   if 0 < n then
      hanoi(n-1, A, C, B)
      print "Disk" n " is moved to " B " from " A   
      hanoi(n-1, C, B, A)
   end
end
*/

int main(void)
{
  int n, m, tc = 0;
  while(cin >> n >> m && (n | m)){
    cnt = 0;
    l[0] = l[1] = l[2] = list<int>();
    for(int i=0; i<n; ++i){
      l[0].push_front(i+1);
    }
    printf("Problem #%d\n", ++tc);
    hanoi(n, m, l[0], l[2], l[1]);
    while(cnt++ - 1 < m)output();
    puts("");
  }
  return 0;
}
