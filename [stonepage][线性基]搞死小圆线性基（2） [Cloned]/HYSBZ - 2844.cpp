/*
一个大小为n向量组，消元为大小为k的基，则每一种结果出现次数为2^(n-k)次
注意计算rank时和计算kth一样，要进行重构。 
题目有问题？可能无解？ 
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
#define K 31
struct LinerBase{
	int a[K];
	int tot;
	int siz;
	void add(int x){
		for(int i=K-1;i>=0;i--) if((x>>i)&1){
			if(a[i]) x^=a[i];
			else {
				siz++;
				a[i]=x;
				break;
			}
		}
	}
	void rebuild(){
		for(int i=0;i<K;i++) if(a[i])
			for(int j=i+1;j<K;j++) if((a[j]>>i)&1) a[j]^=a[i];
			
	}
	int rank(int x){
		int res=0;
		int cnt=0;
		for(int i=0;i<K;i++) {
			if(a[i]){
				if((x>>i)&1)res|=(1<<cnt);
				if(a[i]) cnt++;
			}
		
		}
		return res;
	}
}b;
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int x; scanf("%d",&x);
		b.add(x); 
	}
	b.rebuild();
	int x; scanf("%d",&x);
	int ans=b.rank(x)%10086;
	for(int i=0;i<n-b.siz;i++){
		ans<<=1;
		if(ans>=10086) ans-=10086;
	}
	ans+=1; if(ans==10086) ans=0;
	printf("%d\n",ans);
}




