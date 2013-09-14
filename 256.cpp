#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

int pow10(int n)
{
  int m = 1;
  while(n--)m *= 10; 
  return m;
}

int main(void)
{
  for(int n; cin >> n; ){
    if(n == 2){
      cout << "00" << endl;
      cout << "01" << endl;
      cout << "81" << endl;
    }
    else if(n == 4){
      cout << "0000" << endl;
      cout << "0001" << endl;
      cout << "2025" << endl;
      cout << "3025" << endl;
      cout << "9801" << endl;
    }
    else if(n == 6){
      cout << "000000" << endl;
      cout << "000001" << endl;
      cout << "088209" << endl;
      cout << "494209" << endl;
      cout << "998001" << endl;
    }
    else{
      cout << "00000000" << endl;
      cout << "00000001" << endl;
      cout << "04941729" << endl;
      cout << "07441984" << endl;
      cout << "24502500" << endl;
      cout << "25502500" << endl;
      cout << "52881984" << endl;
      cout << "60481729" << endl;
      cout << "99980001" << endl;
    }
  }
  return 0;
  char buff[10];
  for(int k=2; k<=8; k+=2){
    int lim = pow10(k/2);
    sprintf(buff, "0%d", k/2);
    string f(buff);
    f = "%" + f + "d";
    cout << f << endl;
    for(int i=0; i<lim; ++i){
      for(int j=0; j<lim; ++j){
        sprintf(buff, f.c_str(), i);
        string a(buff);
        sprintf(buff, f.c_str(), j);
        string b(buff);
        string c = a + b;
        if( atoi(c.c_str()) == (i + j) * (i + j) ){
          cout << c << endl;
        }
      }
    }
  }
  return 0;
}
