#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
#define N 112345
typedef long long ll;

int gn(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int diff(int x,int y){
    return x>y? x-y: y-x;
}
int a[N];
int n;
bool check(int z){
    int low = 0, high = 1e9;
    for(int i=1;i<n;i++){
        int x = a[i-1], y = a[i];
        if(x==-1&&y==-1) continue;
        if(x!=-1&&y!=-1){
            if(diff(x,y)>z) return false;
        } else if(x==-1){
            low = max(low, y-z);
            high = min(high, y+z);
        } else if(y==-1){
            low = max(low, x-z);
            high = min(high, x+z);
        }
    }
    return (low<=high);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int l=-1, r = 1e9;
        while(l+1<r){
            int mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        int z = r;
        int low = 0, high = 1e9;
        for(int i=1;i<n;i++){
            int x = a[i-1], y = a[i];
            if(x==-1&&y==-1) continue;
            if(x!=-1&&y!=-1){
                if(diff(x,y)>z) return false;
            } else if(x==-1){
                low = max(low, y-z);
                high = min(high, y+z);
            } else if(y==-1){
                low = max(low, x-z);
                high = min(high, x+z);
            }
        }
        printf("%d %d\n",z,low);
    }
    return 0;
}