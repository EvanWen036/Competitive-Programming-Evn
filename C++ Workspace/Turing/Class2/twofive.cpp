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
vector<int> adj[25];
int indegree[25];
bool vis[25];
void topSort(){
    
}
int main(){
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string type;
    cin >> type;
    for(int i  =0; i < 5;i ++){
        for(int j = 0; j < 5; j++){
            if(i != 4){
                adj[i*5+j].pb((i+1)*5+j);
                indegree[i*5+j]++;
            }
            if(j != 4){
                adj[i*5+j].pb(i*5 + j + 1);
                indegree[i*5+j]++;
            }
        }
    }
    topSort();
    /**
    for(int i =0; i < 25;i ++){
        for(auto it : adj[i]){
            cout << it << " ";
        }
        cout << "\n";
           
    }**/
    if(type == "N"){
        int a; cin >> a;
    }
    else{
        string str; cin >> str;    
    }


}

