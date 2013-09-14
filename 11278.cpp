#include <iostream>
#include <map>

using namespace std;

map<char, char> keyboard;

void set_key_position(void)
{
 keyboard.insert( make_pair('`','`') );
  keyboard.insert( make_pair('1','1') );
  keyboard.insert( make_pair('2','2') );
  keyboard.insert( make_pair('3','3') );
  keyboard.insert( make_pair('4','q') );
  keyboard.insert( make_pair('5','j') );
  keyboard.insert( make_pair('6','l') );
  keyboard.insert( make_pair('7','m') );
  keyboard.insert( make_pair('8','f') );
  keyboard.insert( make_pair('9','p') );
  keyboard.insert( make_pair('0','/') );
  keyboard.insert( make_pair('-','[') );
  keyboard.insert( make_pair('=',']') );
  keyboard.insert( make_pair('q','4') );
  keyboard.insert( make_pair('w','5') );
  keyboard.insert( make_pair('e','6') );
  keyboard.insert( make_pair('r','.') );
  keyboard.insert( make_pair('t','o') );
  keyboard.insert( make_pair('y','r') );
  keyboard.insert( make_pair('u','s') );
  keyboard.insert( make_pair('i','u') );
  keyboard.insert( make_pair('o','y') );
  keyboard.insert( make_pair('p','b') );
  keyboard.insert( make_pair('[',';') );
  keyboard.insert( make_pair(']','=') );
  keyboard.insert( make_pair('\\','\\') );
  keyboard.insert( make_pair('a','7') );
  keyboard.insert( make_pair('s','8') );
  keyboard.insert( make_pair('d','9') );
  keyboard.insert( make_pair('f','a') );
  keyboard.insert( make_pair('g','e') );
  keyboard.insert( make_pair('h','h') );
  keyboard.insert( make_pair('j','t') );
  keyboard.insert( make_pair('k','d') );
  keyboard.insert( make_pair('l','c') );
  keyboard.insert( make_pair(';','k') );
  keyboard.insert( make_pair('\'','-') );
  keyboard.insert( make_pair('\n','\n') );
  keyboard.insert( make_pair('z','0') );
  keyboard.insert( make_pair('x','z') );
  keyboard.insert( make_pair('c','x') );
  keyboard.insert( make_pair('v',',') );
  keyboard.insert( make_pair('b','i') );
  keyboard.insert( make_pair('n','n') );
  keyboard.insert( make_pair('m','w') );
  keyboard.insert( make_pair(',','v') );
  keyboard.insert( make_pair('.','g') );
  keyboard.insert( make_pair('/','\'') );
  keyboard.insert( make_pair('~','~') );
  keyboard.insert( make_pair('!','!') );
  keyboard.insert( make_pair('@','@') );
  keyboard.insert( make_pair('#','#') );
  keyboard.insert( make_pair('$','Q') );
  keyboard.insert( make_pair('%','J') );
  keyboard.insert( make_pair('^','L') );
  keyboard.insert( make_pair('&','M') );
  keyboard.insert( make_pair('*','F') );
  keyboard.insert( make_pair('(','P') );
  keyboard.insert( make_pair(')','?') );
  keyboard.insert( make_pair('_','{') );
  keyboard.insert( make_pair('+','}') );
  keyboard.insert( make_pair('Q','$') );
  keyboard.insert( make_pair('W','%') );
  keyboard.insert( make_pair('E','^') );
  keyboard.insert( make_pair('R','>') );
  keyboard.insert( make_pair('T','O') );
  keyboard.insert( make_pair('Y','R') );
  keyboard.insert( make_pair('U','S') );
  keyboard.insert( make_pair('I','U') );
  keyboard.insert( make_pair('O','Y') );
  keyboard.insert( make_pair('P','B') );
  keyboard.insert( make_pair('{',':') );
  keyboard.insert( make_pair('}','+') );
  keyboard.insert( make_pair('|','|') );
  keyboard.insert( make_pair('A','&') );
  keyboard.insert( make_pair('S','*') );
  keyboard.insert( make_pair('D','(') );
  keyboard.insert( make_pair('F','A') );
  keyboard.insert( make_pair('G','E') );
  keyboard.insert( make_pair('H','H') );
  keyboard.insert( make_pair('J','T') );
  keyboard.insert( make_pair('K','D') );
  keyboard.insert( make_pair('L','C') );
  keyboard.insert( make_pair(':','K') );
  keyboard.insert( make_pair('"','_') );
  keyboard.insert( make_pair('Z',')') );
  keyboard.insert( make_pair('X','Z') );
  keyboard.insert( make_pair('C','X') );
  keyboard.insert( make_pair('V','<') );
  keyboard.insert( make_pair('B','I') );
  keyboard.insert( make_pair('N','N') );
  keyboard.insert( make_pair('M','W') );
  keyboard.insert( make_pair('<','V') );
  keyboard.insert( make_pair('>','G') );
  keyboard.insert( make_pair('?','"') );
  keyboard.insert( make_pair(' ',' ') );
  return ;
}

int main(void)
{
  set_key_position();
  //cout << keyboard.size() << endl;
  string s;
  while(true){//getline(cin, s)){

    getline(cin, s);
    if(cin.eof() == true)
      break;
    for(int i=0; i<s.size(); i++)
      cout << keyboard[s[i]];
    cout << endl;
  }
  return 0;
}
