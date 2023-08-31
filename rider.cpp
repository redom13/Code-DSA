#include<bits/stdc++.h>
using namespace std;
class point
{
    public:
    int x;int y;
    int dist;
    point(int x ,int y):x(x),y(y){}
    int getx(){return x;}
    int gety(){return y;}
};
class Rider
{public:
    int startx;
    int starty;
    int moves;
    Rider(int x,int y,int move){startx=x;starty=y;moves=move;}
    int getx(){return startx;}
    int gety(){return starty;}
    int getmoves(){return moves;}
};
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
}
void bfs(int num,int row,int col,vector<pair<int,Rider>>&rider,vector<vector<vector<int>>>&visit,vector<vector<int>>&visited)
{
    vector<int>dx={1,1,2,2,-1,-1,-2,-2};
    vector<int>dy={2,-2,1,-1,2,-2,1,-1};
    queue<pair<int,int>>q;

    q.push(make_pair(rider[num].second.getx(),rider[num].second.gety()));
    int x=rider[num].second.getx();
    int y=rider[num].second.gety();
    //cout<<"Pos: "<<x<<","<<y<<endl;
    visited[x][y]++;
    visit[num][x][y]=1;
    while(!q.empty())
    {    pair <int,int>cell=q.front();
        q.pop();

            for(int i=0;i<8;i++)
            {
                int newx=cell.first+dx[i];
                int newy=cell.second+dy[i];
                if(isvalid(newx,newy,row,col)&&visit[num][newx][newy]==0)
                {
                    visit[num][newx][newy]=visit[num][cell.first][cell.second]+1;
                    //cout<<"level for "<<num<<" of ("<<newx<<","<<newy<<") "<<visit[num][newx][newy]<<endl;
                    q.push(make_pair(newx,newy));
                    visited[newx][newy]++;
                }
            }
    }

}
int minimalcount(int no_of_riders,int no_of_rows,int col,vector<pair<int,Rider>>&rider,vector<vector<vector<int>>>&visit)
{
    int count=0;
    vector<vector<int>>visited(no_of_rows,vector<int>(col));
   for(int i=0;i<no_of_rows;i++)
   {
    for(int j=0;j<col;j++)
    {
        visited[i][j]=0;
    }
   }

    for(int i=0;i<no_of_riders;i++)
    {
        bfs(i,no_of_rows,col,rider,visit,visited);
    }
    vector<point>samepos;
    int k=0;
    for(int i=0;i<no_of_rows;i++)
    {
        for(int j=0;j<col;j++)
       {
        if(visited[i][j]==no_of_riders)
        {
            point p(i,j);
            samepos.push_back(p);
            //cout<<"("<<p.getx()<<","<<p.gety()<<")"<<endl;
        }
       }
    }
    //cout<<"Samepos size:"<<samepos.size()<<endl;
    vector<int>result;
    for(int i=0;i<samepos.size();i++)
    {
     int ans=0;
     int x=samepos[i].getx();
     int y=samepos[i].gety();
     for(int j=0;j<no_of_riders;j++)
     {
        //cout<<visit[j][x][y]<<endl;
        //if (visit[j][x][y]!=1)
        cout<<rider[j].second.getmoves()<<" ";
        ans+=ceil(visit[j][x][y]-1/(float)rider[j].second.getmoves());
     }
     cout<<endl;
     //cout<<ans<<" ";
     result.push_back(ans);
    }
    cout<<endl;
    if(result.size()==0)return -1;
    int minimal=result[0];
    for(int i=1;i<result.size();i++)
    {
        if(result[i]<minimal)minimal=result[i];
    }
    return minimal;

}

int main()
{
    int no_row,no_columns,no_of_riders;

   // ifstream chess("input4.txt");
    //ofstream output("output4.txt");

    vector<pair<int,Rider>>rider;
    string str;int startx,starty,moves;
    cin>>no_row>>no_columns>>no_of_riders;
    for(int i=0;i<no_of_riders;i++)
    {
        cin>>startx>>starty>>moves;
        Rider r(startx,starty,moves);
        pair<int,Rider>pq=make_pair(i,r);
        rider.push_back(pq);
    }
    // while(getline(chess, str)&&!str.empty())
    // {

    // }
    // for(int i=0;i<no_of_riders;i++)
    // {
    //     chess>>rider[i][0]>>rider[i][1]>>rider[i][2];
    // }
    vector<vector<vector<int>>>visit(no_of_riders,vector<vector<int>>(no_row,vector<int>(no_columns)));
    for(int i=0;i<no_of_riders;i++)
    {
        for(int j=0;j<no_row;j++)
        {
            for(int k=0;k<no_columns;k++)
            {
                visit[i][j][k]=0;
            }
        }
    }

cout<<minimalcount(no_of_riders,no_row,no_columns,rider,visit);
    return 0;
}
