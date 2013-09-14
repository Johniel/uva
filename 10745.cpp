#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int C = 'z' + 1;
const int S = 10 + 1;

class Item{
public:
  int cnt[C];
  char t[S], u[S];
  bool valid;
  Item(){
    valid = false;
    fill(cnt, cnt + C, 0);
  }
  void asign(char s[]){
    char c[] = "z\n";
    ++c[0];
    int size = strlen(s);
    for(int i=0; i<size; ++i){
      ++cnt[s[i]];
      u[i] = s[i];
      t[i] = s[i];
    }
    sort(u, u + size);
    strcat(u, c);
    return ;
  }
  bool include(Item i){
    bool flg = true;
    for(char c='a'; flg && c<='z'; ++c){
      flg &= cnt[c] >= i.cnt[c];
    }
    return flg;
  }
};
bool operator < (const Item &a, const Item &b)
{
  return strcmp(a.u, b.u) < 0;
}

bool cmp(const Item &a, const Item &b)
{
  return strcmp(a.t, b.t) < 0;
}

int main(void)
{
  const int I = 15000 + 1;
  Item item[I];
  int size = 0;  
  for(char s[S]; scanf("%s", s) == 1; item[size++].asign(s));
  for(int i=0; i<size; ++i)item[i].valid = true;
  sort(item, item + size); 

  //for(int i=0; i<size; ++i)puts(item[i].u);

  for(int i=0; i<size; ++i){
    if(!item[i].valid)continue;
    for(int j=i+1; j<size; ++j){
      if(!item[j].valid)continue;
      if(item[i].include(item[j]))item[j].valid = false;
    }
  }
  sort(item, item + size, cmp);
  for(int i=0; i<size; ++i){
    if(item[i].valid)puts(item[i].t);
  }
  return 0;
}
