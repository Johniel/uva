#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

bool *used;
string in;
char *re;
vector<string> rem;

void display(int p)
{
  if(p == in.size()){
    string tmp;
    REP(i, in.size())
      tmp += re[i];
    rem.push_back(tmp);
  }
  REP(i, in.size()){
    if(used[i] == false){
      used[i] = true;
      re[p] =  in[i];
      display(p + 1);
      used[i] = false;
    }
  }
}

bool cmp(const char& a, const char& b)
{
  if(toupper(a) == toupper(b))
    return a < b;
  return toupper(a) <  toupper(b);
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    cin >> in;
    used = new bool[in.size()];
    re = new char[in.size()];
    fill(used, used + in.size(), false);
    sort(ALL(in), cmp);
    display(0);
    string empty;
    rem.push_back(empty);
    REP(i, rem.size()-1){
      if(rem[i] == rem[i+1]);
      else{ cout << rem[i];if(rem[i].size())cout << endl;}
    }
  }
  return 0;
}
