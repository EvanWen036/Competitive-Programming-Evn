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
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    double p[N];
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        p[i] = x/1e6;
    }
    int l = 0;
    int r = 0;
    double ans = 0;
    double sum = 0;
    double product = 1;
    while(l < N || r < N){
        while(sum < 1 && r < N){
            //extend
            sum += p[r] / (1-p[r]);
            product *= (1-p[r]);
            r++;
        }
        ans = max(ans, sum*product);
        sum -= p[l]/(1-p[l]);
        product /= (1-p[l]);
        l++;

    }
    cout << (int)(ans*1e6) << "\n";

}

