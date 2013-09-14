#include <iostream>

#include <map>
#define REP(i, n) for(int i=0; i<(int)n; i++)
using namespace std;
map<char, char> rem;
bool pd(string in)
{
  REP(i, in.size())
    if(in[i] == '0')
      in[i] = 'O';
  REP(i, in.size())
    if(in[i] != in[in.size() - i - 1])
      return false;
  return true;
}

bool ms(string in)
{
  REP(i, in.size())
    if(in[i] == '0')
      in[i] = 'O';
  REP(i, in.size())
    if(in[in.size() - i - 1] != rem[in[i]] )
      return false;
  return true;
}

int main(void)
{
  rem.insert( make_pair('A', 'A') );
  rem.insert( make_pair('E', '3') );
  rem.insert( make_pair('3', 'E') );
  rem.insert( make_pair('H', 'H') );
  rem.insert( make_pair('I', 'I') );
  rem.insert( make_pair('J', 'L') );
  rem.insert( make_pair('L', 'J') );
  rem.insert( make_pair('M', 'M') );
  rem.insert( make_pair('O', 'O') );
  rem.insert( make_pair('S', '2') );
  rem.insert( make_pair('2', 'S') );
  rem.insert( make_pair('T', 'T') );
  rem.insert( make_pair('U', 'U') );
  rem.insert( make_pair('V', 'V') );
  rem.insert( make_pair('W', 'W') );
  rem.insert( make_pair('X', 'X') );
  rem.insert( make_pair('Y', 'Y') );
  rem.insert( make_pair('Z', '5') );
  rem.insert( make_pair('5', 'Z') );
  rem.insert( make_pair('8', '8') );
  rem.insert( make_pair(' ', ' ') );
  rem.insert( make_pair('1', '1') );
  while(true){
    string in;
    //getline(cin, in);
    cin >> in;
    if(cin.eof())
      break;  
    bool p = pd(in);
    bool m = ms(in);
    if(p == m){
      if(p)
	cout << in <<" -- is a mirrored palindrome."  << endl;
      else
	cout << in <<" -- is not a palindrome."  << endl;
    }
    else if(p)
      cout << in <<" -- is a regular palindrome." << endl;
    else
      cout << in <<" -- is a mirrored string." << endl;
    cout << endl;
  }
  return 0;
}
