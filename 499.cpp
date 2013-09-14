#include <iostream>

using namespace std;

static const int N = (int)'z' + 1;

int main(void)
{
  while(true){
    string in;
    getline(cin, in);
    //cout << in << endl;
    if(cin.eof() == true)
      break;
    int cnt[N];
    int tmp = 0;
    fill(cnt, cnt+N, 0);
    //cout << in.size() << endl;
    for(int i=0; i<in.size(); i++){
      //if(isalpha(in[i])) cout << 222 << endl;
      if(isalpha(in[i])){
	cnt[(int)in[i]]++;
	tmp = max(tmp, cnt[in[i]]);
      }
    }
    for(int i=0; i<N; i++){
      //if(isalpha((char)i))cout << cnt[i] << ' ';;
      if(isalpha((char)i) && cnt[i] == tmp){
	cout << (char)i ;
      }
    }
    cout << ' ' << tmp << endl;
  }
  return 0;
}
