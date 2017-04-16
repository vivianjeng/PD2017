#include <iostream>
using namespace std;

int main(){
	int n,p,d;
	int x[50], y[50], P[50];
	int sum=0;
	
	cin>>n>>p>>d;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>P[i];
	}
	
	bool coverFlag[n];
	for(int i=1;i<=n;i++){
		coverFlag[i] = false;
	}
	
	for(int j=0;j < p;j++){
		int maxCover = -1;
		int maxCoveringTown;
		for(int i=1;i <= n;i++){
			if(coverFlag[i] == false){
				int cover = 0;
				for(int k=1;k<=n;k++){
					if((coverFlag[k] == false) &&
						((x[i]-x[k])*(x[i]-x[k]) + (y[i]-y[k])*(y[i]-y[k])) <= d*d)
							cover += P[k];
				}
				if(cover > maxCover){
					maxCover = cover;
					maxCoveringTown = i;
				} 
			}
		}
		for(int k=1;k<=n;k++){
				if(((x[maxCoveringTown]-x[k])*(x[maxCoveringTown]-x[k]) 
				  + (y[maxCoveringTown]-y[k])*(y[maxCoveringTown]-y[k])) <= d*d)
					coverFlag[k] = true;
		}
		sum += maxCover;
		cout<<maxCoveringTown<<" "; 
	}
	cout<<sum;
	return 0;
}
