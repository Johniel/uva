#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
  while(true){
    string in;
    getline(cin, in);
    if(cin.eof() == true)
      break;
    istringstream iss(in);
    string out;
    bool flg = true;
    while(iss >> out){
      //cout << "test00" << endl;
      reverse(out.begin(), out.end());
      if(flg == true){
	cout << out;
	flg = false;
	continue;
      }
      cout << ' '<< out ;
    }
    cout << endl;
  }
}
