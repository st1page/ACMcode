#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

#define K 62
struct LinerBase{
	ll a[K];
	ll na[K];
	int tot=0;
	int zero;
	void init(){
		zero=tot=0;
		memset(a,0,sizeof(a));
	}
	void add(ll x){
		for(int i=K-1;i>=0;i--) if((x>>i)&1){
			if(a[i]) x^=a[i];
			else {
				a[i]=x;
				break;
			}
		}
		if(!x) zero=1;
	}
	void rebuild(){
		for(int i=0;i<K;i++) if(a[i])
			for(int j=i+1;j<K;j++) if((a[j]>>i)&1) a[j]^=a[i];
		tot=0;
		for(int i=0;i<K;i++) if(a[i]) na[tot++]=a[i];
	}
	ll minK(ll k){
		if(zero) k--;
		if(k>=(1ll<<tot)) return -1;
		ll res=0;
		for(int i=0;i<tot;i++) if((k>>i)&1) res^=na[i]; 
		return res;
	}
}b;
int main(){
	int T; scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		b.init();
		printf("Case #%d:\n",cas);
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++) {
			ll x; scanf("%lld",&x);
			b.add(x);
		}
		b.rebuild();
		int m; scanf("%d",&m);
		for(int i=0;i<m;i++){
			ll x; scanf("%lld",&x);
			printf("%lld\n",b.minK(x));
		}
	}
	return 0;
}

