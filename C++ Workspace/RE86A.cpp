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
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(b < 2 * a){
            if(x < y){
                swap(x,y);
            }
            cout << (y*b + a*(x-y)) << endl;
        }
        else{
            cout << x*a + y*a << endl;
        }
    }


}

