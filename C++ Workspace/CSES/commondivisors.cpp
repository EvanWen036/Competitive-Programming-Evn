#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int freq[1000005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    //int freq[1000005];
    for(int i = 0; i < N;i ++){
        int x;
        cin >> x;
        freq[x]++;
    }
    int MAX = 1e6;
    int ans = 0;
    for(int i = MAX; i >= 1; i--){
        int cnt = 0;
        for(int j = i; j <= MAX; j+=i){
            cnt += freq[j];
        }
        if(cnt >= 2){
            ans = max(ans, i);
        }
    }
    cout << ans << endl;


}

