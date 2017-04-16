#include <iostream >
using namespace std;
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	if(n > m)
	{
		int num = 1;
		for(int i = 1; i <= n; i++)
		{	num *= i;
			cout<<num<<endl;
		}	
		int de1 = 1;
		for(int i = 1; i <= m; i++)
			de1 *= i;
		int de2 = 1;
		for(int i = 1; i <= n - m; i++)
			de2 *= i;
		//cout << num / (de1 * de2);
	}
return 0;
}
