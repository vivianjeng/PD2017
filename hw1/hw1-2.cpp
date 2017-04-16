#include <iostream >
using namespace std;
int main()
{
	int n, b = 0, c = 1, d = -1;
	cin >> n;
	while(d < 0){
		if(n / c == 0)
			d=b;c=c*10;b=b+1;
	}
	cout <<d<<"\n";
	return 0;
}
