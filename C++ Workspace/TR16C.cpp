#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        set< pair< pair<int, int>, pair<int, int> > > seen;
        string s;
        cin >> s;
        int curX = 0;
        int curY = 0;
        int time = 0;
        for(int i = 0; i < s.length(); i++){
            int newX = curX;
            int newY = curY;
            if(s[i] == 'N'){
                newY++;
            }
            else if(s[i] == 'S'){
                newY--;
            }
            else if(s[i] == 'E'){
                newX++;
            }
            else{
                newX--;
            }
            //cout << newX << " " << newY << endl;
            if(seen.count(make_pair(make_pair(newX,newY), make_pair(curX,curY))) != 0 || seen.count(make_pair(make_pair(curX,curY), make_pair(newX, newY))) != 0){
                time += 1;
            }
            else{
                time += 5;

            }
            seen.insert(make_pair(make_pair(newX,newY), make_pair(curX,curY)));
            curX = newX;
            curY = newY;
        }
        cout << time << endl;
    }


}

