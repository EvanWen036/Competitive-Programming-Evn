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
	int A, B, n, m;
    cin >> A >> B >> n >> m;
    vector<int> vert(n+1);
    vector<int> horz(m+1);
    vert[0] = 0;
    horz[0] = 0;
    //vert[n+1] = A;
    //horz[m+1] = B;
    for(int i =1; i <= n; i++){
        cin >> vert[i];
    }
    for(int i =1; i <= m;i ++){
        cin >> horz[i];
    }
    sort(vert.begin(), vert.end());
    sort(horz.begin(), horz.end());
    vector<pii> edges;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        vert[i] = vert[i+1] - vert[i];
        if(i != 0){
            edges.pb(mp(vert[i], 0));
        }    //cout << vert[i] << endl;
        else{
            ans += vert[i] * m;
        }
    }
    for(int i = 0; i < m; i ++){
        horz[i] = horz[i+1] - horz[i];
        //cout << horz[i] << endl;
        
        if(i != 0){
          edges.pb(mp(horz[i], 1));
        }
        else{
            ans += horz[i] * n;
        }
      }
    sort(edges.begin(), edges.end());
    int rowsRemoved = 1;
    int columnsRemoved = 1;
    //ll ans = 0;
    for(auto it: edges){
        if(it.s == 0){
            //this is a horizontal edge
            ll remove = (m+1)- rowsRemoved;
            if(remove < 0)break;
            ans += (it.f*remove);
            cout << it.f << " " << remove <<endl;
            rowsRemoved++;
        }
        else{
            ll remove = (n+1) - columnsRemoved;
            if(remove < 0)break;

            ans += it.f*remove;
            cout << it.f << " " << remove << endl;
            columnsRemoved++;
        }
    }
    cout << ans << endl;


}

