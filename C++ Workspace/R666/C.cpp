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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0;i  < N; i++){
        cin >> a[i];
    }
    if(N == 1){
        for(int i = 1; i <= 3; i++){
            cout << 1 << " " << 1 << endl;
            if(i % 2 == 1){
                cout << a[0] * -1 << endl;
            }
            else{
                cout << a[0] << endl;
            }
        }
        return 0;
    }
    cout << 1 << " " << 1 << endl;
    cout << -1 * a[0] << endl;
    a[0] = 0;
    cout << 2 << " " << N << endl;
    for(int i = 1; i < N; i++){
        cout << N * a[i] - (a[i]) << " ";
        a[i] = N*a[i];
    }
    cout << endl;
    cout << 1 << " " << N << endl;
    for(int i = 0; i < N; i++){
        cout << -1 * a[i] << " ";
    }


}

