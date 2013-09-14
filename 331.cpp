#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef struct{
  vector<int> array;
  int cnt;
}state;

int main(void)
{
  int n, sets = 0;
  while( cin >> n && n ){
    sets++;
    vector<int> tmp, ans;
    queue<state> que;
    set< vector<int> > past;
    state input;

    tmp.resize(n);
    for(int i=0; i<n; i++)
      cin >> tmp[i] ;
    ans = tmp;
    sort(ans.begin(), ans.end());
    input.cnt = 0;
    input.array = tmp;
    que.push(input);
    past.insert(tmp);
    int flg = INT_MAX;
    int num = 0;
    if( tmp != ans)
    while( !que.empty() ){
      input = que.front();
      que.pop();
      //for(int i=0; i<n; i++)cout << input.array[i] << ' ' ; cout << "input.cnt = " << input.cnt << endl;
      if( input.array == ans ){
	//cout << "HIT!" << endl; 
	if( num == 0 )flg = input.cnt;
	if( flg == input.cnt )num++;
	past.erase(input.array);
      }
      else{
	//for(int i=0; i<n-1; i++){
	  for(int j=0; j<n-1; j++){
	    //for(int i=0; i<n; i++)cout << input.array[i] << ' ' ;cout << "--->> ";
	    swap(input.array[j], input.array[j+1]);
	    //for(int i=0; i<n; i++)cout << input.array[i] << ' ' ;cout << endl;
	    //if( past.count(input.array) - 1 ){
	      if( input.cnt+1 <= flg){
		input.cnt++;
		que.push(input);
		if( input.array != ans )past.insert(input.array);
		input.cnt--;
	      }
	      //}
	    swap(input.array[j], input.array[j+1]);
	  }
	  //}
      }
    }
    cout << "There are " << num << " swap maps for input data set " << sets << "." << endl;
  }
  return 0;
}
