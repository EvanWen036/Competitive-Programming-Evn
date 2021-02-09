#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> id(n);
	for(int &i : id){
		cin >> i;
	}
	deque<int> deq;
	unordered_set<int> set;
	set.reserve(512);
	
	for(int i= 0; i < n; i++){
		if(set.find(id[i]) == set.end()){
			set.insert(id[i]);
			deq.push_front(id[i]);
		}
		if(deq.size() > k){
			set.erase(deq.back());
			deq.pop_back();
		}
	}
	cout << deq.size() << "\n";
	while(!deq.empty()){
		cout << deq.front() << " ";
		deq.pop_front();
	}
	

}