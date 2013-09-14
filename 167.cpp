#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int result;
bool line[8], row[8], oblique1[8], oblique2[8];
multimap< int, pair<int, int> > num;

multimap< int, pair<int, int> > :: reverse_iterator itr;

void initialize(void)
{
  fill(&line[0], &line[8], true);
  fill(&row[0], &row[8], true);
  fill(&oblique1[0], &oblique1[8], true);
  fill(&oblique2[0], &oblique2[8], true);
}

void EightQueen(int n)
{
  if(n == 8){
    itr = num.rend();
    return;
  }
  while(itr != num.rend()){
    int scr = (*itr).first;
    int i = (*itr).second.first;
    int j = (*itr).second.second;
    cout << i << ' ' << j << ' ' << scr << ' ' << result << endl;
    if(line[i] && row[j] && oblique1[i+j] && oblique2[i-j+7]){
      line[i]  = false;
      row[j] = false;
      oblique1[i+j] = false; 
      oblique2[i-j+(8-1)] = false;
      result += scr;
      itr = num.rbegin();
      EightQueen(n+1);
    }
    itr++;
  }
}

int main(void)
{
  int n;
  cin >> n;
  while(n--){
    initialize();
    result = 0;
    num.clear();
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
	int m;
	cin >> m;
	pair<int, int> in = make_pair(i, j);
	num.insert(make_pair(m, in));
      }
    }
    itr = num.rbegin();
    EightQueen(0);
    cout << result << endl;
  }
  return 0;
}
