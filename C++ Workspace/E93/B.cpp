#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        vector<int> streaks;
        int curr = 0;
        for(int i = 0; i  < s.length(); i++){
            if(s[i] == '1' && (i == 0 || s[i-1] == '1')){
                curr++;
            }
            else if(s[i] == '1'){
                curr = 1;
            }
            else{
                if(curr != 0){
                    streaks.pb(curr);
                }
                curr = 0;
            }
            if(i == (int)s.length()-1 && curr != 0){
                streaks.pb(curr);
            }
        }
        
        int alice = 0;
        int bob = 0;
        bool turn = true;
        sort(streaks.begin(), streaks.end());
        while(!streaks.empty()){
            //cout << streaks.back() << endl;
            if(turn){
                alice += streaks.back();
            }
            else{
                bob += streaks.back();
            }
            turn = !turn;
               
            streaks.pop_back();
        }
        cout << alice << endl;


    }


}

