#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void)
{
  while(true){
    int n;
    string s;
    cin >> s;
    if(s[0] == '-')break;
    if(s[0] == '0'){
      istringstream iss(s);
      iss.setf( std::ios::hex, std::ios::basefield );
      iss.setf( std::ios::uppercase);
      iss >> n;
      cout << n << endl;
    }
    else{
      istringstream iss(s);
      iss >> n;
      cout.setf( std::ios::hex, std::ios::basefield );
      cout.setf( std::ios::uppercase);
      cout << "0x" << n << endl;
      cout.unsetf( std::ios::showbase );
      cout.unsetf( std::ios::hex );
    }
  }
  return 0;
}
