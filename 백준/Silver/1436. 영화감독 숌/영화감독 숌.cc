#include<iostream>
using namespace std;

int N, ans, cnt, temp;

int main()
{
	
	cin >> N;

	ans = 0;
	cnt = 0;

	while (cnt != N)
	{
		ans++;
		temp = ans;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else temp /= 10;
		}
	}
	cout << ans;
}