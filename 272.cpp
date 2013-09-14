#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  bool flg = true;
  while(true){
    char in;
    cin.get(in);
    if(cin.eof() == true)
      break;
    if( in == '"' ){
      if( flg == true){
	cout << "``" ;
	flg = false;
      }
      else{
	cout << "''" ;
	flg = true;
      }
    }
    else
      cout << in;
  }
  return 0;
}
