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
string str[8] = {"byr","iyr","eyr","hgt","hcl","ecl","pid","cid"};
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream File("input.in");
	int ans = 0;
	while(!File.eof()){
		string s;
		set<string> set;
		cout << "hi\n";
		int cnt = 0;
		while(getline(File, s) && !s.empty()){
			//set.insert(s.substr(0, 3));
			int pos = 0;
			while(s.length()){
				pos = s.find(" ");

				//cout << s.substr(0, pos);
				int col = s.substr(0,pos).find(":");
				string type = s.substr(0, 3);
				if(col != string::npos){
					string val = s.substr(0,pos).substr(col+1);
					//cout << type << " " << val << '\n';
					if(type == "byr" && stoi(val) >= 1920 && stoi(val) <= 2002){
						set.insert("byr");
					}
					if(type == "iyr" && stoi(val) >= 2010 && stoi(val) <= 2020){
						set.insert("iyr");
					}
					if(type == "eyr" && stoi(val)>= 2020 && stoi(val) <= 2030){
						set.insert("eyr");
					}
					if(type == "hcl"){
						cout << val << '\n';
						cout << (val[0] == '#') << '\n';
						if(val[0] == '#' && val.length() == 7){
							cout << "hi\n";
							for(int i = 1; i <= 6; i++){
								if(!isalpha(val[i]) && !isdigit(val[i])){
									break;
								}
							}
							set.insert("hcl");
						}
					}
					if(type == "hgt"){
						string type = val.substr(val.length()-2); 
						//cout << type << '\n';
						if(type == "in"){
							int pos = val.find(type);
							if(stoi(val.substr(0,pos)) >= 59 && stoi(val.substr(0,pos)) <= 76){
								set.insert("hgt");
							}
						}
						if(type == "cm"){
							int pos = val.find(type);
							if(stoi(val.substr(0,pos)) >= 150 && stoi(val.substr(0,pos)) <= 193){
								set.insert("hgt");
							}
						}
					}
					if(type == "ecl" && (val == "amb" || val == "blu" || val == "brn" || val == "gry" || val == "grn" || val == "hzl" || val == "oth")){
						set.insert("ecl");
					}
					if(type == "pid" && val.length() == 9){
						for(int i = 0; i <8 ; i++){
							if(!isdigit(val[i]))break;
						}
						set.insert("pid");
					}
				}
				if(pos == string::npos){
					break;
				}
				s.erase(0, pos + 1);

			}
		}
		for(auto it : set){
			cout << it << ' ';
		}
		cout << '\n';
		if(set.size() == 7){
			ans++;
		}
	}
	cout << ans << '\n';

}
