#include<bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using namespace std;
constexpr int mo = 1e9+7;
constexpr int inf = 1<<30;
constexpr ll infl = 1ll<<60;

int main(){
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> pos,neg;
	int all = 0;
	for(int i=0;i<n;++i){
	       	cin>>a[i];
		if(a[i] >= 0) pos.push_back(a[i]),all=1;
		else if(a[i] < 0) neg.push_back(a[i]);

	}
	sort(neg.rbegin(),neg.rend());
	sort(pos.begin(),pos.end());
	if(all == 0){
		if(k%2 == 0){
			ll sum = 1;
			for(int i=0;i<k;++i){
				sum *= mo+neg[n-i-1];
				sum %= mo;
			}	
			cout << sum << endl;
		}else {
			ll sum = 1;
			for(int i=0;i<k;++i){
				sum *= mo + neg[i];
				sum %= mo;
			}
			cout << sum << endl;
		}
	}else {
		if((int)pos.size() == n){
			ll sum = 1;
			for(int i=0;i<k;++i){
				sum *= pos[n-i-1];
				sum %= mo;
			}
			cout << sum << endl;
		}else {
			ll sum = 1;
			if(k%2 == 1){
				sum *= pos.back();
				pos.pop_back();
			}
			vector<ll> vec;
			while((int)pos.size() >= 2){
				ll x = pos.back(); pos.pop_back();
				x *= pos.back(); pos.pop_back();
				vec.push_back(x);
			}
			while((int)neg.size() >= 2){
				ll x = neg.back(); neg.pop_back();
				x *= neg.back(); neg.pop_back();
				vec.push_back(x);
			}
			sort(vec.rbegin(),vec.rend());
			for(int i=0;i<k/2;++i){
				sum *= vec[i];
			}
			cout << sum << endl;
			
		}
	}
	return 0;
}
