#include <iostream>
#include <algorithm>

using namespace std;
 
void r1(string &s)
{  
  char tmp = s[0];  
  s[0] = s[4];  
  s[4] = s[5];  
  s[5] = s[1];  
  s[1] = tmp;   
} 

void r2(string &s)  
{  
  char tmp = s[4];  
  s[4] = s[3];  
  s[3] = s[1];  
  s[1] = s[2];  
  s[2] = tmp;  
}  

void r3(string &s)  
{  
  char tmp = s[0];  
  s[0] = s[2];
  s[2] = s[5];  
  s[5] = s[3];  
  s[3] = tmp;  
}  
 
int main(void)
{
  string s;  
  while(cin >> s){
    string a, b;
    for(int i=0; i<6; ++i){
      a += s[i];
    }
    for(int i=6; i<12; ++i){
      b += s[i];
    }
    bool flg = a == b;
    string tmp = a;

    a = tmp;
    for(int i=0; i<4 && !flg; ++i){
      r1(a);  
      flg = a == b;
      for(int j=0; j<4 && !flg; ++j){
        r2(a); 
        flg = a == b; 
      }
    }
    a = tmp;
    for(int i=0; i<4 && !flg; ++i){
      r2(a);  
      flg = a == b;
      for(int j=0; j<4 && !flg; ++j){
        r3(a);  
        flg = a == b; 
      }  
    }  
    a = tmp;
    for(int i=0; i<4 && !flg; ++i){
      r1(a);  
      flg = a == b;
      for(int j=0; j<4 && !flg; ++j){
        r3(a);  
        flg = a == b; 
      }  
    }  
    
    cout << (flg ? "TRUE" : "FALSE") << endl;
  }
  return 0;
}
