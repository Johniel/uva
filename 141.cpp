#include <iostream>
#include <algorithm>
#include <set>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

typedef set< pair<int, int> > State;  

bool operator < (State a, State b)
{
  a.insert(make_pair(-1, -1));
  b.insert(make_pair(-1, -1));
  State::iterator i = a.begin();  
  State::iterator j = b.begin();  
  for(; i != a.end() && j != b.end(); ++i, ++j){
    if(*i != *j){
      return *i < *j;
    }
  }
  return false;
}

State rot90(State s, int n)
{
  State t;
  FOR(i, s){
    t.insert(make_pair(n - i->second, i->first));    
  }  
  return t;
}

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    State state;
    set<State> visited;
    bool flg = false;
    visited.insert(state);
    for(int i=0; i<2*n; ++i){
      int h, w;
      char c;
      cin >> h >> w >> c;
      if(flg)continue;
      --h, --w;
      if(c == '+'){
	state.insert(make_pair(h, w));
      }
      else{
	state.erase(make_pair(h, w));
      }      
      State s = state;
      for(int j=0; j<3; ++j){
	State t = rot90(s, n);
	if(visited.count(t)){
	  flg = true;
	  cout << "Player " << 2-i%2 << " wins on move " << i+1 << endl;
	  break;
	}
	else visited.insert(t);
	s = t;
      }
    }
    if(!flg){
      cout << "Draw" << endl;
    }
  }
  return 0;
}
