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
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N;
    cin >> N;
    vector<pii> pts(N);
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        pts[i] = mp(x,y);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N;k ++){
                if(i ==j || j ==k || i == k)continue;
                if(pts[j].f == pts[i].f && pts[j].s == pts[k].s){
                    ans = max(ans, abs(pts[j].s - pts[i].s) * abs(pts[j].f - pts[k].f));
                }
            }
        }
    }
    cout << ans << "\n";
}

