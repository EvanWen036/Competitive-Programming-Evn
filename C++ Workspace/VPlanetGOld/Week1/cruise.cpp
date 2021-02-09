#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	freopen("cruise.in", "r", stdin);
	freopen("cruise.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    pair<int, int> adj[N];
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        //cout << a << " " << b << endl;
        adj[i] = mp(--a,--b);
    }
    string directions[M];
    for(int i = 0; i < M; i++){
        string a;
        cin >> a;
        directions[i] = a;
        //cout << directions[i] << endl;
    }
    //build functional graph
    int graph[N];
    for(int i = 0; i < N;i ++){
        int curr = i;
        for(int i = 0; i < M; i++){
            if(directions[i] == "L"){
                //go to the left
                curr = adj[curr].f;
            }
            else{
                curr = adj[curr].s;
            }
        }
        graph[i] = curr;
        //cout << graph[i] << endl;
    }
    //where you get to if you go 2^second_index from first index
    int P[N][32];
    for(int i = 0; i < N; i++){
        P[i][0] = graph[i];
    }
    for(int i = 1; i <= 31;i ++){
        for(int j =0; j < N;j ++){
            int temp = P[j][i-1];
            P[j][i] = P[temp][i-1];
            //cout << i << " " << j << " " << P[j][i] << endl; 
        }
    }
    int k = 0;
    int pos = 0;
    for(int i =0; i < 32;i ++){
    	if(K & (1 << i)){
    		pos = P[pos][i];
    	}
    }
    cout << pos+1 << endl;

}

