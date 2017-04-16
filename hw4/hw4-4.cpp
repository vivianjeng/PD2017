#include <iostream>
using namespace std;

bool FirstStep(int ,int ,int, int[50][20], int);
bool SecondStep(int ,int ,int, int[50][20],int);
void SecondArrangement(int,int,int,int[50][20],int);
void printSeat(int,int,int[50][20]);

int main(){
	int n,m;
	int getOn,getOff;
	int seatNum = 1;
	
	cin>>n>>m;
	
	int seat[50][20];
	/*    _____m_____
	 *   |           |
	 *   |           |
	 *   n           |
	 *   |           |
	 *   |___________|
	 */
	 
	for(int i=0; i < n ; i++){
		for(int j = 0; j < m ; j++){
			seat[i][j] = 0;
		}
	}
	
	while( cin >> getOn >> getOff){
		if(getOff < getOn){
			seatNum++;
			continue;
		}
		/*If the input data is invalid, we go to serve the next passenger.*/
		
		if(FirstStep(getOn,getOff,n, seat,seatNum) == true) {
			seatNum++;
			continue;
		}
		/*If there are continuous seats for a passenger, we use the function to 
		  arrange the seats.*/
		
		if(SecondStep(getOn,getOff,n, seat,seatNum) == true){
			 SecondArrangement(getOn,getOff,n,seat,seatNum);
		}
		
		/*If there are enough empty seats for a passenger to take from getting on 
		  to getting off, we use the second method arrangement function.*/
		  
		seatNum++;
	}
	
	printSeat(n,m,seat);
	/*Print out the seats.*/
	
	
	return 0;
}

bool FirstStep(int getOn,int getOff,int n, int seat[50][20], int seatNum){
		for(int i=0; i < n ;i++){
			for(int j=getOn ; j<getOff;j++){
				if(seat[i][j]!=0) break;
				/*If there are no continuous seats in j-th row,
				 *we go to the next row.*/
				  
				if(j == getOff-1){
					for(int j=getOn ; j<getOff;j++)
						seat[i][j] = seatNum;
					return true;
				}
				/*If we check til j = "getOff-1",
				 *there must be continuous seats. 
				 *We assign the passenger number to the seat,and return true.*/
			}
		}
		return false;
}

bool SecondStep(int getOn,int getOff,int n, int seat[50][20],int seatNum){
	int row = -1;
	int change = 0;
	for(int i= getOn; i < getOff; i++ ){
			for(int j=0; j < n ; j++){
				if(seat[j][i] == 0) {
					if(row != j){
						change++;
						row = j;
						if(change == 2){
							for(int k=i ; k<getOff;k++){
								if(seat[j][k]!=0) return false;
								if(k == getOff-1){
								return true;
								}
							}
						}
					}
					break;
				}
				if((seat[j][i] != 0) && j == (n-1))
					return false;
			}
		}
		/*Check if j-th column is full.
		 *If it is full, return true, or return false.*/
	return true;
}

void SecondArrangement(int getOn,int getOff,int n,int seat[50][20],int seatNum){
	int row = -1;
	int change = 0;
		for(int i= getOn; i < getOff; i++ ){
				for(int j=0; j < n ; j++){
					if(seat[j][i] == 0){
						if(change<2){
							seat[j][i] = seatNum;
							break;
						}
						if(row != j){
						change++;
						row = j;
						
						if(change == 2){
							for(int k=i ; k<getOff;k++){
								if(seat[j][k]!=0) break;
								if(k == getOff-1){
									for(int l=i ; l<getOff;l++){
										seat[j][l] = seatNum;
									}
								}
							}
						}
					}
					}
				}
		}
		/*The second method to assign the seats.*/
}

void printSeat(int n,int m,int seat[50][20]){
	for(int i=0; i < n ; i++){
		for(int j = 0; j < m ; j++){
			cout<<seat[i][j];
			if(j != (m-1)) cout<<" ";
		}
		if(i != (n-1))cout<<"\n";
	}
}
