#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#define int long long

int32_t main(){
    freopen("empty.in","r",stdin);
    freopen("empty.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int amount[N];
    memset(amount,0,sizeof(amount));
    for(int i = 0; i < K; i++){
        int x, y, a,b;
        cin >> x >> y >> a >> b;
        for(int j = 1; j <= y ;j++){
            amount[(a*j+b)%N] += x;
        }
    }
    int current = 0;
    int pos = 1;
    while(current > 0 || pos < 2 * N){
        if(amount[pos % N] != 0){
            current += amount[pos%N];
            amount[pos%N] = 0;
        }
        if(current > 0){
            amount[pos%N]++;
            current--;
        }
        pos++;
    }
    for(int i = 0; i < N; i++){
        if(amount[i] == 0){
            cout << i;
            return 0;
            
        }
    }

}

