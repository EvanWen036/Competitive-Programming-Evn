#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int dsu[100005];
int size[100005];
int maxSize;
int maxPos;
int find(int u){
    if(dsu[u] == u){
        return u;
    }
    return find(dsu[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(dsu[u] == -1 || dsu[v] == -1)return;
    if(u < v){
        dsu[u] = v;
        size[v] += size[u];
        if(size[v] == maxSize){
            maxPos = -1;
        }
        if(size[v] > maxSize){
            maxSize = size[v];
            maxPos = v;
        }
    }
    if(v < u){
        dsu[v] = u;
        size[u] += size[v];
        if(size[u] == maxSize){
            maxPos = -1;
        }
        if(size[u] > maxSize){
            maxSize = size[u];
            maxPos = u;
        }
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n);
        map<int, int> pos;
        maxSize = 1;
        maxPos = -1;
        for(int i = 0; i < n;i ++){
            cin >> p[i];
            pos[p[i]] = i;
        }
        for(int i = 0; i < n;i ++){
            dsu[i] = i;
            size[i] = 1;
        }
        dsu[n] = -1;    
        int firstPos = pos[1];
        if(firstPos != n-1){
            merge(firstPos, firstPos+1);
        }
        if(firstPos == n-1)dsu[firstPos] = -1;
        bool done = false;
        for(int i = 2; i <= n;i ++){
            for(int i = 0; i < n;i ++){
                cout << dsu[i] << " ";
            }
            cout << "\n";
            int f = pos[i];
            if(size[f] < maxSize){
                done = true;
                cout << "No" << endl;
                break;
            }
            else{
                    if(pos[i]){
                    merge(pos[i], pos[i]+1);
                }
                if(pos[i] == n-1)dsu[pos[i]] = -1;
            }
        }
        if(!done)cout << "Yes" << endl;
        
    }


}

