#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 1000015
#define M 30

struct Node {
	int bit[M];
	Node *ls,*rs;
	void init(){
		memset(bit,0,sizeof(bit));
	}
	node(){	}
	void out(){
		for(int i=0;i<M;i++) {
			for(int j=0;j<M;j++) printf("%d",(bit[i]>>j)&1);
			putchar('\n');
		}
		putchar('\n');
	}
	void add(int x){
		for(int i = M-1;i>=0;i--){
			if(!x) break;
			if((x>>i)&1){
				if(bit[i]) x^=bit[i];
				else {
					bit[i]=x;
					break;
				}
			}
		}
	}
	int query(){
		int res=0;
		for(int i=M-1;i>=0;i--){
			if((res^(bit[i]))>res)
				res^=bit[i];
		}
		return res;
	}
}pool[N<<1],*root,*pp,ans;
int nn,n,m;
int a[500005];
void init(){
	root=pp=&pool[0];
}
void merge(Node &res,Node *y){
	for(int i=0;i<M;i++) res.add(y->bit[i]);
} 
void merge(Node &res,Node *x,Node *y){
	for(int i=0;i<M;i++) res.bit[i] = x->bit[i];
	for(int i=0;i<M;i++) res.add(y->bit[i]);
} 
void build(Node *x,int l,int r){
	if(l==r){
		x->init();
		if(l<=nn) x->add(a[l]);
		return ;
	}
	int mid = (l+r)>>1;
	x->ls=++pp;
	x->rs=++pp;
	build(x->ls,l,mid);
	build(x->rs,mid+1,r);
	if(l<=nn) merge(*x,x->ls,x->rs);
}
void change(Node *x,int l,int r,int y){
	if(l==r){
		x->add(a[y]);
		return ;
	}
	int mid = (l+r)>>1;
	if(y<=mid) change(x->ls,l,mid,y);
	else change(x->rs,mid+1,r,y);
	merge(*x,x->ls,x->rs);
}
void query(Node *x,int l,int r,int fl,int fr,Node &res){
	if(fl<=l&&r<=fr){
		merge(res,x);
		return;
	}
	int mid=(l+r)>>1;
	if(fl<=mid)query(x->ls,l,mid,fl,fr,res);
	if(fr>mid)query(x->rs,mid+1,r,fl,fr,res);
	return ;
}
struct Q{
	int a,b,c;
}q[500005];
int main(){
	int ttt=gn();
	while(ttt--){
		init();
		n=nn=gn(); m = gn();
		for(int i=1;i<=n;i++) a[i]=gn();
		for(int i=0;i<m;i++){
			if(q[i].a=gn()){
				a[++n]=gn();
			} else {
				q[i].b=gn(); q[i].c=gn();
			}
		}
		build(root,1,n);
		int aans = 0;
		for(int i=0;i<m;i++){
			if(q[i].a){
				nn++; a[nn]^=aans;
				change(root,1,n,nn);
			} else {
				int l=(q[i].b^aans)%nn +1, r=(q[i].c^aans)%nn+1;
				if(l>r) swap(l,r);
				ans.init();
				query(root,1,n,l,r,ans);
				aans=ans.query();
				printf("%d\n",aans);
			}
		}
	}
	return 0;
}



