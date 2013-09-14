#include <iostream>
using namespace std;

bool bingo[5][5];
int call[75];
int card[5][5];

int check(void)
{
  for(int i=0; i<5; i++){
    bool flg = true;
    for(int j=0; j<5; j++){
      if( bingo[i][j] == false){
	flg = false;
	break;
      }
    }
    if( flg ){
      //cout << i << endl;
      return true;
    }
  }
  //cout << "test2" << endl;
  for(int i=0; i<5; i++){
    bool flg = true;
    for(int j=0; j<5; j++){
      if( bingo[j][i] == false){
	flg = false;
	break;
      }
    }
    if( flg )return true;
  }
  
  bool flg = true;
  for(int i=0; i<5; i++){
    if( bingo[i][i] == false ){
      flg = false;
      break;
    }
  }
  if( flg )return true;
  
  flg = true;
  for(int i=0; i<5; i++){
    if( bingo[4-i][i] == false ){
      flg = false;
      break;
    }
  }
  if( flg )return true;
  
  //cout << "test4" << endl;
   
  return false;
}

int main(void)
{
  int n;
  cin >> n;
  while(n--){
    int hit = -1;
    for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
	if( i != 2 || j != 2)
	  cin >> card[i][j];
	bingo[i][j] = false;
      }
    }
    card[2][2] = -1;
    bingo[2][2] = true;
    for(int i=0; i<75; i++){
      cin >> call[i];
      if( hit < 0 ){
	for(int j=0;j<5; j++){
	  for(int k=0; k<5;k++){
	    if( call[i] == card[j][k] ){
	      bingo[j][k] = true;
	      //cout << "test" << endl;
	    }
	  }
	}
      if( check() )hit = i;
      }
    }
    cout << "BINGO after " << hit+1 <<" numbers announced"<< endl;
    //cout << "test1" << endl;
  }
  return 0;
}
