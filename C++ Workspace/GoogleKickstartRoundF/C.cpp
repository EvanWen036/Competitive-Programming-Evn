#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
bool bad[10][10];
int col[10];
int ans = -100000000;
int N;
void go(int r1, int c1, int p1, int r2, int c2, int p2, bool turn){
    assert(r1 <= N && r2 <= N);
    bool wentSomewhere = false;
    bad[r1][c1] = true;
    bad[r2][c2] = true;
    //cout << r1 << " " << c1 << " " << p1 << " " << r2 << " " << c2 << " " << p2 << " " << turn << "\n";
    bool comeFrom = false;
    if(turn){
        //bool comeFrom = false;
        if(!bad[r1-1][c1-1] && r1 -1 >= 1 && c1-1 >= 1 && c1 <= col[r1-1]){
            wentSomewhere = true;
            go(r1-1,c1-1, p1+1, r2, c2, p2, !turn);
        }
        if(!bad[r1+1][c1+1] && r1 + 1 <= N && c1 <= col[r1+1]){
            wentSomewhere = true;
            go(r1+1,c1+1, p1+1, r2, c2, p2, !turn);
        }
        if(!bad[r1][c1+1] && c1 + 1<= col[r1]){
            wentSomewhere = true;
            go(r1, c1+1, p1+1, r2, c2, p2, !turn);
        }
        if(!bad[r1][c1-1] && c1 - 1>= 1){
            wentSomewhere = true;
            go(r1, c1-1, p1+1, r2, c2, p2, !turn);
        }
        if(wentSomewhere == false){
            //turn over
            turn = false;
            comeFrom = true;
        }
    }
    if(!turn){
        if(!bad[r2-1][c2-1] && r2 - 1 >= 1 && c2 -1  >= 1 && c2 <= col[r2-1]){
            wentSomewhere = true;
            go(r1,c1,p1,r2-1,c2-1, p2+1, true);
        }
        if(!bad[r2+1][c2+1] && r2 + 1 <= N && c2 <= col[r2+1]){
            wentSomewhere = true;
            go(r1,c1,p1,r2+1,c2+1,p2+1, true);
        }
        if(!bad[r2][c2+1] && c2 + 1 <= col[r2]){
            wentSomewhere = true;
            go(r1,c1,p1,r2,c2+1, p2+1, true);
        }
        if(!bad[r2][c2-1] && c2 - 1 >= 1){
            wentSomewhere = true;
            go(r1,c1,p1,r2, c2-1, p2+1, true);
        }
        if(!wentSomewhere){
            //cout << "hi\n";
            if(!comeFrom){
                go(r1,c1,p1,r2,c2,p2, true);
            }
            //cout << "hi" << "\n";
            else{
                //cout << p1 << " " << p2 << "\n";
                ans = max(ans,p1-p2);
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
        int  rA, pA, rB, pB, C;
        cin >> N >> rA >> pA >> rB >> pB >> C;
        bad[rA][pA] = true;
        bad[rB][pB] = true;
        for(int i = 0; i < C; i++){
            int x, y;
            cin >> x >> y;
            bad[x][y] = true;
        }
        col[1] = 1;
        for(int i = 2; i < 10; i ++){
            col[i] = col[i-1] + 2;
        }
        go(rA, pA, 1, rB, pB, 1, true);
        cout << ans << "\n";
        memset(bad, false, sizeof(bad));
        ans = -100000000;
    }

}

