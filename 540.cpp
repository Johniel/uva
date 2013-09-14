#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(void)
{
  int n, tc = 0, num, m;
  while(cin >> n && n){
    vector< queue<int> > q(1);
    map<int, int> team;
    for(int i=0; i<n; ++i){
      cin >> m;
      for(int j=0; j<m; ++j){
        cin >> num;
        team[num] = i;
        //cout << num << " : " << i << endl;
      }
    }    
    cout << "Scenario #" << ++tc << endl;
    while(true){
      //for(int i=0; i+1<q.size(); ++i)cout << "Front : " << q[i].front() << endl;

      string s;
      cin >> s;
      if(s == "STOP")break;
      if(s == "ENQUEUE"){
        cin >> num;
        for(int i=0; i<q.size(); ++i){
          if( q[i].empty() ){
            q[i].push( num );
            break;
          }
          if(team[num] == team[q[i].front()]){
            q[i].push( num );
            break;
          }
        }
      }
      if(s == "DEQUEUE"){
        cout << q[0].front() << endl;
        q[0].pop();
        if( q[0].empty() )q.erase( q.begin() );
      }      
      if(q.size() == 0 || !q.back().empty())q.push_back( queue<int>() );
    }
    cout << endl;
  }
  return 0;
}
