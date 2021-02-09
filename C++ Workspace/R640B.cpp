#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n ,k;
        cin >> n >> k;
        if(k > n){
            cout << "NO" << endl;
            continue;
        }
        if(k == n){
            cout << "YES" << endl;
            for(int i = 0; i < k; i++){
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        if(n%2 == 0 && k > n/2 && k % 2 == 1){
            cout << "NO" << endl;
            continue;
        }
        if(n%2 == 1 && k % 2 == 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int sum = 0;
        for(int i = 0; i < k-1; i++){
            if(n % 2 == 0 && 2 *k <= n){
                cout << 2 << " ";
                sum += 2;
            }
            else{
                cout << 1 << " ";
                sum++;
            }
        }
        cout << n-sum << endl;
        

    }


}

