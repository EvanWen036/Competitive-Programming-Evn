#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
string s;
int x;
void solve(){
    cin >> s >> x;
    //cout << s << endl;
    string ans = "";
    for(int i = 0; i < (int)s.length(); i++){
        ans += "1";
    }
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == '0'){
            if(i-x >= 0){
                //cout << "hi" << endl;
                ans[i-x] = '0';
            }
            if(i + x < (int)s.length()){
                ans[i+x] = '0'; 
            }
        }
    }
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == '1'){
            bool chk1 = 0;
            bool chk2 = 0;
            //cout << i + x << " " << i - x << endl;
            if(i+x < (int)s.length() && ans[i+x] == '1')chk1 = true;
            if(i - x >= 0 && ans[i-x] == '1')chk2=  true;
            //cout << i << " " << chk1 << " " << chk2 << endl;
            if(!chk1 && !chk2){
                cout << -1 << endl;
                return;
            }

        }
    }
    cout << ans << endl;

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}

