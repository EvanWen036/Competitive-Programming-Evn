#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int A[N+1];
    for(int i = 0; i < N;i ++){
        cin >> A[i];
    }
    A[N] = 0;
    ll ans = 0;
    for(int i = 0; i <= N; i++){
        if(i == 0){
            ans += A[i];
        }
        else{
            ans += abs(A[i]-A[i-1]);
        }
    }
    cout << ans / 2 << endl;


}

