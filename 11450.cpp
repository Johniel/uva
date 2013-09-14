#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    int num, c, limit;
    bool m[20][201];
    fill(&m[0][0], &m[19][201], false);
    cin >> limit >> num;
    for(int i=0; i<num; i++){
      cin >> c;
      for(int j=0; j<c; j++){
	int in;
	cin >> in;
	if( i != 0 ){
	  for(int k=0; k<=200; k++){
	    if( m[i-1][k] == true ){
	      if( k+in <= 200 ){
		m[i][k+in] = true;
		//cout << k+in << endl;
	      }
	    }
	  }
	}
	else{
	  m[0][in] = true;
	}
      }
    }
    //cout << count(&m[num-1][0], &m[num-1][limit], true) << endl;
    int re = INT_MIN;
    //for(int j=num-1; j>=0; j--){
      for(int i=limit; i>=0; i--){
	if( m[num-1][i] == true ){
	  re = max( re, i);
	  break;
	}
      }
      //}
    if( re != INT_MIN)
      cout << re << endl;
    else
      cout << "no solution" << endl;
  }
  return 0;
}
