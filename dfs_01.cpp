#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
//const int MOD = 1000000007;

using ll = long long;

const int INF = (1<<30)-1;
const ll LINF = (1LL<<62)-1;

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

struct state {
	int x, y, dir;
};

int main() {
	int n; cin>>n;
    int H, W, sx, sy, gx, gy;
	H=n, W=n;
	cin >> sx >> sy >> gx >> gy;
	--sx, --sy, --gx, --gy;
	vector<string> S(n, string(' ',W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin>>S[i][j];

	vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));

	deque<state> deq;
	for (int i = 0; i < 4; ++i) {
		dist[sx][sy][i] = 0;
		deq.push_back({ sx, sy, i });
	}

	int shortest = INF;
	while (!deq.empty()) {
		state p = deq.front(); deq.pop_front();
		if(shortest<dist[p.x][p.y][p.dir]) break;
		for (int i = 0; i < 4; ++i) {
			int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int cost = dist[p.x][p.y][p.dir];
            if(p.dir != i) cost++;

			if (0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.' && dist[nx][ny][i] > cost) {
				dist[nx][ny][i] = cost;
				if (p.dir != i) deq.push_back({ nx, ny, i });
				else deq.push_front({ nx, ny, i });
				if(nx==gx&&ny==gy) shortest = min(shortest, cost);
			}
		}
	}
	int answer = INF;
	for (int i = 0; i < 4; ++i) {
		answer = min(answer, dist[gx][gy][i]);
	}
	if(answer==INF){
		cout<<-1<<endl;
		return 0;
	}
    //曲がった回数をカウントしているので，移動回数は+1
	cout << answer+1 << endl;
	return 0;
}
    


