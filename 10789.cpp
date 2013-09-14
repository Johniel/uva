#include <iostream>

using namespace std;

int main(void)
{
  int tc = 0;
  while(true){
    int cnt['z'+1];
    fill(cnt, cnt+'z+1', 0);
    string in;
    getlinr(cin, in);
    for(int i=0; i<in.size(); i++){
      cnt[in[i]]++;
    }
    for(int i=0; i<'z'+1; i++){
      if(cnt[i])
	cout << (char)i;
    }
    cout << endl;
  }
  return 0;
}
