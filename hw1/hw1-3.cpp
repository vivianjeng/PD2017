#include <iostream>
using namespace std;

int main(){
	int n;
	int middle;
	cin>>n;
	int a3, a2, a1, a0;
	a3 = n/1000;
	n = n - a3*1000;
	a2 = n/100;
	n = n - a2*100;
	a1 = n/10;
	n = n-a1*10;
	a0 = n;
	middle = 10*a2+a1;
	middle = middle*middle;
	
	if(middle/1000==0) {
		cout<<"0";
		if(middle/100==0){
			cout<<"0";
			if(middle/10==0){
				cout<<"0";
				if(middle==0)
					cout<<"0";
			}
		}
	}
	if(middle!=0)
	cout<<middle;
	return 0;
}

