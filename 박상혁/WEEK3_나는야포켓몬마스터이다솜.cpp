#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define MAX_LEN 20
#define N_MAX 100'000

using namespace std;

char pokemon[N_MAX + 1][MAX_LEN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	char input[MAX_LEN + 1] = "";

	int N, M;
	cin >> N >> M;
	
	unordered_map<string, int> LazyDasom;

	for (int i = 1; i <= N; ++i)
	{
		cin >> pokemon[i];
		LazyDasom.insert(make_pair(string(pokemon[i]), i));
	}

	int index;
	while (M--)
	{
		cin >> input;
		if (*input <= '9')
		{
			index = atoi(input);
			cout << pokemon[index] << '\n';
		}
		else
		{
			cout << LazyDasom[string(input)] << '\n';
		}		
	}

	return 0;
}
