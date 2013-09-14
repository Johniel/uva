#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  bool result['Z'-'A'+1];
  fill(&result[0], &result['Z'-'A'-1], false);
  while(true){
    char c;
    cin >> c;
    if(c == '#')
      break;
    result[c-'A'] = true;
    cout << c << endl;
  }
  for(int i=0; i<='Z'-'A'; i++){
    if(result[i] == true)
      cout << (char)('A' + i);
  }
  cout << endl;
  return 0;
}
