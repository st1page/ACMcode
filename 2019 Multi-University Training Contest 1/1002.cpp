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
#define M 31

struct Node {
	unsigned int bit[M];
	int pos[M];
	void init(){
		memset(bit,0,sizeof(bit));
		memset(pos,0,sizeof(pos));
	}
	Node(){	}
	void out(){
		for(int i=0;i<M;i++) {
			printf("%3d  ",pos[i]);
			for(int j=0;j<M;j++) printf("%d",(bit[i]>>j)&1);
			putchar('\n');
		}
		putchar('\n');
	}
	void cpy(Node &x){
		for(int i=0;i<M;i++) bit[i]=x.bit[i];
		for(int i=0;i<M;i++) pos[i]=x.pos[i];
	}
	void add(int key,unsigned int val){
		for(int i=M-1;i>=0;i--){
			if(!val) break;
			if((val>>i)&1){
				if(bit[i]){
					if(key>pos[i]){
						swap(pos[i],key);
						swap(bit[i],val);
					}
					val^=bit[i];
				} else {
					pos[i]=key;
					bit[i]=val;
					break;
				}
			}
		}
	}
	unsigned int query(int l){
		unsigned int res=0;
		for(int i=M-1;i>=0;i--){
			if(pos[i]>=l&&(res^(bit[i]))>res)
				res^=bit[i];
		}
		return res;
	}
}b[N];
int n,m;
unsigned int a[N];
int main(){
	int ttt=gn();
	while(ttt--){
		n=gn(); m=gn();
		for(int i=1;i<=n;i++) a[i]=gn();
		b[0].init();
		for(int i=1;i<=n;i++){
			b[i].cpy(b[i-1]);
			b[i].add(i,a[i]);
		}
		unsigned int ans = 0;
		for(int i=0;i<m;i++){
			int op=gn();
			if(op){
				n++;
				a[n]=gn()^ans;
				b[n].cpy(b[n-1]);
				b[n].add(n,a[n]);
			} else {
				int l=(gn()^ans)%n +1, r=(gn()^ans)%n+1;
				if(l>r) swap(l,r);
				ans=b[r].query(l);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}



