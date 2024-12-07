#include <iostream>
#include <climits>
using namespace std;


class Graph{
    int vertices; //It stores total number of vertices
    int** matrix; //Matrix representation of graph
    public:
    Graph(int v=5):vertices(v){
        matrix=new int*[v];
        for(int i=0;i<v;i++){
            matrix[i]=new int[v];
        }
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                matrix[i][j]=INT_MAX;
            }
        }
    }
    void add_edge(int source,int destination,int weight){
        matrix[source][destination]=weight;
        matrix[destination][source]=weight;
    }
    void remove_edge(int source,int destination){
        matrix[source][destination]=INT_MAX;
        matrix[source][destination]=INT_MAX;
    }
    bool has_edge(int source,int destination){
        return matrix[source][destination]!=INT_MAX;
    }
    int degree(int vertex){
        int count=0;
        for(int i=0;i<vertices;i++){
            if(matrix[vertex][i]!=INT_MAX){
                count++;
            }
        }
        return count;
    }
    void print_matrix(){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(matrix[i][j]==INT_MAX)
                cout<<"INF"<<" ";
                else cout<<matrix[i][j]<<" ";
            }
            cout<<endl;



            
        }
    }
    bool* get_neighbours(int vertex){
        bool* neighbours=new bool[vertices];
        for(int i=0;i<vertices;i++){
            neighbours[i]=has_edge(vertex,i);
        }
        return neighbours;
    }
    int get_vertices(){
        return vertices;
    }
};

//Use case
int main(){
    Graph G(5);
    G.add_edge(0,1,5);
    G.add_edge(1,2,7);
    G.add_edge(1,3,10);
    G.add_edge(2,3,3);
    G.add_edge(3,4,6);
    G.print_matrix();
    bool* neighbours_0=G.get_neighbours(2);
    for(int i=0;i<G.get_vertices();i++){
        if(neighbours_0[i]==true){
            cout<<i<<" is a neighbour of 2"<<endl;
        }
        else{
            cout<<i<<" is not a neighbour of 2"<<endl;
        }
    }
}