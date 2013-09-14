//adhoc
#include <iostream>
#include <sstream>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; i++)

using namespace std;

int n = 5;
string ay = "aeiou";

bool check1(string s)
{
  REP(i, n){
    if(s[0] == ay[i] || s[0] == toupper(s[i]))
      return true;
  }
  return false;
}

bool check2(string s)
{
  REP(i, n){
    if(s[0] == ay[i] || s[0] == toupper(ay[i]))
      return false;
  }
  return true;
}

int main(void)
{
  while(true){
    string in;
    getline(cin, in);
    if(cin.eof())
      break;
    vector<string> re(1);
    REP(i, in.size()){
      if(isalpha(in[i])){
	re[re.size()-1] += in[i];
      }
      else{
	re.resize(re.size() + 2);
	re[re.size()-2] += in[i];
      }
    }
    //REP(i, re.size())cout << re[i] << endl;
    REP(i, re.size()){
      if(isalpha(re[i][0])){
	string tmp = re[i];
	bool ayflg = check1(tmp);
	bool baflg = check2(tmp);
	if(baflg){
	  tmp += tmp[0];
	  tmp.erase(tmp.begin());
	}
	if(baflg || ayflg)
	  tmp += "ay";
	cout << tmp;
      }
      else
	cout << re[i];
    }
    cout << endl;
  }
  return 0;
}
