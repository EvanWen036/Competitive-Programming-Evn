#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    int ones = 0;
    int zeroes = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0)zeroes++;
        if(a[i] == 1)ones++;
        if(i % 2 == 0){
            s += a[i];
        }
        else{
            s -= a[i];
        }
    }
    if(s == 0){
        cout << n << endl;
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else if(s != 0){
        if(zeroes >= n/2){
            cout << n/2 << endl;
            for(int i = 0; i < n/2;i ++){
                cout << 0 << " ";
            }
            cout << endl;
        }
        else{
            int cnt = 0;
            cout << (n/2 % 2 == 0 ? n/2:(n/2)+1) << endl;
            int end = n/2;
            if(end%2 == 1)end++;
            for(int i = 0; i < end;i ++){
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    



    /**
    for(int pos = 0; pos < n; pos++){
        //cnt is # of 1
        vector<int> ans;
        bool chk = false;
        int prev = -1;
        for(int i = pos; i < n; i++){
            if(a[i] == prev || prev == -1){
                ans.pb(a[i]);
                if((i - pus)%2 == 1){
                    prev = -1;
                }
                else{
                    prev = a[i];
                }
            }
        }
        int s = 0;
        for(int i = 0; i < ans.size(); i++){
            if(i % 2 == 0){
                s += ans[i];
            }
            else{
                s -= ans[i];
            }
        }
        if(s == 0 && ans.size() >= n/2){
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
            return;
        }
    }**/
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

