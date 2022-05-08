#include <bits/stdc++.h>
using namespace std;

const int INF = (1<<30)-1;

int DX[4] = {1, 0, -1, 0};
int DY[4] = {0, 1, 0, -1};

void solve() {

	int h,w; cin>>h>>w;
	vector<string> G(h);
	for(int i=0;i<h;i++) cin>>G[i];

	int sx=0,sy=0;
	int gx=0,gy=0;
	for(int i=0;i<h;i++) for(int j=0;j<w;j++){
		if(G[i][j]=='S') sx=i, sy=j;
		if(G[i][j]=='G') gx=i, gy=j;
	}

	vector<vector<int>> dist(h,vector<int>(w,INF));
	auto dfs = [&](auto dfs, int px, int py)->void{
		for(int i=0;i<4;i++){
			int nx = px+DX[i];
			int ny = py+DY[i];
			if(0<=nx&&nx<h&&0<=ny&&ny<w&&G[nx][ny]!='#'){
				if(dist[px][py]+1<dist[nx][ny] && dist[px][py]+1<=dist[gx][gy]){
					dist[nx][ny] = dist[px][py]+1;
					dfs(dfs, nx,ny);
				}
			}
		}
	};

	dist[sx][sy] = 0;
	dfs(dfs, sx, sy);

	cout<<dist[gx][gy]<<endl;

	return;
}

int main() {
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);

	int t;
	t=1;
	for(int i=0;i<t;i++) solve();

	return 0;
}
