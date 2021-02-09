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
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    int s = 0;
    for(int i = 1; i <= n;i ++){
        cin >> a[i];
        s += a[i];
    }
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    if(s % n != 0){
        cout << -1 << "\n";
        return;
    }
    //int val = -1;
    //check if there is a possible answer
    /**
    for(int i = 1; i <= n;i ++){

        for(int j = 1; j <= n;j ++){
            //if(j == i)continue;
            if(abs(a[i] - a[j]) % 2 != 0){
                cout << -1 <<  "\n";
                return;
            }
        }
    }**/
    //cout << n-1 << "\n";
    int avg = s/n;
    vector<pair<pii,int>> operations;
    for(int i = 0; i < n;i ++){
        //find minimum
        int mi = 100000000;
        int miPos = -1;
        for(int i = 1; i <= n;i ++){
            if(a[i] < mi && a[i] != avg){
                mi = a[i];
                miPos = i;
            }
        }
        if(miPos == -1){
            break;
        }
        for(int i = 1; i <= n;i ++){
            if(a[i] > mi && i != miPos && a[i] != avg){
                if(abs(avg - a[miPos]) % i == 0 && a[i] >= (avg-a[miPos])){
                    //cout << i << " " << miPos << " " << (avg - a[miPos])/i << "\n";
                    operations.pb(mp(mp(i,miPos), (avg-a[miPos])/i));
                    a[i] -= (avg - a[miPos]);
                    a[miPos] = avg;
                    break;
                }
            }
        }
    }
    for(int i =1 ;i <= n ;i ++){
        if(a[i] != avg){
            cout << -1 << "\n";
            return;
        }
    }
    cout << operations.size() << "\n";
    assert(operations.size() <= 3 * n);
    for(int i = 0; i < operations.size(); i++){
        pair<pii,int> it = operations[i];
        //cout << "hi" << endl;
        cout << it.f.f << " " << it.f.s << " " << it.s << "\n";
    }
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

