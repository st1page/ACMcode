#include<cstdio>

using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 212345
#define MOD 998244353
int m;
ll t1,t2;
int p,q,n,m;
ll C(int x,int y,int mod){
	
}
ll pow(ll x,ll y,ll mod){
	x%=mod;
	ll res=1;
	for(;y;y>>=x, x=x*x%mod) if(y&1) res=res*x%mod;
	return res;
}
ll ans=1;
int main(){
	while(scanf("%lld%lld%lld%lld%lld%lld%d",&t1,&t2,&p,&q,&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			int vt1 = pow(v,t1,MOD);
			int vt2 = pow(v,t2,MOD);
			if(x% p || y%q) continue;
			int a=x%p, b=y%q;    
		}
	}
	return 0;
}




