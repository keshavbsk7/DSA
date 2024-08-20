#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<vector<int>>adj={{},{},{3},{1},{0,1},{0,2}};
void dfs(int node,int vis[],stack<int> &st)
{
	vis[node]=1;
	for(auto i:adj[node])
	{
		if(!vis[i])
		dfs(i,vis,st);
	}
	st.push(node);
}
vector<int> toposort(int v)
{
	int vis[v]={0};
	stack<int> st;
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
		{
			dfs(i,vis,st);
		}
	}
	vector<int> ans;
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}
int main()
{
	vector<int>res=toposort(6);
	for(auto i:res)
	{
		cout<<i<<" ";
	}
}