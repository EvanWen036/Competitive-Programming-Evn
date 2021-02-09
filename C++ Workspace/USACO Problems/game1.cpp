#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int sum[5005][5005];
int memo[5005][5005];
int dp(int A[], int l, int r){
    if(memo[l][r] == -1){
        if(l == r){
            memo[l][r] = A[l];
        }
        else{
            memo[l][r] = max(A[l] + sum[l+1][r] - dp(A, l+1, r), A[r] + sum[l][r-1] - dp(A,l,r-1));
        }
    }
    return memo[l][r];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int A[N];
    int total = 0;
    for(int i = 0;i < N;i ++){
        cin >> A[i];
        total += A[i];
    }
    
    for(int i = 0; i < N;i ++){
        int temp = 0;
        for(int j = i;j < N; j++){
            temp += A[j];
            sum[i][j] = temp;
            //cout << i << " " << j << " " << sum[i][j] << endl;
            memo[i][j] = -1;
        }
    }
    int ans = dp(A, 0, N-1);
    cout << ans << '\n';


}

