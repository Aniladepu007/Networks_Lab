/*
CED16I002
Anil Kumar Adepu
Implementation of Dijkstra algo where each router is taken as a vertex and the least distance is calculated
using Dijkstra's shortest path algorithm

Input is given as adjacency matrix with zeroes indicating no path between the involved vertices(path of infinite distance)
*/

#include <iostream>
#include <climits>
using namespace std;

class Dijkstra {
private :
      int NOF_routers;
public :
      void algo();
      Dijkstra(int var) {
            NOF_routers=var; //total vertices
      }
};

void Dijkstra::algo() {
int i,j,s, adj[NOF_routers][NOF_routers];
int dist[NOF_routers], marked[NOF_routers], prev[NOF_routers];

cout<<"Enter the adjacency matrix!\n";
for(int i=1;i<=NOF_routers;i++)
      for(int j=1;j<=NOF_routers;j++)
            cin>>adj[i][j];

//assigning a larger value for paths of infinite distances
for(int i=1;i<=NOF_routers;i++)
      for(int j=1;j<=NOF_routers;j++)
            if(adj[i][j]==0)
                  adj[i][j]= INT_MAX/1000000;

cout<<"\n\nThe adjacency matrix for the graph is :\n";
for(i=1;i<=NOF_routers;i++) {
      for(j=1;j<=NOF_routers;j++)
            cout<<adj[i][j]<<"\t";
      cout<<endl<<endl;
}
cout<<"\nEnter the source!\n";
cin>>s;
cout<<"\n------------------------------------\n";
for(i=1;i<=NOF_routers;i++) {
      dist[i]=adj[s][i];
      marked[i]=0;
      if(adj[s][i]!= INT_MAX/1000000)
            prev[i]=s; //records the path everytime
}
dist[s]=0;
marked[s]=1;
prev[s]=s;
cout<<endl;
//printing distance array
for( i=1;i<=NOF_routers;i++)
	cout<<dist[i]<<"\t";
cout<<endl;
//printing marked array
for( i=1;i<=NOF_routers;i++)
	cout<<marked[i]<<"\t";

int u,min,w;
//iterating for (NOF_routers-2) times
for(int t=2;t<NOF_routers;t++) {
      min = INT_MAX;
      for(i=1;i<=NOF_routers;i++) {
            if(dist[i]<min && marked[i]!=1) {
                  min=dist[i];
                  u=i;
            }
      }
cout<<"\n\nu is :"<<u<<endl;
marked[u]=1;
w=1;

while(w<=NOF_routers) {
      if( marked[w]==0 && dist[w] > dist[u] + adj[u][w] ) {
            dist[w] = dist[u] + adj[u][w];
            prev[w] = u;
      }
w++;
}
//printing distance array after every iteration
for(i=1;i<=NOF_routers;i++)
      cout<<dist[i]<<"\t";
cout<<endl;
//printing distance array after every iteration
for(i=1;i<=NOF_routers;i++)
      cout<<marked[i]<<"\t";
}
for(i=1;i<=NOF_routers;i++)
	if(marked[i]==0) {
		marked[i]=1;
		break;
}
cout<<"\n\nFinal o/p : ---------------------------\n\n";
cout<<"Distance array!\n";
for(i=1;i<=NOF_routers;i++)
	cout<<dist[i]<<"\t";
	cout<<endl;
cout<<"\nMarked array!\n";
for(i=1;i<=NOF_routers;i++)
	cout<<marked[i]<<"\t";
cout<<endl;
cout<<"\nPath array!\n";
for(i=1;i<=NOF_routers;i++)
	cout<<prev[i]<<"\t";
cout<<endl;
}

int main() {
int nof_ver;
cout<<"Enter number of sub-routers!\n";
cin>>nof_ver;
//passing the no. of vertices thru' an implicit constructor
Dijkstra obj(nof_ver);
obj.algo();
      return 0;
}
