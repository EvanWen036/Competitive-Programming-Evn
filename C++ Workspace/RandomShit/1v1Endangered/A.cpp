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
    int n, a, b;
    cin >> n >> a >> b;
    int cnt2 = 0;
    int cnt1 = 0;
    for(int i = 0; i < n;i ++){
        int a;
        cin >> a;
        if(a == 2)cnt2++;
        else{cnt1++;}
    }
    int ans = (cnt2 > b ? cnt2-b:0);
    if(b >= cnt2){
        b-=cnt2;
    }
    int totalSeats = a + b*2;
    ans += (cnt1 > totalSeats ? cnt1-totalSeats:0);
    cout << ans;

}

