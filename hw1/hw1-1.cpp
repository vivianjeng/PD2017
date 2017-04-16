#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cout << "块獶璽俱计:" ; 
	cin >> n; //块獶璽俱计
	int rmd = n % 2; //rmd(remainder)n埃2ぇ緇计 
	
	if(rmd == 1) //璝remainder1玥计 
		cout << "块计" << 3*n + 1; 
	if(rmd == 0) //璝remainder0玥案计  
		cout << "块计" << n / 2;
	return 0;
}
