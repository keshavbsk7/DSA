#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>adj={{},{},{3},{1},{0,1},{0,2}};
vector<int> topo(int v)
{
	int indegree[v]={0};
	for(int i=0;i<v;i++)
	{
		for(auto it:adj[i]){
			indegree[it]++;
		}
	}
	queue<int> q;
	for(int i=0;i<v;i++)
	{
		if(indegree[i]==0) q.push(i);
	}
	vector<int>topo;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		topo.push_back(node);
		for(auto i:adj[node])
		{
			indegree[i]--;
			if(indegree[i]==0) q.push(i);
		}
	}
	return topo;
}
int main()
{
	vector<int>res;
	res=topo(6);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
}