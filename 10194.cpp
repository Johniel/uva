#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Team{
public:
  string name;
  int win, even, lose, goal, against;
  Team(){}
  Team(string n){
    win = even = lose = goal = against = 0;
    name = n;
  }
  string getStatistics(void){
    char s[256];
    sprintf(s, "%s %dp, %dg (%d-%d-%d), %dgd (%d-%d)", 
	    name.c_str(), 
	    calcPoint(), 
	    totalGame(),
	    win, 
	    even, 
	    lose, 
	    calcGD(), 
	    goal, 
	    against);
    return string(s);
  }
  int calcPoint(void) const {
    return win * 3 + even;
  }
  int calcGD(void) const {
    return goal - against; 
  }
  int totalGame(void) const {
    return win + lose + even;
  }
  bool operator < (const Team &t) const {
    if(calcPoint() != t.calcPoint())
      return calcPoint() > t.calcPoint();
    if(win != t.win)
      return win > t.win;
    if(calcGD() != t.calcGD())
      return calcGD() > t.calcGD();
    if(goal != t.goal)
      return goal > t.goal;
    if(totalGame() != t.totalGame())
      return totalGame() < t.totalGame();    
    return lexCmp(name, t.name);
    return name < t.name;
  }
  bool lexCmp(string a, string b) const {
    int lim = min(a.size(), b.size());
    for(int i=0; i<lim; ++i){
      if(toupper(a[i]) != toupper(b[i]))
	return toupper(a[i]) < toupper(b[i]);      
    }
    return a < b;
  }
};

int main(void)
{
 const int N = 30 + 1;
 int tc, team, game;
 string s, t, u, team1, team2;
 Team T[N];
 cin >> tc;
 cin.ignore();
 for(int cnt = 0; tc--; cnt = 0){
   map<string, int> M;
   getline(cin, s);
   cout << s << endl;
   cin >> team;
   cin.ignore();
   for(int i=0; i<team; ++i){
     getline(cin, s);
     ++cnt;
     M[s] = cnt;
     T[cnt] = Team(s);
   }
   cin >> game;
   cin.ignore();
   for(int i=0; i<game; ++i){
     getline(cin, s);
     int j = 0, score1, score2, tmp = 0, id1, id2;
     for(; s[j] != '#'; ++j);
     team1 = s.substr(tmp, j - tmp);
     tmp = j + 1;
     for(; s[j] != '@'; ++j);
     score1 = atoi(s.substr(tmp, j - tmp).c_str());
     tmp = j + 1;
     for(; s[j] != '#'; ++j);
     score2 = atoi(s.substr(tmp, j - tmp).c_str());
     tmp = j + 1;
     team2 = s.substr(tmp, (int)s.size() - tmp);
     id1 = M[team1];
     id2 = M[team2];
     if(score1 < score2){
       ++T[id1].lose;
       ++T[id2].win;
     }
     else if(score1 > score2){
       ++T[id1].win;
       ++T[id2].lose;
     }
     else{
       ++T[id1].even;
       ++T[id2].even;
     } 
     T[id1].goal += score1;
     T[id1].against += score2; 
     T[id2].goal += score2;
     T[id2].against += score1;
   }
   stable_sort(T + 1, T + team + 1);
   for(int i=0 + 1; i<team + 1; ++i)
     cout << i << ") " << T[i].getStatistics() << endl;
   if(tc)cout << endl;
 }  
 return 0;
}
