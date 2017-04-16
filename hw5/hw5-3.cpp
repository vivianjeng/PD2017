#include <iostream>
using namespace std;

void swap(int array[],int n,int m){
	int tmp;
	tmp = array[n]; 
	array[n] = array[m];
	array[m] = tmp;
}

int main(){
	
	/*Initialization.*/
	
	int n,m;
	float threashold;
	cin>>n>>m>>threashold;
	threashold = threashold * m;
	int table[m][n];
	bool support[m];
	int confidence[n];
	int outputNumber[n];
	int outputSupport = 0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			table[i][j]=0;
			
	for(int i=0;i<n;i++){
		confidence[i]=0;
		outputNumber[i] = i+1;
	}
	
	for(int i=0;i<m;i++){
		support[i]=true;
	}
	
	/*Build the table.*/
	
	for(int i=0;i <m;i++){
		int count;
		cin>>count;
		int list[count];
		for(int j=0;j<count;j++){
			cin>>list[j];
			table[i][list[j]-1] = 1;
		}
	}

	/*Inputing the query.*/

	int suppCount;
	cin>>suppCount;
	int set[suppCount];
	bool querySet[n];
	
	for(int i=0;i<n;i++){
		querySet[i]= false;
	}
	
	for(int i=0;i<suppCount;i++){
		cin>>set[i];
		querySet[set[i]-1] = true;
	}
	
	/*Counting the value of support.*/
	
	for(int i=0;i<m;i++){
		for(int j=0;j<suppCount;j++){
			if(table[i][set[j]-1] == 0){
				support[i] = false;
				break;
			}
		}
	}
	
	
	for(int i=0;i<m;i++){
		if(support[i] == true){
			outputSupport++;
		}
	}
	
	if(outputSupport < threashold)
		return 0;
	
	
	/*Counting the number of confidence.*/
	
	for(int i=0;i<n;i++){
		if(querySet[i] == false){
			for(int j=0;j<m;j++){
				if(support[j]==true && table[j][i]==1){
					confidence[i]++;
				}
			}
		}
	}
	
	
	/*Sorting the confidence value.*/
	
	for(int i=0;i<n;i++){
		for (int j = 0; j < n - 1 - i; j++)
			if (confidence[j] < confidence[j + 1]){
				swap(confidence,j,j+1);
				swap(outputNumber,j,j+1);
			}
	}
	

	cout<<outputNumber[0]<<" "<<confidence[0]<<" "<<outputSupport;

	
	return 0;
}

