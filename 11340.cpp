#include <iostream>
#include <map>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while( n-- ){
    map<char,int> value;
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
      pair<char,int> input;
      cin >> input.first;
      cin >> input.second;
      value.insert(input);
    }

    cin >> num;
    int result = 0;
    char in[10001];
    gets(in);
    for(int i=0; i<num; i++){
      gets(in);
      for(int j=0; in[j] != '\0' ; j++){
	result += value[in[j]];
      }
    }
    /*
    for(int i=0; i<num+1; i++){
      string in;
      getline(cin, in);
      for(int j=0; j<in.size(); j++){
	result += value[in[j]];
      }
    }
    */
    /*
    char in;
    while( cin >> in ){
      result += value[in];
    }
    */
    printf("%.2f$\n",(float)result/100);
  }
  return 0;
}
