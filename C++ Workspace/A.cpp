#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int mat[505][505];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int u, d, l, r;
    l = 500; r=  0;
    u = 500;
    d = 0;
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      for(int j = 0; j < m; j++){
        if(s[j] == 'X')mat[i][j] = 1;
        if(mat[i][j] == 1){
            u = min(u,i);
            d = max(d,i);
            l = min(l, j);
            r = max(r, j);
        }
      }
    }
    //cuut << u << " " << d << " " << l << " " << r << endl;
    for(int ro = u; ro <= d; ro++){

        for(int c = l; c <= r; c++){
            if(mat[ro][c] != 1){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;


}

