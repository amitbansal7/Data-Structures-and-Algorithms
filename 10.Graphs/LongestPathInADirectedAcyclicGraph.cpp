/* Amit Bansal - @amitbansal7 */
#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#define NINF INT_MIN
using namespace std;
using namespace std;

/* Longest simple path in directed acyclic graph in O(V+E) */

void TopologicalSort(vector <pair<int, int> >adj[], int s, bool visited[], stack <int> &S)
{
	visited[s] = true;

	vector<pair<int, int> >::iterator it;
	for (it = adj[s].begin(); it != adj[s].end(); it++)
		if (!visited[it->first])
			TopologicalSort(adj, it->first, visited, S);


	S.push(s);
}

void LSPDAG(vector <pair<int, int> >adj[], int s, int v)
{
	stack <int> S;
	bool visited[v];
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < v; i++)
		if (!visited[i])
			TopologicalSort(adj, i, visited, S);

	int dist[v];

	for(int i=0;i<v;i++)
		dist[i] = NINF;

	dist[s] = 0;

	while (!S.empty())
	{
		int u = S.top();
		S.pop();

		if (dist[u] != NINF)
		{
			vector <pair<int, int> >::iterator it;
			for (it = adj[u].begin(); it != adj[u].end(); ++it)
				if (dist[it->first] < dist[u] + it->second)
					dist[it->first] = dist[u] + it->second;
		}

	}

	for (int i = 0; i < v; i++)
		(dist[i] == NINF) ? cout << "-INF " : cout << dist[i] << " ";

	printf("\n");
}

int main()
{
	vector <pair<int, int> >adj[6];

	adj[0].push_back(make_pair(1, 5));
	adj[0].push_back(make_pair(2, 3));
	adj[1].push_back(make_pair(3, 6));
	adj[1].push_back(make_pair(2, 2));
	adj[2].push_back(make_pair(4, 4));
	adj[2].push_back(make_pair(5, 2));
	adj[2].push_back(make_pair(3, 7));
	adj[3].push_back(make_pair(5, 1));
	adj[3].push_back(make_pair(4, -1));
	adj[4].push_back(make_pair(5, -2));

	LSPDAG(adj, 1, 6);

	return 0;
}
