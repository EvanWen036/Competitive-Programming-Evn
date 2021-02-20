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
#define vti vector<int>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int cnt[105][105];

int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        vti a;
        for(int j = 0; j < N; j++){
            int next; cin >> next;
            a.pb(next);
        }
        for(int j = 0; j < N; j++){
            for(int x = 0; x < N; x++){
                if(x == j)continue;
                if(a[j] > a[x]){
                    cnt[j][x]++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cnt[i][j] >= K/2 + 1)ans++;
        }
    }
    
	cout << ans << "\n";

}

