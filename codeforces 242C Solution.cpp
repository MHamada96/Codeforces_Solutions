#include<iostream>

#include<fstream>
#include<istream>
#include<ostream>

#include<vector>
#include<deque>
#include<set>
#include<map>
#include<queue>

#include<string>
#include<cstring>
#include<sstream>

#include<cmath>
#include <stdlib.h>
#include<iomanip>
#include<algorithm>
#include<assert.h>

using namespace std;

#define PI		3.14159265
#define OO		1e9
#define S       second
#define F       first  


int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

//fstream out("output.txt", ios::in | ios::out);
//fstream in("input.txt", ios::in | ios::out);

//#define cout out
//#define cin  in 

set<pair<int, int> > Vis;
map<int, vector<pair<int, int> > > allowed;

bool Allow(int r, int Col)
{
	for (int i = 0; i < allowed[r].size(); i++)
	if (Col >= allowed[r][i].first&&Col <= allowed[r][i].second)
		return true;

	return false;
}
int main()
{
	fast();

	int startX, startY, endX, endY, N;
	cin >> startX >> startY >> endX >> endY;
	cin >> N;

	while (N--)
	{
		int Row, left, right;

		cin >> Row >> left >> right;

		allowed[Row].push_back(make_pair(left, right));

		/*
			if (allowed[Row].F == 0 && allowed[Row].S == 0)
			allowed[Row].F = left, allowed[Row].S = right;
			else
			allowed[Row].F = min(allowed[Row].F, left), allowed[Row].S = max(allowed[Row].S, right); // enlarge ...
			*/
	}

	queue<pair<int, int> > q;

	q.push(make_pair(startX, startY));

	Vis.insert(make_pair(startX, startY));

	int siz = 0, dep = 0;

	while (!q.empty())
	{
		siz = q.size();
		while (siz--)
		{
			pair<int, int> Top = q.front();
			q.pop();

			int X = Top.first;
			int Y = Top.second;

			if (X == endX &&Y == endY)
			{
				cout << dep;
				return 0;
			}

			for (int i = 0; i < 8; i++)
			{
				int newX = X + dx[i];
				int newY = Y + dy[i];
				if (newX < 1 || newY < 1)
					continue;

				if (Vis.find(make_pair(newX, newY)) == Vis.end() && Allow(newX, newY))
				{
					Vis.insert(make_pair(newX, newY)); // mark as visited 
					q.push(make_pair(newX, newY));    //  add to queue 
				}
			}
		}

		dep++;
	}


	cout << -1;

}
