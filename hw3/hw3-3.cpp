#include <iostream>
using namespace std;

int main(){
	/*Initialization.*/
	int n;
	int p,d;
	float x[51], y[51], P[51];
	int sum=0;
	int people=0;
	
	/*Input data.*/
	cin>>n>>p>>d;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>P[i];
		people+=P[i];
	}
	
	bool coverFlag[n];  /*If the town is covered or not.*/
	bool station[n];    /*If there is a station in the town or not.*/
	for(int i=1;i<=n;i++){
		coverFlag[i] = false; /*The town hasn't been covered yet.*/
		station[i] = false;   /*There are no station in the town yet.*/
	}
	
	while(p>0){
		int maxCover = -1;  /*The maximum number of the covered people.*/
		int maxCoveringTown; /*Currently the town which cover the most people.*/
		for(int i=1;i <= n;i++){
			if(station[i] == false){
				int cover = 0; /*Computing all possibilities of covering people.*/
				for(int k=1;k<=n;k++){
					if((coverFlag[k] == false) &&
						(((x[i]-x[k])*(x[i]-x[k])) + ((y[i]-y[k])*(y[i]-y[k]))) <= d*d)
							cover += P[k]; 
					/*If the k town is within the radius, we add "P[k]" to "cover".*/
				}
				if(cover > maxCover){
					maxCover = cover;
					maxCoveringTown = i;
				}
				/*Saving currently maxCover and maxCoveringTown.*/ 
			}
		}
		station[maxCoveringTown] = true; /*Set a station at maxCoveringTown*/
		for(int k=1;k<=n;k++){
				if((((x[maxCoveringTown]-x[k])*(x[maxCoveringTown]-x[k]) 
				  + (y[maxCoveringTown]-y[k])*(y[maxCoveringTown]-y[k])) <= d*d) &&
				     coverFlag[k] == false){
						coverFlag[k] = true;
					/*If the town is within the radius, we set coverFlag "true".*/
				}
		}
		sum += maxCover;
		/*The summation of the covered people.*/
		cout<<maxCoveringTown<<" ";
		p--; 
		if(sum == people) break;
		/*If the whole town is covered, we break the loop.*/
	}
	if(p>0){
		for(int j=1;j<=n;j++){
			if(station[j]==false){
				cout<<j<<" ";
				p--;
				if(p==0) break;
			}
			if(p==0) break;
		}
	}
	
	/*Dealing with the situation that the whole town is covered but we can still add stations.*/
	
	cout<<sum;
	
	return 0;
}

