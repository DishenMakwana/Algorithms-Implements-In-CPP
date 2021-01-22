#include "bits/stdc++.h"
#define int long long int
#define IOS                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
using namespace std;

int log2(int n)
{
	return (n == 1) ? 0 : 1 + log2(n / 2);
}

int minimax(int depth, int nodeIndex, bool isMax, int scores[], int h)
{
	if (depth == h)
	{
		return scores[nodeIndex];
	}

	if (isMax)
	{
		return max(minimax(depth + 1, nodeIndex * 2, false, scores, h), minimax(depth + 1, nodeIndex * 2 + 1, false, scores, h));
	}
	else
	{
		return min(minimax(depth + 1, nodeIndex * 2, true, scores, h), minimax(depth + 1, nodeIndex * 2 + 1, true, scores, h));
	}
}

int32_t main()
{
	IOS;
	int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};

	int n = sizeof(scores) / sizeof(scores[0]);
	int h = log2(n);

	int res = minimax(0, 0, true, scores, h);

	cout << "The optimal value is : " << res << endl;
	return 0;
}