#include <iostream>

using namespace std;

int main(void)
{
  const int sleep = 0, warm = 1, run = 2;
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    int query, stiff, wait, ignored = 0, inactive = 0, time = 0;
    int state = run;
    cin >> query >> wait >> stiff;
    //cin >> query >> stiff >> wait;
    for(int i=0, m; i<query; ++i){
      cin >> m;
      while(true){
	//cout << i << " : " << time << ' ' << state << ' ' << m << endl;
	if(time > m){
	  ++ignored;
	  break;
	}
	if(state == sleep){
	  time = m + stiff;
	  state = run;
	  ++inactive;
	  break;
	}
	else if(state == run){
	  if(m > time + wait){
	    state = sleep;
	    time += wait;
	  }
	  else{
	    time = m;
	    break;
	  }
	}
      }
    }
    cout << "Case " << ++cnt << ": " << inactive << ' ' << ignored << endl;
  }
  return 0;
}
