/*
无向图，从1到n的异或和
每条路走一次才有意义
答案在一条路径加上很多圈 
dfs任意一条即可，其它路径可等价
线性基维护最大异或 
*/

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
#define N 51234
#define M 212345
#define K 63  
struct LinerBase{
	ll a[K];
	void add(ll x){
		for(int i=K-1;i>=0;i--) if((x>>i)&1){
			if(a[i]) x^=a[i];
			else {
				a[i]=x;
				break;
			}
		}
	}
	ll max(ll x){
		ll res=x;
		for(int i=K-1;i>=0;i--) if((res^a[i])>res)	res^=a[i];
		return res;
		
	} 
}b;
int head[N];
struct edge{
	int to,next;
	ll w;
}e[M];
int tot;
void _ins(int x,int y,ll w){
	e[++tot].to=y; e[tot].w=w;
	e[tot].next=head[x]; head[x]=tot;
}
void ins(int x,int y,ll w){
	_ins(x,y,w); _ins(y,x,w);
}
int n,m;
ll d[N];
int vis[N];
void dfs(int x){
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to; ll w=e[i].w;
		if(vis[y]){
			b.add(d[x]^d[y]^w);
		}else {
			d[y]=d[x]^w; vis[y]=1;
			dfs(y);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int x,y; ll w;
		scanf("%d%d%lld",&x,&y,&w);
		ins(x,y,w);
	}
	vis[1]=1; d[1]=0;
	dfs(1);
	printf("%lld\n",b.max(d[n]));
	return 0;
}




