#include <iostream>
#define N_MAX 50
#define us unsigned short

using namespace std;

bool cabbage[N_MAX][N_MAX];
int M, N;

bool dfs(us x, us y)
{
	if (x >= M || y >= N || !cabbage[y][x]) return false;

	cabbage[y][x] = false;

	dfs(x - 1, y), dfs(x + 1, y), dfs(x, y - 1), dfs(x, y + 1);

	return true;
}

us count_earthworms()
{
	us result = 0;

	for (us i = 0; i < N; ++i)
	{
		for (us j = 0; j < M; ++j)
		{
			if (dfs(j, i)) ++result;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, K;
	int a, b;
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < K; ++i)
		{
			cin >> a >> b;
			cabbage[b][a] = true;
		}

		cout << count_earthworms() << '\n';
	}

	return 0;
}
