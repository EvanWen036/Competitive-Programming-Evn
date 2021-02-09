#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int n;
int prefix[3005][3005];
void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    //calculate number of elements before i
    
    for(int i = 0; i < n;i ++){
        prefix[i][a[i]] = 1;
        if(i == 0)continue;
        for(int j = 1; j <= n; j++){
            prefix[i][j] += prefix[i-1][j];
        }
    }

    for(int i = 0; i < n;i ++){
        for(int j = 0;j < n; j++){
            if(i == j && i != j){
                //now we can count how many pairs are between
                //int numberBet = prefix[j-1] - prefix[
            }
        }
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}

