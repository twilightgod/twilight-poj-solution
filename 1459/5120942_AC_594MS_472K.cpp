//----------------------------------------------------------------------------
// Dinic? Dinits? 法 (最大流)
//
// 容量付きグラフ G 上での Src から Dest への最大流量を求める
//   - グラフは隣接行列で渡すこと。G は破壊されます。
//   - 流量だけでなくFlow自体が欲しいときは G の容量が減ってる部分を見る
//
// 計算量は
//   - O(V^2 E) ただし隣接行列なので E=V^2になっちゃってます
//       # 1ステップでSrc→Destの最短路が1以上増えるので、
//       # 繰り返し回数は高々 V 回。で、BFS+DFS は O(VE)。
//
// アルゴリズムの概略
//   以下を繰り返す Ford-Fulkerson 法のバリエーション
//     1. とりあえず流せるだけ流す (*)
//     2. 残余グラフ（1.でf流した辺の容量をf減らし、
//        逆向き辺の容量をf増やしたグラフ）を作る
//
//   Dinic法では、(*) としてこんな感じにする。
//     1. G のうち "Srcからの距離kの頂点とk+1の頂点を結ぶ辺" のみを考える
//        このような辺だけ残したグラフ（Layered Graph）上のSrcからDstへのパスは
//        どれをとっても必ず元の G 上での最短路になっている
//     2. DFS で Src から Dest へのパスを求めて流せるだけ流す
//     3. 2.を繰り返してとにかく流せるだけ流す
//----------------------------------------------------------------------------

#include <vector>
#include <limits>
using namespace std;

typedef int                        Vert;
typedef int                        Capacity;
typedef vector< vector<Vert> >     Layer;
typedef vector< vector<Capacity> > Graph;

// 「v からはじまる」「it～end の辺を使った」パスを作ってそこに流せるだけ流す
Capacity dfs( Graph& G, Vert v, Layer::iterator it, Layer::iterator end,
              Capacity mf = numeric_limits<Capacity>::max() )
{
	if( it == end )
		return mf;
	for(int i=0; i!=it->size(); ++i)
		if( G[v][(*it)[i]] )
			if( Capacity f = dfs(G, (*it)[i], it+1, end, min(mf,G[v][(*it)[i]]) ) )
			{
				G[v][(*it)[i]] -= f;
				G[(*it)[i]][v] += f;
				return f;
			}
	return 0;
}

Capacity dinic( Graph& G, int Src, int Dest )
{
	for( Capacity totalFlow = 0 ;; )
	{
		// L[k] == Src から k ステップで行ける頂点の集合。BFSで求める。
		Layer L(1);

		L.back() = vector<Vert>(1,Src);

		vector<bool> reached(G.size());
		reached[Src] = true;
		while( !reached[Dest] && !L.back().empty() ) {
			L.resize( L.size()+1 );
			vector<Vert> &l0=L[L.size()-2], &l1=L[L.size()-1];
			for(int i=0; i!=l0.size(); ++i)
				for(Vert u=0; u!=G.size(); ++u)
					if( G[l0[i]][u] && !reached[u] )
						l1.push_back(u), reached[u]=true;
		}

		L.back() = vector<Vert>(1, Dest);

		// Dest までたどりつけなくなったので最大流の計算完了
		if( !reached[Dest] )
			return totalFlow;

		// たどりつける場合はDFSで流しまくる
		while( int f = dfs(G, Src, L.begin()+1, L.end()) )
			totalFlow += f;
	}
}

//----------------------------------------------------------------------------
// PKU 1459
//----------------------------------------------------------------------------

#include <iostream>
#include <locale>

int main()
{
	cin.imbue( std::locale("C") );
	for(int n,np,nc,m; cin>>n>>np>>nc>>m;)
	{
		// 0: src, 1: dst, 2: ...
		Graph g(n+2, vector<Capacity>(n+2));

		while(m--)
		{
			int u, v, z; char _;
			cin >> _ >> u >> _ >> v >> _ >> z;
			g[u+2][v+2] = z;
		}

		while(np--)
		{
			int u, z; char _;
			cin >> _ >> u >> _ >> z;
			g[0][u+2] = z;
		}

		while(nc--)
		{
			int u, z; char _;
			cin >> _ >> u >> _ >> z;
			g[u+2][1] = z;
		}

		cout << dinic(g, 0, 1) << endl;
	}
}

