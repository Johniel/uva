#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string num[10][5] = {{"#-#",
                      "| |",
                      "# #",
                      "| |",
                      "#-#"},

                     {" ##",
                      " #|", 
                      " ##",
                      " #|",
                      " ##"},	
	  
                     {"#-#",
                      "# |",
                      "#-#",
                      "| #",
                      "#-#"},	
	  
                     {"#-#",
                      "# |",
                      "#-#",
                      "# |",
                      "#-#"},	
	  
                     {"# #",
                      "| |",
                      "#-#",
                      "# |",
                      "# #"},	
	  
                     {"#-#",
                      "| #",
                      "#-#",
                      "# |",
                      "#-#"},
		  
                     {"#-#",
                      "| #",
                      "#-#",
                      "| |",
                      "#-#"},	
	  
                     {"#-#",
                      "# |",
                      "# #",
                      "# |",
                      "# #"},		  

                     {"#-#",
                      "| |",
                      "#-#",
                      "| |",
                      "#-#"},		  

                     {"#-#",
                      "| |",
                      "#-#",
                      "# |",
                      "#-#"}};

void output(vector<string> v)
{
  for(int i=0; i<v.size(); ++i){
    for(int j=0; j<v[i].size(); ++j){
      if(v[i][j] == '@' || v[i][j] == '#' || v[i][j] == '$')v[i][j] = ' ';
      cout << v[i][j];
    }
    cout << endl;
  }  
  return ;
}

void build(vector<string> v, int n)
{
  vector<string> u;
  for(int i=0; i<v.size(); ++i){
    int a = count( v[i].begin(), v[i].end(), '-' );
    int b = count( v[i].begin(), v[i].end(), '|' );
    if(a || a+b == 0){
      string s;
      for(int j=0; j<v[i].size(); ++j){
        if(v[i][j] == '#')s += '#';
        else s += string(n, v[i][j]);
      }
      u.push_back(s);
    }
    else if(b){
      string s;
      for(int j=0; j<v[i].size(); ++j){
        if(v[i][j] == '@') s += string(n, v[i][j]);
        else s += v[i][j];
      }
      for(int j=0; j<n; ++j){
        u.push_back(s);
      }
    }    
  }
  output(u);
  return ;
}

int main(void)
{
  int size; 
  string s;
  for(int i=0; i<10; ++i){
    for(int j=0; j<5; ++j){
      for(int k=0; k<num[i][j].size(); ++k){
        if(num[i][j][k] == ' ')num[i][j][k] = '@';
      }
    }
  }
  while(cin >> size >> s){
    if(size == 0 && s == "0")break;
    vector<string> v(5);
    for(int i=0; i<5; ++i){
      for(int j=0; j<s.size(); ++j){
        if(j)v[i] += '#';
        v[i] += num[ s[j] - '0' ][i];
      }
    }
    build(v, size);
    cout << "" << endl;
  }
  return 0;
}
