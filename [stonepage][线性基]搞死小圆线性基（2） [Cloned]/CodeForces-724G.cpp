/*
��Ȩ����ͼ������������Ԫ��(u,v,w)��u��v֮����·������Ȩ����Ϊw��w֮��
����ͼdfs��ֻ�з���ߡ�
��x,y֮������п��ܵ�·�������� ����x��y·���������л�������������
��w������ÿһλ�Ĺ��ס�
��СΪS�����Ի�����2^S��������Ͻ����
�������������iλ��Ϊ0�����н����Ϊ��Ϊ0�� 
�������������iλΪ1������������������ѡȡ��2^(S-1)�֣���ʱ�������Ƿ�ѡ����������Ϊ�Ƿ�Ϊ1��
���λΪ0��1����2^(S-1)�� 
*/
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define K 62 
#define N 112345
#define M 412345 
#define P 1000000007ll
struct LinerBase{
	ll a[K];
	int siz;
	void init(){
		memset(a,0,sizeof(a));
		siz=0;
	}
	void add(ll x){
		for(int i=K-1;i>=0;i--) if((x>>i)&1){
			if(a[i]) x^=a[i];
			else {
				a[i]=x;
				siz++;
				break;
			}
		}
	}
}b;
int n,m;
int head[N];
struct edge{
	int to,next;
	ll w;
}e[M];
int tot;
void _ins(int x,int y,ll w){
	e[++tot].to=y; e[tot].w=w;
	e[tot].next=head[x]; head[x] =tot;
}
void ins(int x,int y,ll z){
	_ins(x,y,z); _ins(y,x,z);
}
int vis[N];
int siz[N];
ll d[N];ll cnt[K];

void dfs(int x){
	for(int k=0;k<K;k++) if((d[x]>>k)&1) cnt[k]++;
	siz[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].to; ll w=e[i].w;
		if(vis[y]) b.add(d[x]^d[y]^w);
		else {
			vis[y]=vis[x];
			d[y]=d[x]^w;
			dfs(y);
			siz[x]+=siz[y];
		}
	}
}
int gsiz;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y; ll w;
		scanf("%d%d%lld",&x,&y,&w);
		ins(x,y,w);
	}
	ll ans=0;
	for(int rt=1;rt<=n;rt++) if(!vis[rt]){
		b.init();
		vis[rt]=rt; d[rt]=0; siz[rt]=0;
		memset(cnt,0,sizeof(cnt));
		dfs(rt);
		for(int k=0;k<K;k++){
			int flag=0;
			for(int i=0;i<K;i++) if((b.a[i]>>k)&1) flag=1;
			if(flag){
				ans+= (ll)(1ll<<k) % P * ((1ll<<(b.siz-1))%P) % P * (ll)(1ll*siz[rt]*(siz[rt]-1)/2%P) % P;
				if(ans>=P) ans-=P;
			} else {
				ans+= (ll)(1ll<<k) % P * ((ll)(1ll<<b.siz)%P) % P * (ll)(1ll*cnt[k]*(siz[rt]-cnt[k])%P) %P;
				if(ans>=P) ans-=P;
			}
		}
	}
	printf("%lld\n",ans);
}

