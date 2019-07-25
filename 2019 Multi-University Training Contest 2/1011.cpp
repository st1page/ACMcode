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
#define N 112345
#define M 45
int n,q;
int aa[N];
struct Node {
	int tot;
	int a[M];
	Node *ls,*rs;
	void init(){
		tot=0;
	}
	void init(int x){
		a[0]=x;
		tot=1;
	}
	void add(int x){
		a[tot++]=x;
	}
	void out(){
		printf("%d:: ",tot);
		for(int i=0;i<tot;i++) printf("%d ",a[i]);
		putchar('\n');
	}
}pool[N<<2],*rt,*p;
void merge(Node *res,Node x,Node y){
	res->tot =0;
	for(int i=0,j=0;i<x.tot||j<y.tot;){
		if(res->tot==M) break;
		if(j==y.tot || (i<x.tot&&x.a[i]>y.a[j]) ) res->add(x.a[i++]);
		else res->add(y.a[j++]);
	}
}
void merge(Node *res,Node y){
	int tmp[M];
	int tt=res->tot;
	for(int i=0;i<tt;i++) tmp[i]=res->a[i];
	res->tot =0;
	for(int i=0,j=0;i<tt||j<y.tot;){
		if(res->tot==M) break;
		if(j==y.tot || (i<tt&&tmp[i]>y.a[j]) ) res->add(tmp[i++]);
		else res->add(y.a[j++]);
	}
}
void init(){
	rt=p=pool;
}
void build(Node *x,int l,int r){
	if(l==r){
//		printf("[%d]\n",l);
		x->init(aa[l]);
//		x->out();
		return ;
	}
	int mid=(l+r)>>1;
	x->ls = ++p;
	x->rs = ++p;
	build(x->ls,l,mid);
	build(x->rs,mid+1,r);
	merge(x,*x->ls,*x->rs);
//	printf("[%d,%d]\n",l,r);
//	x->out();
}
void query(Node *x,int l,int r,int fl,int fr,Node *res){
	if(fl<=l&&r<=fr){
		merge(res,*x);
		return ;
	}
	int mid=(l+r)>>1;
	if(fl<=mid)query(x->ls,l,mid,fl,fr,res);
	if(fr>mid)query(x->rs,mid+1,r,fl,fr,res);
}
int main(){
	while(scanf("%d%d",&n,&q)!=EOF){
		init();
		for(int i=1;i<=n;i++) scanf("%d",&aa[i]);
		build(rt,1,n);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			Node ans;
			ans.init();
			query(rt,1,n,l,r,&ans);
//			ans.out();
			long long anss=-1ll;
			for(int i=0;i+2<ans.tot;i++){
				if(ans.a[i]-ans.a[i+1]<ans.a[i+2]){
					anss = (ll)ans.a[i]+(ll)ans.a[i+1]+(ll)ans.a[i+2];
					break;
				}
			}
			printf("%lld\n",anss);
		}
	}
	return 0;
}
/*
5 8
2 5 6 5 2
1 2
2 3
3 4
4 5
1 1
2 2
1 3
2 4
2 5
*/

