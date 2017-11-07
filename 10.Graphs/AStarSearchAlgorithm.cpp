/* Amit Bansal - amitbansal7 */
#include <bits/stdc++.h>
using namespace std;

void AStar(vector<pair<int, pair<int, int> > >adj[], int src, int dest, int heuristicDistFromSource, int v)
{
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	vector<int> dist(v, INT_MAX);
	vector<int> parent(v, -1);

	parent[src] = src;
	dist[src] = 0;

	pq.push(make_pair(dist[src] + heuristicDistFromSource, src));

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		if (u == dest)
			break;

		vector<pair<int, pair<int, int> > >::iterator it;
		for (it = adj[u].begin(); it != adj[u].end(); it++)
		{
			int v = it->first;
			int w = it->second.first;
			int heuristic = it->second.second;

			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v] + heuristic, v));
				parent[v] = u;
			}
		}
	}

	cout << "Distance from " << src << " to " << dest << " is " << dist[dest] << endl;
	cout << "Path is " << dest;
	int p = dest;
	while (parent[p] != p)
	{
		cout << "<-" << parent[p];
		p = parent[p];
	}
	cout << endl;
}

int main()
{
	vector<pair<int, pair<int, int> > >adj[13];

	//adj[src].push_back(make_pair(dest, make_pair(weight, heuristic)));
	adj[0].push_back(make_pair(1, make_pair(7, 9)));
	adj[0].push_back(make_pair(2, make_pair(2, 7)));
	adj[0].push_back(make_pair(3, make_pair(3, 8)));
	adj[1].push_back(make_pair(2, make_pair(3, 7)));
	adj[1].push_back(make_pair(4, make_pair(0, 10)));
	adj[2].push_back(make_pair(4, make_pair(4, 8)));
	adj[2].push_back(make_pair(8, make_pair(1, 6)));
	adj[3].push_back(make_pair(12, make_pair(2, 6)));
	adj[4].push_back(make_pair(6, make_pair(5, 6)));
	adj[7].push_back(make_pair(5, make_pair(2, 0)));
	adj[8].push_back(make_pair(7, make_pair(2, 3)));
	adj[8].push_back(make_pair(6, make_pair(3, 6)));
	adj[9].push_back(make_pair(10, make_pair(6, 4)));
	adj[9].push_back(make_pair(11, make_pair(4, 3)));
	adj[10].push_back(make_pair(11, make_pair(4, 3)));
	adj[11].push_back(make_pair(5, make_pair(5, 0)));
	adj[12].push_back(make_pair(9, make_pair(6, 4)));
	adj[12].push_back(make_pair(10, make_pair(4, 4)));

	// AStar(adj, src, dest, heuristicDistFromSource, nmberOfEdges);
	AStar(adj, 0, 5, 10, 13);
}
