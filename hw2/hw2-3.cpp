#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k; 
	/*initialization*/
	if(k == 1){ 
		for(int i = 1 ; i <= n ; i++){  
			if((n % i) == 0)    /*If i divides n.*/ 
			{
				cout << i;
				(i == n) ? cout<<"" :cout<<" ";
				/*To make sure there is no blank space behide the last number.*/
			}
		}
	}
	/*if k is 1, find all positive factors.*/
	else{
		for(int i = 2 ; i <= n ; i++){
			if((n % i) == 0){
				while((n % i) == 0){
					n /= i;
				}
				/*Iteratively dividing by i to get prime factor.*/
				cout<<i;
				if(i < n){
					cout<<" ";
				}
				/*Though n is getting smaller, it won't be less than its divisor i.
			 	 *If i is the last divisor, n will be eventually divided into 1.
			 	 *The "(i < n)" condition cannot hold. */
			} 
		}
	}
	/*if k is 2, find all positive prime factors.*/
	return 0;
}

