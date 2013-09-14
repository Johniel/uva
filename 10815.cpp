#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
  vector<string> V;
  string s, in;
  while(true){
    cin >> s;
    if(cin.eof())break;
    for(int i=0; i<(int)s.size(); i++){
      if(isalpha(s[i]))s[i] = tolower(s[i]);
      else s[i] = ' ';
    }
    istringstream iss(s);
    while(iss >> in)
      V.push_back(in);
  }
  sort(V.begin(), V.end());
  if(V.size() > 0)cout << V[0] << endl;
  for(int i=1; i<(int)V.size(); i++)
    if(V[i-1] != V[i])cout << V[i] << endl;
  return 0;
}
