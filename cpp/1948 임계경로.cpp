#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001
using namespace std;

class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> v[MAX];
vector<Edge> v1[MAX];  //역추적을 위한 

void topologySort() {
	queue<int> q;
	q.push(start); //시작점 노드 큐에 삽입
	while (!q.empty()) { //더이상 방문할 노드가 없을 때까지
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			Edge y = Edge(v[x][i].node, v[x][i].time);
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x];
			}
			if (--inDegree[y.node] == 0) {
				q.push(y.node);
			}
		}
	}
	int cnt = 0; //결과를 역추적
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < v1[y].size(); i++) {
			Edge x = Edge(v1[y][i].node, v1[y][i].time); 
			if (result[y] - result[x.node] == x.time) { //임계경로에 포함되는지 확인
				cnt++;
				if (c[x.node] == 0) { //한번씩 담아 추적
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}
	printf("%d\n%d", result[finish], cnt);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(Edge(b, c));
		v1[b].push_back(Edge(a, c));
		inDegree[b]++;
	}
	cin >> start >> finish;
	topologySort();
}
