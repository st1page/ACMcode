#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

ll gn(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
#define N 1123456
const ll MOD = 1e9+7;

struct Mat{
	ll a[5][5];
	void clear(){
		memset(a,0,sizeof(a));
	}
	Mat(){
		clear();
	}
	void out(){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++) printf("%d ",a[i][j]);
			putchar('\n');
 		} putchar('\n');
	}
	friend Mat operator*(Mat x,Mat y){
		Mat res;
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				for(int k=0;k<5;k++){
					res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%MOD;
				}
		return res;
	}
	friend Mat operator^(Mat x,ll y){
		Mat res;
		for(int i=0;i<5;i++) res.a[i][i]=1;
		for(;y;y>>=1,x=x*x) if(y&1ll) res=res*x;
		return res;  
	}
}trans,ans;
ll n;
int main(){
	while(scanf("%lld",&n)!=EOF){
		ll ax,ay,bx,by,a0,b0;
		a0=gn()%MOD, ax=gn()%MOD, ay=gn()%MOD;
		b0=gn()%MOD, bx=gn()%MOD, by=gn()%MOD;
		if(n==0) {
			puts("0");
			continue;
		}
		trans.clear();
		trans.a[0][0]=ax; trans.a[0][4]=ay;
		trans.a[1][1]=bx; trans.a[1][4]=by;
		trans.a[2][0]=ax*by%MOD; trans.a[2][1]=ay*bx%MOD; trans.a[2][2]=ax*bx%MOD; trans.a[2][4]=ay*by%MOD;
		trans.a[3][0]=ax*by%MOD; trans.a[3][1]=ay*bx%MOD; trans.a[3][2]=ax*bx%MOD; trans.a[3][3]=1; trans.a[3][4]=ay*by%MOD;
		trans.a[4][4]=1;
		ans.clear();
		ans.a[0][0]=a0;
		ans.a[1][0]=b0;
		ans.a[2][0]=a0*b0%MOD;
		ans.a[3][0]=a0*b0%MOD;
		ans.a[4][0]=1;
		ans=(trans^(n-1))*ans;
		printf("%lld\n",ans.a[3][0]);
	}
	return 0;
}

