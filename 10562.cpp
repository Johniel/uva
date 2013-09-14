#include <iostream>
#include <algorithm>

using namespace std;

const int L = 200 + 1;

string tree[L];
int idx[L];

void find_node(int, int);

bool is_label(char c)
{
  return !(c == '|' || c == '-' || c == ' ');
}

void find_edge(int h)
{
  for(; idx[h]<tree[h].size(); ++idx[h]){
    if(tree[h][idx[h]] == '-'){
      for(; idx[h] < tree[h].size(); ++idx[h]){
	if(tree[h][idx[h]] == ' '){
	  break;
	}
      }
      find_node(h+1, idx[h]);
      return ;
    }
  }
  return ;
}

void find_node(int h, int lim)
{
  for(; idx[h] < lim && idx[h] < tree[h].size(); ++idx[h]){
    if(is_label(tree[h][idx[h]])){
      cout << tree[h][idx[h]] << '(' ;
      if(tree[h+1][idx[h]] == '|'){
	find_edge(h + 2);
      }
      cout << ')';
    }
  }
  return ;
}

int main(void)
{
  int tc;
  for(cin >> tc, cin.ignore(); tc--; ){
    int size = 0;
    for(int i=0; ; ++i){
      getline(cin, tree[i]);
      if(tree[i] == "#")break;
      ++size;
    }
    fill(idx, idx + size, 0);
    cout << '(';
    find_node(0, 1 << 20);
    cout << ')' << endl;
  }
  return 0;
}
