#include <iostream>
using namespace std;

int main() {
	int n,m,p,c;
	cin>>n>>m>>p>>c;

	int companyx[n];
	int companyy[n];
	int storex[m];
	int storey[m];
	int total_revenue=0;
	int needs[m]; //Store's needs
	int capacity[n]; //Center's capacity
	int unsatisfied=0;
	int distance[m][n]; //distance between Stores and Centers
	bool j_star_exist = true;
	int j_star[m];
	

	for(int i=0;i<n;i++){
		cin>>companyx[i]>>companyy[i];
	}
	for(int i=0;i<m;i++){
		cin>>storex[i]>>storey[i];
	}
	
	for(int i=0;i<m;i++){
		cin>>needs[i];
		unsatisfied += needs[i];
	}
	
	for(int i=0;i<n;i++){
		cin>>capacity[i];
	}

	// Count distance between Stores and Centers
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp_distance = 0 ;
			if(companyx[j] > storex[i])
				tmp_distance += companyx[j] - storex[i];
			else
				tmp_distance += storex[i] - companyx[j];
			if(companyy[j] > storey[i])
				tmp_distance += companyy[j] - storey[i];
			else
				tmp_distance += storey[i] - companyy[j];

			distance[i][j] = tmp_distance;
		}
	}
	
	while(j_star_exist){
		int j_star_count = 0;
		for(int i = 0 ; i < m ; i++){
			int minDistance = 400;
			int minCenter = -1;
			int maxRemain = 0;
			if(needs[i] > 0){
				for(int j = 0; j < n ; j++){
					if(capacity[j] > 0 && (p-c*distance[i][j]) > 0){
						j_star_count++ ;
						if(distance[i][j] < minDistance){
							minDistance = distance[i][j];
							minCenter = j;
							maxRemain = capacity[j];
						}
						else if(distance[i][j] == minDistance && capacity[j] > maxRemain){
							minCenter = j;
							maxRemain = capacity[j];
						}
					}
				}
				j_star[i] = minCenter;
			}
		}
		if(j_star_count == 0){
			break;
		}

		int minDistance = 400;
		int minStore = -1;
		int maxNeed = 0;
		for (int i = 0; i < m; i++)
		{	
			if(j_star[i] != -1){
				if(distance[i][j_star[i]] < minDistance){
					minDistance = distance[i][j_star[i]];
					minStore = i;
					maxNeed = needs[i];
				}
				else if(distance[i][j_star[i]] == minDistance && needs[i] > maxNeed){
					minStore = i;
					maxNeed = needs[i];
				}
			}
		}
		
		int complement = 0;

		if(needs[minStore] > capacity[j_star[minStore]]){
			needs[minStore] -= capacity[j_star[minStore]];
			complement = capacity[j_star[minStore]];
			capacity[j_star[minStore]] = 0;
		}
		else{
			capacity[j_star[minStore]] -= needs[minStore];
			complement = needs[minStore];
			needs[minStore] = 0;
		}
		
		total_revenue += (p - c*distance[minStore][j_star[minStore]])*complement;
		unsatisfied -= complement;
		if(needs[minStore] == 0){
			j_star[minStore] = -1;
		}
	}
	
	cout<<total_revenue<<" "<<unsatisfied;

	return 0;
}