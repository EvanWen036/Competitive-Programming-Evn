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
	int n, m, x, y;
    cin >> n >> m >> x >> y;
    int startX = x;
    bool end = false;
    for(int c = y; c <= m; c++){
        cout << x << " " << c << endl;
        //end = true;
    }
    for(int c = y-1; c >= 1; c--){
        cout << x << " " << c << endl;
    }
    for(int r = 1; r <= n; r++){
        if(r == startX)continue;
        if(end){
            for(int c = m; c >= 1; c--){
                cout << r << " " << c  << endl;
            }
            end = false;
        }
        else if(!end){
            fur(int c = 1; c<= m; c++){
                cout << r << " " << c << endl;
            }
            end = true;
        }

    }



}

