#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int toBi(string s){
    int pow = 1;
    int num = 0;
    for(int i = s.length()-1; i >= 0; i --){
        if(s[i] == '1'){
            num +=pow;
        }
        pow *=2;
    }
    return num;
}
string toString(int x, int L){
    int mask = 1;
    string ans = "";
    for(int i = 0; i < L; i++){
        if((mask & x) >= 1){
            ans += "1";
        }
        else{
            ans += "0";
        }
        mask <<= 1; 
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, L;
    cin >> N >> L;
    string lights;
    cin >> lights;
    string pitch;
    cin >> pitch;
    pii dp[N+1][1 << L];
    for(int i = 0; i <= N; i++){
        for(int j =0; j < 1 << L; j++){
            dp[i][j] = make_pair(10000, 10000);
        }
    }
    //cuut << toBi(lights.substr(0,L)) << endl;
    dp[L-1][toBi(lights.substr(0, L))] = make_pair(0,0);
    //cout << lights.substr(0,L)<< endl;
    //cout << toString(2, L) << endl;
    dp[L-1][toBi(lights.substr(0,L)) ^ toBi(pitch)] = make_pair(0,1);
    for(int i = L-1; i < N-1; i++){
        for(int j = 0; j < 1 << L; j++){

            if(dp[i][j].first != 10000 && dp[i][j].second != 10000){
                //cout << toString(j, L) << endl;
                //we can transition fowards.
                //don't press the switch
                string s = toString(j, L);
                s += lights[i+1];
                int add = (s[0] == '1' ? 1 : 0);
                s=s.substr(1,s.length()-1);
                //cout << j << " " << toString(j, L) << " " << s << endl;
                dp[i+1][toBi(s)] = min(dp[i+1][toBi(s)], make_pair(dp[i][j].first + add,dp[i][j].second));
                //we press the switch
                s = toString(j, L);
                s += lights[i+1];
                add = (s[0] == '1' ? 1 : 0);
                s=s.substr(1, s.length()-1);
                //cout << s << " " << (toBi(s)^toBi(pitch)) << endl;
                dp[i+1][toBi(s) ^ toBi(pitch)] = min(dp[i+1][toBi(s)^toBi(pitch)], make_pair(dp[i][j].first+add, dp[i][j].second+1));
            }
        }
    }
    int ans = 0;
    int turns = 1000000;
    for(int j = 0; j < 1 << L; j++){
        //cout << toString(j, L) << " " << L - __builtin_pupcount(j) << endl; 
        if(dp[N-1][j].first != 10000 && dp[N-1][j].second != 10000){
            if(L - __builtin_popcount(j) + dp[N-1][j].first > ans){
           
                ans = L - __builtin_popcount(j) + dp[N-1][j].first;
                turns = dp[N-1][j].second;
            }
            //if(L - __builtin_popcount(j) + dp[N-1][j].first == ans){
              //  turns = min(turns, dp[N-1][j].second);
            //}
        }
    }
    if(turns == 1000000)turns = 0;
    cout << turns << endl;
}

