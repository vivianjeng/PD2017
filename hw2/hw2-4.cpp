#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	/*Initialization.*/
	for(int i = 2 ; i <= n ; i++){
		if((n % i) == 0){
			int count = 0;
			while((n % i) == 0){
				count++;
				n /= i;
			}
			/*Count the power of i by iteratively dividing by i.*/
			cout<<i;
			if(count > 1){
				cout<<" ^ "<<count;
			}
			/*If the power of i is more than 1, print the count.*/
			if(i < n){
				cout<<" * ";
			}
			/*Though n is getting smaller, it won't be less than its divisor i.
			 *If i is the last divisor, n will be eventually divided into 1.
			 *The "(i < n)" condition cannot hold. */
		}
	} 
	return 0;
}

