#include <iostream>

using namespace std;

const static int N = 1000001;

int main(void)
{
  
  while(true){
    int cnt[N];
    fill(cnt, cnt+N, 0);
    int n;
    cin >> n;
    if(cin.eof() == true)
      break;
    for(int i=0; i<n; i++){
      int tmp;
      cin >> tmp;
      cnt[tmp]++;
    }
    int num;
    cin >> num;
    
    int r, l;
    if(num%2 == 0){
      r = num/2;
      l = num/2;
    }
    else {
      l = num/2;
      r = l + 1;
    }
    while(true){
      if(cnt[r] != 0 && cnt[l] != 0){
	cout << "Peter should buy books whose prices are " << l << " and " << r << '.' << endl;
	break;
      }
      l--;
      r++;
    }
    cout << endl;
  }
  return 0;
}
