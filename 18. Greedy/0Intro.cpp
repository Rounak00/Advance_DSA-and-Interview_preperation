/*Understanding basic greedy, in basic greedy questions we mainy times use searching, sorting, priority queue*/

//1. Codechef question code RAMDEV, here a hall number given with Dimension LxB and we need to count how many people can do yoga , every one get a yoga mt lxb size and we can place it either horizental or vertical

-> we can place it like that (L/l)*(B/b) , but if we place it horizental then we will place it this way (L/b)*(B/l)
   Now here we need to do both and check which will give you max number 
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long L,B,l,ans=0,b,hall;
	cin>>l>>b;
	cin>>hall;
     for(long long i=0;i<hall;i++){
         cin>>L>>B;
         ans+=max((L/l)*(B/b),(L/b)*(B/l));
     }
	cout<<ans<<endl;
	return 0;
}



//2. Codechef question code CARSELL, where each year we need to sell cars and every year car price will -1; and car price never goes lessthan 0.

-> mahnga car pahle becho bcz sasti wali 0 ke niche nehi jayega

#include <bits/stdc++.h>
#define ll long long
#define mod 1,000,000,007
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    vector<int>v;
	    for(ll i=(ll)0;i<n;i++){cin>>v[i];}
	    sort(v.begin(),v.end(),greater<ll>());
	    ll ans =(ll)0;
	    for(ll i=(ll)0;i<n;i++){
	        ans+=max((ll)0,v[i]-i);
	        ans%=mod;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}


