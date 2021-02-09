#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int mx = 2e5+5;
multiset<int> amt[mx];
ll pow(int a, int b){
    //cout << a << " " << b << endl;
    if(b == 1)return a;
    if(b == 0)return 1;
    if(b % 2 == 0){
        ll temp = pow(a, b/2);
        return temp * temp;
    }
    else{
        return a * pow(a, b-1);
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    /**
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    **/
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int p = 2; p * p <= x; p++){
            int cnt = 0;
            while(x % p == 0){
                cnt ++;
                x /= p;
            }
            if(cnt != 0){
                amt[p].insert(cnt);
            }
        }
        if(x != 1){
            amt[x].insert(1);
        }
    }
    ll ans = 1;
    for(int i = 2; i <= 200000; i ++){
        //if(amt[i].size() < 2)cuntinue;
        
        //cout << i << endl;
        /**
        for(auto it : amt[i]){
            cout << it << " ";
        }        
        cout << endl;
        **/;
        //cuut << *next(amt[i].begin()) << " " << puw(i,*next(amt[i].begin())) << endl;
        if(amt[i].size() == n){
            ans *= pow(i,*(next(amt[i].begin())));
        }
        if(amt[i].size() == n-1){
            ans *= pow(i, *amt[i].begin());
        }
    }
    cout << ans << endl;


}

