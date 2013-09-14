#include <iostream>

using namespace std;

int main(void)
{
  int cnt = 0;
  while(cin){
    string in;
    string tmp;
    while( getline(cin,tmp) && tmp.size() != 0){
      in += '!';
      in += tmp;
    }
    if( cnt != 0)
      cout << endl;
    //cout << in << endl;
    int num = 0;
    for(int i=1; i<in.size() ;i++){
      if( isdigit( in[i]) )
	num += in[i] - '0';
      else if( in[i] == '!')
	cout << endl;
      else {
	for(int j=0; j<num; j++){
	  if( in[i] != 'b')
	    cout << in[i] ;
	else
	  cout << ' ';
	}
	num = 0;
      }
    }
    cnt++;
    cout << endl ;
  }
  return 0;
}
