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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[k];
    for(int i = 0; i < k;i ++){
        a[i] = i;
    }
    int ans = 100000000;
    vector<string> vt;
    int mi = 1e8;
    int ma = 0;
    for(int i = 0; i < n;i ++){
        string s;
        cin >> s;
        mi = min(mi,stoi(s));
        ma = max(ma, stoi(s));
        //cout << s << "\n";
        vt.push_back(s);
    }
    ans = min(ans, ma-mi);
    while(next_permutation(a, a+k)){
        //cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << "\n";
        //cout << "hi" << "\n";
        mi = 1000000000;
        ma = 0;
        bool dip = false;
        for(int i = 0; i < n;i ++){
            string curr = "";
            for(int j = 0; j < k; j++){
                curr += vt[i].substr(a[j], 1);
            }
            int val = stoi(curr);
            mi = min(mi, val);
            ma = max(ma, val);
        }
        //cout << ma << " " << mi << "\n";
        //if(dip)break;
        ans = min(ans, ma-mi);
    }
    cout << ans << "\n";


}

