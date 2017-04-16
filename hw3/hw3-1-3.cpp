#include <iostream>
using namespace std;

int main(){
	bool hasBadRatio = false;
	for(int num = 1; num < 100; num ++)
	{
		for(int deno = 1; deno < 100; deno ++)
		{
		float r = static_cast <float >(num) / deno;
		if(num != deno * r)
		{
			cout << num << " " << deno << " " << r << "\n";
			hasBadRatio = true;
			break;
		}
		}
		if(hasBadRatio == true)
		break;
	}
	return 0;
}

