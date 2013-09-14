#include <iostream>

using namespace std;

string compute(string in)
{
  int p;
  //cout << in << endl;
  while( count(&in[0], &in[in.size()], '&') ){
    p = 0;
    cout << in << endl;
    for(int i=0; i<in.size(); i++){
      if( in[i] == '|' )
	p = i+1;
      else if( in[i] == '&' ){
	if( in[p] == '~' || in[i+1] == '~'){
	  if(in[p] == '~' && in[i+1] == '~' )
	    in.erase(p,5);
	  else 
	    in.erase(p,4);
	  in.insert(p,"~a");
	}
	else{
	  in.erase(p,3);
	  in.insert(p,"a");
	}
	break;
      }
    }
  }
  //cout << in << endl;
  while( count(&in[0], &in[in.size()], '|') ){
    cout << in << endl;
    p = 0;
    for(int i=0; in.size(); i++){
      if( in[i] == '|' ){
	if( i == 2 && in[i+1] == '~' ){
	  in.erase(0,5);
	  in.insert(0,"~a");
	}
	else{
	  if( i==2 || in[i+1] == '~')in.erase(0,4);
	  else in.erase(0,3);
	  in.insert(0,"a"); 
	  //cout << "test : " << in << endl;
	}
	break;
      }
    }
  }
  cout << in << endl;
  return in;
}

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    string in;
    //getline(cin, in);
    cin >> in ;
    //cout << in << endl;
    while( count(&in[0], &in[in.size()], '(' )  != 0){
      int p;
      string tmp;
      for(int i=0; i<in.size(); i++){
	if( in[i] == '(' )
	  p = i;
	else if( in[i] == ')' ){
	  tmp = compute( in.substr(p+1,i-p-1) );
	  in.erase(p,i-p+1);
	  in.insert(p,tmp);
	  //cout << in << endl;
	  break;
	}
      }
    }
    //cout << in << endl;
    string tmp= compute( in );
    if( tmp.size() == 1 )
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
