#include <iostream>
using namespace std;

int main(){int a,b,c;
	cin>>a>>b>>c;
	int min = c;
	if(a <= b && a <= c)
		min = a;
	else if(b <= c)
		min = b;
	cout<<min;
	return 0;
}

