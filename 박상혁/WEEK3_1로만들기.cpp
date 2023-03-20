#include <iostream>
#define us unsigned short
#define N_MAX 1'000'000

using namespace std;

us cal_count[N_MAX + 1] = { 0, 0, 1, 1, 2 };

int main()
{
	int N;
	cin >> N;

	for (int i = 5; i <= N; ++i)
	{
		if (i % 3)
		{
			cal_count[i] = i & 1 ? (cal_count[i - 1] + 1) : (min(cal_count[i >> 1], cal_count[i - 1]) + 1);
		}
		else
		{
			cal_count[i] = i & 1 ? (min(cal_count[i / 3], cal_count[i - 1]) + 1) : min(min(cal_count[i / 3], cal_count[i - 1]), cal_count[i >> 1]) + 1;
		}
	}

	cout << cal_count[N];

	return 0;
}
