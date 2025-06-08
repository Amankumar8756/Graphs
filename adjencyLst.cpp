#include<bits/stdc++.h>

using namespace std;

// adjency matrix 
// undirected unweighted graph

int main(){

    int node, edges;

    cin>>node>>edges;

    vector<vector<bool> >Adjmatrix(node, vector<bool>(node,0));

    int u,v;
    
    for(int i =0; i<edges; i++){
        cin>>u>>v;
        Adjmatrix[u][v] =1;
        Adjmatrix[v][u] =1;

    }

    for(int i =0; i<node; i++){
        for(int j=0; j<node; j++){
            cout<<Adjmatrix[i][j]<<" ";
        }
       cout<<endl; 
    }

    
}

