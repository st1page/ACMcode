/*
询问01数列不包含101 111子串的方案数 
有趣的题 考虑最后一位增添需要对前面进行限制
等价为i-1的串增添0 长度为i-3增添001 i-4增添0011
f[i]=f[i-1]+f[i-3]+f[i-4] 
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
int M;
void madd(int &x,int y){
	x+=y; if(x>=M) x-=M;
}
struct Mat{
	int a[4][4];
	void clear(){
		memset(a,0,sizeof(a));
	}
	Mat(){
		clear();
	}
	void out(){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++) printf("%d ",a[i][j]);
			putchar('\n');
		} putchar('\n');
	}
	friend Mat operator *(Mat x,Mat y){
		Mat z;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++)
					madd(z.a[i][j], x.a[i][k]*y.a[k][j]%M);
		return z;
	}
	friend Mat operator ^(Mat x,int y){
		Mat z;
		for(int i=0;i<4;i++) z.a[i][i]=1;
		for(;y;y>>=1,x=x*x) if(y&1) z=z*x;
		return z;
	}
}trans; 
#define N 1123456
int ans[10]={1,2,4,6};
int main(){
	trans.a[0][0]=trans.a[0][2]=trans.a[0][3]=1;
	trans.a[1][0]=trans.a[2][1]=trans.a[3][2]=1;
	int n;
	while(scanf("%d%d",&n,&M)!=EOF){
		if(n<=3) {
			printf("%d\n",ans[n]%M);
			continue;
		} 
		Mat x;
		x.a[0][0]=6%M; x.a[1][0]=4%M; x.a[2][0]=2%M; x.a[3][0]=1;
		x=(trans^(n-3))*x;
		printf("%d\n",x.a[0][0]);
	}
	
}




