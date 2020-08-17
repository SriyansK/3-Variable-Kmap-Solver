#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define pp pop_back
#define fr first
#define sc second
#define ins insert
using namespace std;

//const ll maxN =;
int a[2][4];
int g[2][4];
vector <pair<int,int> > v[100];
vector <string> v1[100];
int idx=0;

int eight()
{
	int count=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<4;j++)
			if(a[i][j]==1)
				count++;
	if(count==8)
		for(int i=0;i<2;i++)
			for(int j=0;j<4;j++)
			{
				g[i][j]=8;
				v[idx].pb(mp(i,j));
			}
	idx++;
	return 0;
}

int four()
{
	for(int i=0;i<2;i++)
	{
		int count=0;
		for(int j=0;j<4;j++)
			if(a[i][j]==1 && g[i][j]!=8)
				count++;
		if(count==4)
		{
			for(int j=0;j<4;j++)
			{
				g[i][j]=4;
				v[idx].pb(mp(i,j));
			}
			idx++;
		}
	}

	for(int j=0;j<4;j++)
	{
		int count=1;
		if(a[0][j]==1 && g[0][j]==-1)
		{
			if(a[1][j]==1)
				count++;
			if(a[0][j+1]==1)
				count++;
			if(a[1][j+1]==1)
				count++;
		}
		if(count==4)
		{
			v[idx].pb(mp(0,j));
			v[idx].pb(mp(0,j+1));
			v[idx].pb(mp(1,j));
			v[idx].pb(mp(1,j+1));
			g[0][j]=4;
			g[0][j+1]=4;
			g[1][j]=4;
			g[1][j+1]=4;
			idx++;
		}

		if(j==3)
		{
			int count=0;
			if(a[0][0]==1)
				count++;
			if(a[1][0]==1)
				count++;
			if(a[0][3]==1 && g[0][3]==-1)
				count++;
			if(a[1][3]==1 && g[1][3]==-1)
				count++;
			if(count==4)
			{
				g[0][0]=4;
				g[0][3]=4;
				g[1][0]=4;
				g[1][3]=4;
				v[idx].pb(mp(0,0));
				v[idx].pb(mp(0,3));
				v[idx].pb(mp(1,0));
				v[idx].pb(mp(1,3));
				idx++;
			}
		}
	}
	return 0;
}

int two()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
		{
			int flag=0;
			if(a[i][j]==1 && a[i][j+1]==1 && j<3)
			{
				if(g[i][j]==-1)
				{
					flag=1;
					g[i][j]=2;
				}
				if(g[i][j+1]==-1)
				{
					flag=1;
					g[i][j+1]=2;
				}
			}
			if(flag==1)
			{
				v[idx].pb(mp(i,j));
				v[idx].pb(mp(i,j+1));
				idx++;
			}
		}
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<4;j++)
		{
			int flag=0;
			if(a[i][j]==1 && a[i+1][j]==1)
			{
				if(g[i][j]==-1)
				{
					flag=1;
					g[i][j]=2;
				}
				if(g[i+1][j]==-1)
				{
					flag=1;
					g[i+1][j]=2;
				}
			}
			if(flag==1)
			{
				v[idx].pb(mp(i,j));
				v[idx].pb(mp(i+1,j));
				idx++;
			}
		}
	}

	if(a[0][0]==1 && a[0][3]==1)
	{
		int flag=0;
		if(g[0][0]==-1)
		{
			flag=1;
			g[0][0]=2;
		}
		if(g[0][3]==-1)
		{
			flag=1;
			g[0][3]=2;
		}
		if(flag==1)
		{
			v[idx].pb(mp(0,0));
			v[idx].pb(mp(0,3));
			idx++;
		}
	}

	if(a[1][0]==1 && a[1][3]==1)
	{
		int flag=0;
		if(g[1][0]==-1)
		{
			flag=1;
			g[1][0]=2;
		}
		if(g[1][3]==-1)
		{
			flag=1;
			g[1][3]=2;
		}
		if(flag==1)
		{
			v[idx].pb(mp(1,0));
			v[idx].pb(mp(1,3));
			idx++;
		}
	}
	return 0;
}

int one()
{
	for(int i=0;i<2;i++)
		for (int j=0;j<4;j++)
			if(a[i][j]==1 && g[i][j]==-1)
			{
				g[i][j]=1;
				v[idx].pb(mp(i,j));
				idx++;
			}
	return 0;
}

int print()
{
	for(int i=0;i<idx;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j].fr==0 && v[i][j].sc==0)
				v1[i].pb("000");
			if(v[i][j].fr==0 && v[i][j].sc==1)
				v1[i].pb("001");
			if(v[i][j].fr==0 && v[i][j].sc==2)
				v1[i].pb("011");
			if(v[i][j].fr==0 && v[i][j].sc==3)
				v1[i].pb("010");
			if(v[i][j].fr==1 && v[i][j].sc==0)
				v1[i].pb("100");
			if(v[i][j].fr==1 && v[i][j].sc==1)
				v1[i].pb("101");
			if(v[i][j].fr==1 && v[i][j].sc==2)
				v1[i].pb("111");
			if(v[i][j].fr==1 && v[i][j].sc==3)
				v1[i].pb("110");
		}
	}

	if(v[0].size()==8)
	{
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<idx;i++)
	{
		bool x =false;
		bool y =false;
		bool z =false;

		for(int j=1;j<v1[i].size();j++)
		{
			if(v1[i][0][0]!=v1[i][j][0])
			{
				x=true;
			}
		}
		for(int j=1;j<v1[i].size();j++)
		{
			if(v1[i][0][1]!=v1[i][j][1])
			{
				y=true;
			}
		}
		for(int j=1;j<v1[i].size();j++)
		{
			if(v1[i][0][2]!=v1[i][j][2])
			{
				z=true;
			}
		}

		if(x==false)
		{
			if(v1[i][0][0]=='0')
			{
				cout<<"X'";
			}
			else
			{
				cout<<"X";
			}
		}
		if(y==false)
		{
			if(v1[i][0][1]=='0')
			{
				cout<<"Y'";
			}
			else
			{
				cout<<"Y";
			}
		}
		if(z==false)
		{	
			if(v1[i][0][2]=='0')
			{
				cout<<"Z'";
			}
			else
			{
				cout<<"Z";
			}
		}
		if(i!=idx-1)
			cout<<"+";
	}
	return 0;
}

int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout<<"Enter 3 variable Kmap "<<endl;
	for(int i=0;i<2;i++)
		for(int j=0;j<4;j++)
		{
			cin>>a[i][j];
			g[i][j]=-1;
		}
	eight();
	four();
	two();
	one();
	cout<<"Equation is :"<<endl;
	print();

}


