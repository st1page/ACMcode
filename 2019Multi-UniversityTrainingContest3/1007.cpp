#include<cstdio>
#include<cstring>
#include<algorithm>
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
#define N 212345
int val[N];
struct data{
	int x,id;
}a[N];
bool cmp1(data x,data y){
	return x.x<y.x;
}
bool cmp2(data x,data y){
	return  x.id<y.id;
}
struct node{
	node *ls,*rs;
	ll sum;
	int tot;
}tr[N<<2],*rt,*p;
void init(){
	rt=p=tr;
}
void pushup(node *x){
	x->tot = x->ls->tot + x->rs->tot;
	x->sum = x->ls->sum + x->rs->sum;
}
void build(node *x,int l,int r){
	if(l==r) {
		x->sum=x->tot=0;
		return ;
	}
	x->ls = ++p;
	x->rs = ++p;
	int mid = (l+r)>>1;
	build(x->ls,l,mid);
	build(x->rs,mid+1,r);
	pushup(x);
	return ;
}
void change(node *x,int l,int r,int id){
	if(l==r){
		x->tot=1;
		x->sum=val[id];
		return ;
	}
	int mid=(l+r)/2;
	if(id<=mid) change(x->ls,l,mid,id);
	else change(x->rs,mid+1,r,id);
	pushup(x);
}
ll query(node *x,int l,int r,ll y){
	if(l==r) return 0;
	int mid=(l+r)/2;
	if(x->ls->sum>y) return query(x->ls,l,mid,y);
	else return x->ls->tot + query(x->rs,mid+1,r,y - x->ls->sum);
}
int n;
ll m;
int main(){
	int T=gn();
	while(T--){
		init();
		n=gn(); m=gn();
		for(int i=1;i<=n;i++) a[i].x=gn(), a[i].id=i;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++) {
			val[i]=a[i].x;
			a[i].x=i;
		}
		sort(a+1,a+1+n,cmp2);
		build(rt,1,n);
		for(int i=1;i<=n;i++){
			printf("%d ",i-1-query(rt,1,n,m-val[a[i].x]));
			change(rt,1,n,a[i].x);
		}
		putchar('\n');
	}
	return 0;
}




