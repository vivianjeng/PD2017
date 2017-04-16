#include <iostream>
using namespace std;

int main(){
	/*Initialization.*/
	int n;
	int p,d;
	int chooseTwo = 2;
	float x[51], y[51], P[51];
	int sum=0;
	int maxPeople=0;
	
	/*Input data.*/
	cin>>n>>p>>d;
	
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>P[i];
		maxPeople += P[i];
	}
	
	bool coverFlag[n];  /*If the town is covered or not.*/
	bool station[n];    /*If there is a station in the town or not.*/
	for(int i=1;i<=n;i++){
		coverFlag[i] = false; /*The town hasn't been covered yet.*/
		station[i] = false;   /*There are no station in the town yet.*/
	}
	while(p>0){
		if(sum == maxPeople) break;
		if(p>1){
			int maxTwo=-1;
			int maxCoveringTown[2]; 
			for(int i=1;i<n;i++){
				if(station[i]==false){
					for(int j=i+1;j<=n;j++) {
						int cover = 0;
						if(station[j]==false){
							for(int k=1;k<=n;k++){
								if((coverFlag[k] == false) &&
							((x[i]-x[k])*(x[i]-x[k]) + (y[i]-y[k])*(y[i]-y[k])) <= d*d)
									cover += P[k]; 
					/*If the k town is within the radius, we add "P[k]" to "cover".*/
							}
							for(int k=1;k<=n;k++){
								if((coverFlag[k] == false) &&
							((x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k])) <= d*d
							&& ((x[i]-x[k])*(x[i]-x[k]) + (y[i]-y[k])*(y[i]-y[k])) > d*d)
									cover += P[k]; 
					/*If the k town is within the radius, we add "P[k]" to "cover".*/
							}
						}
						if(cover > maxTwo){
							maxTwo = cover;
							maxCoveringTown[0] = i;
							maxCoveringTown[1] = j;
						}
					}
				}
			}
			sum+=maxTwo;
			for(int k=1;k<=n;k++){
				if((coverFlag[k] == false) &&
						((x[maxCoveringTown[0]]-x[k])*(x[maxCoveringTown[0]]-x[k]) +
						 (y[maxCoveringTown[0]]-y[k])*(y[maxCoveringTown[0]]-y[k])) <= d*d)
								coverFlag[k] = true; 
				if((coverFlag[k] == false) &&
						((x[maxCoveringTown[1]]-x[k])*(x[maxCoveringTown[1]]-x[k]) +
						 (y[maxCoveringTown[1]]-y[k])*(y[maxCoveringTown[1]]-y[k])) <= d*d)
								coverFlag[k] = true; 
			}
			station[maxCoveringTown[0]] = true;
			station[maxCoveringTown[1]] = true;
			cout<<maxCoveringTown[0]<<" "<<maxCoveringTown[1]<<" ";
			p-=2;
			if(sum == maxPeople) break;
		}
		else{
			int maxCover = -1;  /*The maximum number of the covered people.*/
			int maxCoveringTown; /*Currently the town which cover the most people.*/
			for(int i=1;i <= n;i++){
				if(coverFlag[i] == false){
					int cover = 0; /*Computing all possibilities of covering people.*/
					for(int k=1;k<=n;k++){
						if((coverFlag[k] == false) &&
						((x[i]-x[k])*(x[i]-x[k]) + (y[i]-y[k])*(y[i]-y[k])) <= d*d)
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
			sum+=maxCover;
			cout<<maxCoveringTown<<" ";
			p-=1;
		}
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
	cout<<sum;
	
	return 0;
}

