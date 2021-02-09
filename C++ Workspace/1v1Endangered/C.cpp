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
bool taken[105];
int indegree[105];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n;i ++){
        cin >> a[i];
    }
    for(int i = 0; i < n;i ++){
        for(int j = 0; j < n; j++){
            if(a[i] % 2 == 0 && a[i] / 2 == a[j]){
                //there exists an edge from i to j
                indegree[i]++;
            }
            if(a[i] * 3 == a[j]){
                indegree[i]++;
            }
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        //cout << indegree[i] << "\n";
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top = q.front(); q.pop();
        cout << a[top] << " " ;
        for(int i = 0; i < n; i++){
            if(a[top] % 3 == 0 && a[top]/3 == a[i]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            if(a[top] * 2 == a[i]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    
}

