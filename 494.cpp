#include <iostream>

using namespace std;

int main(void)
{
  while(true){
    string in;
    getline(cin, in);
    if(cin.eof() == true)
      break;
    for(int i=0; i<in.size(); i++){
      //cout << in << ' ' << in.size() << ' ' << i << endl;
      if(isalpha(in[i]) || in[i] == ' ')
	continue;
      in[i] = ' ';
    }
    //cout << in << endl;
    for(int i=0; i<in.size()-1; i++){
      if(in[i] == in[i+1] && in[i] == ' '){
	in.erase(i, 1);
	i--;
      }
    }
    while(in[0] == ' ')in.erase(0, 1);
    while(in[in.size()-1] == ' ')in.erase(in.size()-1, 1);
    //cout << in << endl;
    cout << count(in.begin(), in.end(), ' ') + 1 << endl;
  }
}
