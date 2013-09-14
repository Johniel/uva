
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Length 60

void display(vector<string>& output)
{
  cout << "------------------------------------------------------------" << endl
;
  for(int i=0; i<output.size(); i++){
    //for(int j=output[i].size()-1; output[i][j] == ' '; j--)output[i].erase(j, 1);
    cout << output[i] << endl;
  }
  return ;
}

bool make(vector<string>& input, vector<string>& output , int len, int size)
{
  output.resize( (input.size()+len-1) / len );
  for(int i=0; i<output.size(); i++){
    for(int j=i; j<input.size(); j+=output.size()){
      output[i] += input[j];
      for(int k=0; k<size+2-input[j].size(); k++)
        output[i] += ' ';
    }
  }
  bool flg = true;
  for(int i=0; i<output.size() && flg ; i++){
    if( output[i].size() > Length )
      flg = false;
  }
  return flg;
}

void compute(vector<string>& input, int space)
{
  int len;
  for(int i=20; i>0; i--){
    vector<string> output;
    if( make(input, output, i, space) == true ){
      display(output);
      return ;
    }
  }
  return;
}

int main(void)
{
  int n;
  while( cin >> n && n){
    vector<string> input;
    int len_max = INT_MIN;
    while(n--){
      string in;
      cin >> in;
      len_max = max(len_max , (int)in.size());
      input.push_back(in);
    }
    sort(input.begin(), input.end());
    compute(input,len_max);
  }
  return 0;
}
