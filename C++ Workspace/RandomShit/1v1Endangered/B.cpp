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
    int n, A, B, C, T;
    cin >> n >> A >> B >> C >> T;
    vector<int> cst(n);
    int ans1 = n*A;
    int ans2 = 0;
    for(int i = 0; i < n; i++){
        cin >> cst[i];
        ans2 += A - (B * (T-cst[i]));
        ans2 += C * (T-cst[i]);
    }
    cout << max(ans1, ans2);


}

