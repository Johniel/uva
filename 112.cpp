#include <iostream>
#include <algorithm>

using namespace std;

string tree;
int idx;
int n;
int flg;

void compute(int sum)
{
  cout << "sum:"<<sum<<' '<<tree.substr(idx, tree.size()-idx)<<endl;  
  if(idx == tree.size())
    return ;
  while(true){
    if(tree[idx] == '(' || tree[idx] == ')')
      break;
    idx++;
  }
  int tmp = idx+1;
  while(true){
    if(tree[tmp] == '(' || tree[tmp] == ')')
      break;
    tmp++;
  }
  int re = atoi(tree.substr(idx+1, tmp - idx - 1).c_str());
  cout << "> "<< tree.substr(idx+1, tmp - idx - 1) << endl<<endl;
  if(tree[idx] == '(' && tree[tmp] == ')'){flg += 1;}
  idx = tmp;
  if(tree[idx] == '('){
    compute(sum+re);
    compute(sum+re);
  }
  else{return;idx++;}
}

int main(void)
{
  while(cin >> n){
    cin >> n;
    tree.clear();
    idx = flg = 0;
    cin >> tree ;
    while(count(tree.begin(), tree.end(), '(') != 
	  count(tree.begin(), tree.end(), ')')){
      string tmp;
      cin >> tmp;
      tree += tmp;
    }
    cout << tree << endl;
    for(int i=0; i<tree.size()-1; i++){
      if(tree[i] == '(' && tree[i+1] == ')'){
	i--;
	tree.erase(i+1,2);
      }
    }
    cout << tree << endl << endl;
    compute(0);
    if(flg)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
