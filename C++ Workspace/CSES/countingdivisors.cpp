#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        map<int, int> count;
        for(int i = 2; i * i <= n; i++){
            while(n % i == 0){
                count[i]++;
                n /= i;
            }
        }
        if(n != 1)count[n]++;
        ll ans = 1;
        for(map<int,int>::iterator it = count.begin(); it != count.end(); it++){
            ans *= it->second+1;
        }
        cout << ans << endl;

    }


}

