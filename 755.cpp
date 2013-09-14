//do not use string and cin

#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

class data{
public:
  char str[9];
  bool operator < (const data &in)const{
    REP(i, 7){
      if(str[i] < in.str[i])
	return true;
      else if(str[i] > in.str[i])
	return false;
    }
    return false;
  }
};

map<char, int> rem;

void initiarize(void)
{
  rem.insert( make_pair('A', 2) );
  rem.insert( make_pair('B', 2) );
  rem.insert( make_pair('C', 2) );
  rem.insert( make_pair('D', 3) );
  rem.insert( make_pair('E', 3) );
  rem.insert( make_pair('F', 3) );
  rem.insert( make_pair('G', 4) );
  rem.insert( make_pair('H', 4) );
  rem.insert( make_pair('I', 4) );
  rem.insert( make_pair('J', 5) );
  rem.insert( make_pair('K', 5) );
  rem.insert( make_pair('L', 5) );
  rem.insert( make_pair('M', 6) );
  rem.insert( make_pair('N', 6) );
  rem.insert( make_pair('O', 6) );
  rem.insert( make_pair('P', 7) );
  rem.insert( make_pair('R', 7) );
  rem.insert( make_pair('S', 7) );
  rem.insert( make_pair('T', 8) );
  rem.insert( make_pair('U', 8) );
  rem.insert( make_pair('V', 8) );
  rem.insert( make_pair('W', 9) );
  rem.insert( make_pair('X', 9) );
  rem.insert( make_pair('Y', 9) );
  return ;
}

int main(void)
{
  initiarize();
  int tc;
  scanf("%d", &tc);
  //cout << "tesdt02" << endl;
  while(tc--){
    map<data, int> result;
    int num;
    scanf("%d", &num);
    REP(i, num){
      char c[100];
      //cout << "test01" << endl;
      scanf("%s", c);
      data in;
      in.str[7] = '-';
      int p = 0;
      int len = strlen(c);
      //cout << len << endl;
      for(int j=0; j<len && p < 8; j++){
	if(isdigit(c[j]))
	  in.str[p++] = c[j];
	else if(isalpha(c[j]))
	  in.str[p++] = ('0' + rem[c[j]]);
      }
      //cout << in.str << ' ' << p << endl;
      if(p == 7 && in.str[7] == '-'){
	if(result.count(in))
	  result[in]++;
	else
	  result.insert( make_pair(in, 1) );
      }
    }
    //cout << result.size()<< endl;
    //cout << "test00" << endl;
    bool flg = true;
    map<data, int> :: iterator itr;
    for(itr = result.begin(); itr != result.end(); itr++){
      //REP(i, 7)printf("%c", (*itr).first.str[i]);cout << endl; 
      if((*itr).second == 1)continue;
      REP(i, 3)printf("%c", (*itr).first.str[i]);
      printf("-");
      REP(i, 4)printf("%c", (*itr).first.str[i+3]);
      printf(" %d\n", (*itr).second);
      flg = false;
    }
    if(flg)cout << "No duplicates."<< endl;
    if(tc)cout << endl;
  }
  return 0;
}
