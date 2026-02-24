#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>


const int INF = std::numeric_limits<int>::max(); // 무한대를 위한 상수

std::vector<std::vector<std::pair<int, int>>> graph; // 그래프를 인접 리스트 형태로 저장
std::vector<int> dist; // 각 노드까지의 최단 거리 저장
std::vector<int> prev; // 각 노드의 직전 노드 저장
std::vector<bool> visited;

void dijkstra(int start)
{
	int n = graph.size();
	dist.assign(n, INF);
	prev.assign(n, -1);
	visited.assign(n, false);
	dist[start] = 0;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({0, start});

	while(!pq.empty())
	{
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (visited[u]) continue;
		visited[u] = true;

		for (const auto& edge : graph[u])
		{
			int v = edge.first;
			int weight = edge.second;

			if (dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
				prev[v] = u;
				pq.push({dist[v], v});
			}
		}
	}
}

// 경로 출력
void printPath(int node)
{
	if (node == -1) return ;
	printPath(prev[node]);
	std::cout << node << " ";
}

int main()
{
	graph = {
		{{1,4}, {2, 4}, {4, 1}},
		{},
		{{1, 6}, {3, 8}},
		{{1, 2}},
		{{2, 2}}
	};

	int start = 0;
	dijkstra(start);

	std::cout << "Node\tDistance\tPath" << std::endl;
	for(int i = 0; i < dist.size(); ++i)
	{
		std::cout << i << "\t" << dist[i] << "\t\t";
		printPath(i);
		std::cout << std::endl;
	}
	return 0;
}