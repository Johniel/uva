#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const string digits[10] = { "YYYYYYN",//0
			    "NYYNNNN",//1
			    "YYNYYNY",//2
			    "YYYYNNY",//3
			    "NYYNNYY",//4
			    "YNYYNYY",//5
			    "YNYYYYY",//6
			    "YYYNNNN",//7
			    "YYYYYYY",//8
			    "YYYYNYY"};//9

void replace(vector<string> &input)
{
  for(int j=0; j<7; j++){
    for(int i=0; i<input.size(); i++){
      if( input[i][j] == 'N')
	input[i][j] = '*';
      else 
	break;
    }
  }
  //for(int i=0; i<input.size();i++)cout << input[i] << endl ;cout << endl;
}

bool Dmatch(string in, int num)
{
  for(int i=0; i<in.size(); i++){
    if( in[i] == '*' )
      continue;
    else if( in[i] == digits[num][i] )
      continue;
    else
      return false;
  }
  return true;
}

string match(vector<string> &input)
{
  for(int i=0; i<10; i++){
    bool flg = true;
    for(int j=i; j<i+input.size() && flg ; j++){
      //cout <<  j << endl;
      if( j >= 10 )  return "MISMATCH";
	
      flg = Dmatch(input[j-i], j);
    }
    if( flg == true)
      return "MATCH";
  }
  return "MISMATCH";
}

string compute(vector<string> &input)
{
  replace(input);
  return match(input);
}

int main(void)
{
  int n;
  while( cin >> n && n ){
    vector<string> input;
    string in;
    for(int i=0; i<n; i++){
      cin >> in;
      input.push_back(in);
    }
    reverse( input.begin(),input.end() );
    cout << compute(input) << endl;
  }
  return 0;
}


