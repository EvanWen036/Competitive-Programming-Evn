#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll base = 31;
ll MOD = 1e9+7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll pow = 1;
    ll tHash = 0;
    for(int i = t.length()-1; i >= 0; i--){
        //cout << t[i]-'a' << " " << pow <<  endl;
        tHash += (t[i]-'a')*pow;
        tHash %= MOD;
        pow *= base;
    }
    ll totheK = 1;
    for(int i = 1; i <= t.length(); i++){
        totheK *= base;
        totheK %= MOD;
    }
    //cout << totheK << endl;
    ll rolling = 0;
    vector<ll> hashes;
    string ans = "";
    hashes.pb(0); 
    int removed = 1;
    for(int i = 0; i < s.length(); i++){
        //cout << rolling << endl;
        ans += s[i];
        rolling *= base;
        rolling += s[i] -'a';
        
        rolling %= MOD;
        if(ans.length() > t.length()){
            //cout << i << " " << ans[ans.length()-t.length()-1];
            rolling -= (totheK * (ans[ans.length()-t.length()-1]-'a'));
        }
        
        rolling %= MOD;
        //cout << rolling << endl;
        hashes.pb(rolling); 
        if(rolling == tHash){
            //delete the last couple 
            for(int i = 0; i < t.size(); i++){
                hashes.pop_back();
                ans.pop_back();
            }
            //cuut << ans << endl;
            rolling = hashes[hashes.size()-1];
            //cout << rolling << endl;
            

        }
        
    }
    cout << ans;
}

