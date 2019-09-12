#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 112345
int n,m;
struct gedge{
	int to,w;
	gedge(){}
	gedge(int x,int y){
		to = x; w= y;
	}
};
vector<gedge> g[N];
ll dis[N];
int vis[N];
int S,T;
int head[N],tot=1;
#define pa pair<ll,int>
priority_queue<pa,vector<pa>,greater<pa> >pq;
struct edge{
	int next,to,f;
}e[N<<1];
void insert(int x,int y,int f){
//	printf("%d -> %d %d\n",x,y,f);
	e[++tot].to=y; e[tot].f=f; e[tot].next=head[x]; head[x]=tot;
	e[++tot].to=x; e[tot].f=0; e[tot].next=head[y]; head[y]=tot;
	return ;
}
void dij(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<N;i++) dis[i]=1ll<<60;
	pq.push(make_pair(0,1));
	dis[1]=0;
	while(!pq.empty()){
		int x = pq.top().second; pq.pop();
		if(vis[x]) continue; vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			int y = g[x][i].to, w = g[x][i].w;
			if(dis[x]+w<dis[y]){
				dis[y]=dis[x]+w;
				pq.push(make_pair(dis[y],y));
			}
		}
	}
	for(int x=1;x<=n;x++)
		for(int i=0;i<g[x].size();i++){
			int y = g[x][i].to, w = g[x][i].w;
			if(dis[x]+w==dis[y]){
				insert(x,y,w);
			}
		}
}

#define inf 123456789
int dep[N];
int q[N],fp,rp;
bool bfs(){
	memset(dep,0,sizeof(dep));
	fp=0; rp=1; q[1]=S;
	dep[S]=1;
	while(fp!=rp){
		int x=q[++fp];
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].to;
			if((!dep[y])&&e[i].f){
				dep[y]=dep[x]+1;
				q[++rp]=y;
			}
		}
	}
	return dep[T];
}
int cur[N];
int dfs(int x,int flow){
	if(x==T) return flow;
	int used=0;
	for(int i=cur[x];i;i=e[i].next){
		int y=e[i].to;
		if((dep[y]==dep[x]+1)&&(e[i].f)){
			int w=min(flow-used,e[i].f);
			w=dfs(y,w);
			e[i].f-=w; e[i^1].f+=w;
			used+=w;
			if(e[i].f>0) cur[x]=i;
			if(used==flow) return flow;
		}	
	}
	if(!used) dep[x]=0;
	return used;
}
int dinic(){
	int res=0;
	while(bfs()){
		for(int i=1;i<=T;i++) cur[i]=head[i];
		res+=dfs(S,inf);
	}
	return res;
}
void init(){
	for(int i=0;i<N;i++) vector<gedge>().swap(g[i]);	
	tot = 1;
	memset(head,0,sizeof(head));
}
void solve(){
	n=gn(); m=gn();
	for(int i=0;i<m;i++) {
		int x=gn(), y=gn(), w=gn();
		g[x].push_back(gedge(y,w));
	}
	dij();
	S=1; T=n;
	printf("%d\n",dinic());
}
int main(){
	int ttt=gn();
	while(ttt--){
		init();
		solve();
	}
}




