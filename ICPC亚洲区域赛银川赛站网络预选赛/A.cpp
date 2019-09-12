#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 100005

struct tree2
{
	tree2 *lson,*rson;
	ll one,zero,lazy_or,lazy_xor,lazy_and;
}dizhi[M*41],*root[21];

int n,m,t,a[M],b[M][21];

void bulid(tree2 *tree,int l,int r,int k)
{
	if(l==r)
	{
		tree->one=b[l][k];
		tree->zero=b[l][k]^1;
		return ;
	}
	int mid=(l+r)>>1;
	tree->lson=&dizhi[t++];
	tree->rson=&dizhi[t++];
	bulid(tree->lson,l,mid,k);
	bulid(tree->rson,mid+1,r,k);
	tree->one=(tree->lson->one+tree->rson->one);
	tree->zero=tree->lson->zero+tree->rson->zero;
}

void pushdown(tree2 *tree,int l,int r)
{
	if(!(tree->lazy_xor|tree->lazy_or|tree->lazy_and))return ;
	int mid=(l+r)>>1;
	if(tree->lazy_xor)
	{
		swap(tree->lson->one,tree->lson->zero);
		if(tree->lson->lazy_or|tree->lson->lazy_and)swap(tree->lson->lazy_or,tree->lson->lazy_and);
		else tree->lson->lazy_xor=1;
		swap(tree->rson->one,tree->rson->zero);
		if(tree->rson->lazy_or|tree->rson->lazy_and)swap(tree->rson->lazy_or,tree->rson->lazy_and);
		else tree->rson->lazy_xor=1;
		tree->lazy_xor=0;
	}
	if(tree->lazy_and)
	{
		tree->lson->zero=mid-l+1;tree->rson->zero=r-mid;
		tree->lson->one=tree->rson->one=0;
		tree->lson->lazy_and=tree->rson->lazy_and=1;
		tree->lson->lazy_xor=tree->lson->lazy_or=tree->rson->lazy_xor=tree->rson->lazy_or=0;
		tree->lazy_and=1;
	}
	if(tree->lazy_or)
	{
		tree->lson->one=mid-l+1;tree->rson->one=r-mid;
		tree->lson->zero=tree->rson->one=0;
		tree->lson->lazy_or=tree->rson->lazy_or=1;
		tree->lson->lazy_xor=tree->lson->lazy_and=tree->rson->lazy_xor=tree->rson->lazy_and=0;
		tree->lazy_or=1;
	}
}

void change1(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
	{
		swap(tree->one,tree->zero);
		if(tree->lazy_or|tree->lazy_and)swap(tree->lazy_or,tree->lazy_and);
		else tree->lazy_xor=1;
		return ;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)change1(tree->lson,l,mid,x,y);
	if(y>mid) change1(tree->rson,mid+1,r,x,y);
	tree->one=(tree->lson->one+tree->rson->one);
	tree->zero=tree->lson->zero+tree->rson->zero;
}

void change2(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
	{
		tree->one=r-l+1;
		tree->zero=0;
		tree->lazy_or=1;
		tree->lazy_xor=tree->lazy_and=0;
		return ;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)change2(tree->lson,l,mid,x,y);
	if(y>mid) change2(tree->rson,mid+1,r,x,y);
	tree->one=(tree->lson->one+tree->rson->one);
	tree->zero=tree->lson->zero+tree->rson->zero;
}

void change3(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
	{
		tree->zero=r-l+1;
		tree->one=0;
		tree->lazy_and=1;
		tree->lazy_xor=tree->lazy_or=0;
		return ;
	}
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)change3(tree->lson,l,mid,x,y);
	if(y>mid) change3(tree->rson,mid+1,r,x,y);
	tree->one=tree->lson->one+tree->rson->one;
	tree->zero=tree->lson->zero+tree->rson->zero;
}


ll query(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
		return tree->one;
	pushdown(tree,l,r);
	int mid=(l+r)>>1;
	ll t1=0,t2=0;
	if(x<=mid)t1=query(tree->lson,l,mid,x,y);
	if(y>mid)t2=query(tree->rson,mid+1,r,x,y);
	return (t1+t2);
}

int main()
{
#ifdef anantheparty
//	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int j=0;
		while(a[i])
		{
			b[i][j]=a[i]&1;
			a[i]>>=1;
			j++;
		}
	}
	for(int i=0;i<=20;i++)
	{
		root[i]=&dizhi[t++];
		bulid(root[i],1,n,i);
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int mode=read();
		if(mode==1)
		{
			int a=read(),b=read();
			ll ans=0;
			for(int i=20;i>=0;i--)
				ans=(ans<<1)+(ll)query(root[i],1,n,a,b);
			printf("%lld\n",ans);
		}
		if(mode==2)
		{
			int a=read(),b=read(),c=read(),j=0;
			while(c)
			{
				if(c&1)change1(root[j],1,n,a,b);
				c>>=1;
				j++;
			}
		}
		if(mode==3)
		{
			int a=read(),b=read(),c=read(),j=0;
			while(c)
			{
				if(c&1)change2(root[j],1,n,a,b);
				c>>=1;
				j++;
			}
		}
		if(mode==4)
		{
			int a=read(),b=read(),c=read();
			for(int j=0;j<=20;j++)
			{
				if(!(c&1))change3(root[j],1,n,a,b);
				c>>=1;
			}
		}

	}
	return 0;
}

