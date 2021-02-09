#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    ll A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll maxi[N+1];
    ll ans = -1000000000000;
    memset(maxi, 0, sizeof(maxi));
    for(int i = 1; i <= N; i++){
        maxi[i] = (maxi[i-1] > 0 ? maxi[i-1]:0) + A[i-1];
        ans = max(ans, maxi[i]);
    }
    cout << ans << endl;


}

