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
    double p[N+1];
    for(int i = 0; i < N; i++){
        double x;
        cin >> x;
        p[i] = (double)x/1e6;
    }
    double ans = 0;
    for(int i = 0; i < N;i ++){
        double curr = 1.0;
        double prod = 1.0;
        ans = max(ans, p[i]);
        curr = p[i];
        prod = 1-p[i];
        for(int j = i+1; j < N; j++){
            ans = max(ans, curr * (1 - p[j]) + prod * p[j]);
            curr = curr * (1-p[j]) + prod * p[j];
            prod *= (1-p[j]);
            //curr = curr*(1-p[j]) + prod;
        }
    }
    int answer = (int)(ans*1e6);
    cout << setprecision(0) << fixed;
    cout << answer;

}

