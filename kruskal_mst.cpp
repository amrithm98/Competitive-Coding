#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct subset
{
    int parent,rank;
};

struct edge
{
    int src,dest,weight;
};

struct graph
{
    int V,E;
    struct edge *nextEdge;
};

struct graph* createGraph(int V,int E)
{
    struct graph* g=(struct graph *)malloc(sizeof(struct graph));
    g->V=V;
    g->E=E;
    g->nextEdge=(struct edge *)malloc(g->E*sizeof(struct edge));
    return g;
}

int find(struct subset subsets[],int i)
{
    if(subsets[i].parent!=i)
    {
        subsets[i].parent=find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}

void getUnion(struct subset subsets[],int x,int y)
{
    int xroot=find(subsets,x);
    int yroot=find(subsets,y);
    if(subsets[xroot].rank<subsets[yroot].rank)
    {
        subsets[xroot].parent=yroot;
    }
    else if(subsets[xroot].rank>subsets[yroot].rank)
    {
        subsets[yroot].parent=xroot;
    }
    else
    {
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a,const void* b)
{
    struct edge* a1=(struct edge *)a;
    struct edge* b1=(struct edge *)b;

    return (a1->weight)>(b1->weight);
    // if(((a1->weight)>(b1->weight)))
    //     return 1;
    // else if((a1->weight)==(b1->weight) && (a1->src+a1->dest+a1->weight)>(b1->src+b1->dest+b1->weight))
    // {
    //     return 1;
    // }
    // else
    //     return 0;

}

void Kruskal_mst(struct graph* g)
{
    int V=g->V;
    struct edge mst[V-1];
    int e=0,i=0;
    qsort(g->nextEdge,g->E,sizeof(g->nextEdge[0]),compare);
    struct subset* subsets=(struct subset *)malloc(V*sizeof(struct subset));
    int mstSize=0;
    for(int i=0;i<V;i++)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    for(int i=0;i<g->E;i++)
    {
        struct edge minEdge=g->nextEdge[i];
        int x=find(subsets,minEdge.src-1);
        int y=find(subsets,minEdge.dest-1);
        if(x!=y)
        {
            mst[mstSize++]=minEdge;
            getUnion(subsets,x,y);
        }
        if(mstSize==V-1)    
            break;
    }
    int totalWeight=0;
    for(int i=0;i<V-1;i++)
        totalWeight+=mst[i].weight;
    cout<<totalWeight<<"\n";
}

int main() 
{
    int V,E,i,j;
    cin>>V>>E;
    struct graph *g=createGraph(V,E);
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g->nextEdge[i].src=a;
        g->nextEdge[i].dest=b;
        g->nextEdge[i].weight=c;
    }
    // for(int i=0;i<E;i++)
    // {
    //     cout<<g->nextEdge[i].src<<"\t"<<g->nextEdge[i].dest<<"\t"<<g->nextEdge[i].weight<<"\n";
    // }
    Kruskal_mst(g);
    return 0;
}
