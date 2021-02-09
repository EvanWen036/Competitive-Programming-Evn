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
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    vector<pii> A(N+1);
    for(int i= 1;i <= N;i ++){
        int a;
        cin >> a;
        A[i] = {a,i};
    }
    sort(A.begin(), A.end());
    int mx = 0;
    vector<int> val(N+2);
    val[0] = 0;
    for(int i = 1; i <= N; i ++){
        val[i] = mx + 1 - i;
        mx = max(mx, A[i].s);
    }
    val[N+1] = 0;
    ll ans = 0;
    for(int i =1;i <= N; i++){
        int curr = max(val[i], val[i+1]);
        if(curr == 0 && N > 1)curr++;
        ans += curr;
    }
    cout << ans << "\n";
}

