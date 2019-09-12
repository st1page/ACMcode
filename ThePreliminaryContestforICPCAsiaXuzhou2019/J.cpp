#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define p 1000000007
#define N 1123456
ll inv[N];
void mmod(ll &x){
	if(x>=p) x%=p; 
}
ll madd(ll x,ll y){
	mmod(x); mmod(y);
	return x+y<p?x+y:x+y-p;
}
ll mmul(ll x,ll y){
	mmod(x); mmod(y);
	return x*y%p;
}
ll mdiv(ll x,ll y){
	mmod(x);
	return x*inv[y]%p;
}
ll mpow(ll x,ll y){
	ll res=1ll;
	for(;y;y>>=1,x=mmul(x,x)) if(y&1) res = mmul(res,x);
	return res;
}
void init(){
	inv[1]=1;
	for(int i=2;i<N;i++) inv[i]=(p-(p/i))*inv[p%i]%p;
}
vector<int> g[N];
int n;
ll f[N];
ll d[N];
int mxd[N];
int fa[N];
void dfs1(int x){
	mxd[x]=d[x];
	for(auto y:g[x]){
		if(y==fa[x]) continue;
		fa[y]=x;
		d[y]=d[x]+1;
		dfs1(y);
		mxd[x]=max(mxd[x],mxd[y]);
	}
}
void dfs2(int x){
	if(x!=1&&g[x].size()==1) {
		if(d[x]!=mxd[1]) f[x]=1;
		else f[x]=0;
		return ;
	}
	ll k = x==1? g[x].size():(g[x].size()-1);
	f[x]=0;
	for(auto y:g[x]){
		if(y==fa[x]) continue;
		dfs2(y);
		f[x]=madd(f[x],f[y]);
	}	
//	printf("%d %d %d\n",x,f[x],k);
	f[x]=mmul(f[x],mdiv(1,k));
	f[x]=mpow(f[x],k);
	//printf("%d %d\n",x,f[x]);
	return ;
}
int main(){
	init(); n=gn(); 
	for(int i=1;i<n;i++) {
		int x=gn(),y=gn();
		g[x].push_back(y); 
		g[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	printf("%lld\n",(1-f[1]+p)%p);
}




