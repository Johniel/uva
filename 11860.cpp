#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

const int W = 100000 + 2;

pair<int, int> solve(int no[], int size, int total)
{
  static int cnt[W];
  int r, l, contain, w;
  pair<int, int> p = make_pair(0, W);;
  fill(cnt, cnt + size, 0);
  r = l = contain = 0;
  while(r < size && l < size){
    for(; r < size; ){
      if(cnt[no[r]] == 0){
	++contain;
      }
      ++cnt[no[r]];
      if(contain == total)break;
      ++r;
    }
    for(; l < size; ++l){
      if(cnt[no[l]] == 1)break;
      --cnt[no[l]];
    }
    if(r < size && l < size && contain == total){
       if(p.second - p.first > r - l){
	p = make_pair(l, r);
      }
    }
    --cnt[no[l]];
    ++l;
    --contain;
    ++r;
  }  
  return p;
}

int main(void)
{
  int tc, doc = 0;  
  char buff[150 + 2];
  int no[W];
  scanf("%d\n", &tc);
  while(tc--){    
    int size = 0, cnt = 0;
    map<string, int> word;
    while(true){
      gets(buff);
      if(!strcmp(buff, "END")){
	break;
      }
      int lim = strlen(buff);
      buff[lim++] = '@';
      string t;
      for(int i=0; i<lim; ++i){
	if('a' <= buff[i] && buff[i] <= 'z'){
	  t += buff[i];
	}
	else{
	  if(t.size()){
	    map<string, int>::iterator itr;
	    itr = word.find(t);
	    if(itr == word.end()){
	      word[t] = no[size] = cnt++;
	    }
	    else no[size] = itr->second;
	    ++size;
	    t = "";
	  }
	}
      }  
    }
    pair<int, int> p = solve(no, size, cnt);
    printf("Document %d: %d %d\n", ++doc, p.first + 1, p.second + 1);
  }
  return 0;
}
