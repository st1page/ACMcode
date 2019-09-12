#include<cstdio>
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
#define M 62
#define N 1123
struct LinerBase{
	ll a[M];
	int w[M];
	void add(ll x,int y){
		for(int i=M-1;i>=0;i--) if((x>>i)&1){
			if(a[i]) x^=a[i];
			else {
				a[i]=x;
				w[i]=y;
				break;
			}
		}
	}
}b;
struct data{
	ll x;
	int y;
}a[N];
bool cmp(data x,data y){
	return x.y>y.y;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%lld%d",&a[i].x,&a[i].y);
	}	
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++) b.add(a[i].x,a[i].y);
	int ans=0;
	for(int i=0;i<M;i++) ans+=b.w[i];
	printf("%d\n",ans);
}




