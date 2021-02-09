#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
string poss[] = {"1869","6198" ,"1896" ,"9186" ,"1986","6189", "1698"}; 

void solve(){
    string a;
    cin >> a;
    int cnt[11];
    memset(cnt, 0, sizeof(cnt));
    string ans = "";
    //int zeroes = 0;
    for(int i = 0; i < a.length(); i ++){       
        //cout << a[i]-'0' << endl;
        cnt[a[i] - '0']++;        
    }
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    int remainder = 0; 
    for(int i = 1; i < 10; i++){
        for(int j = 1; j <= cnt[i];j ++){
            cout << i;
            remainder = remainder * 10 + i;
            remainder %= 7;
        }
    }
    cout << poss[remainder];
    for(int i = 0; i < cnt[0]; i++)cout << 0;
    //cuut << ans;
    //cout << endl;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    //cin >> t;
    t= 1;
    while(t--){
        solve();
    }


}

