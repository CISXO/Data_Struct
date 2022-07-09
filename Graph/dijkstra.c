//
//  main.c
//  Graph1.c
//
//  Created by 조정현 on 2022/06/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define Max_vetex 12

typedef struct nodestruc *nodePointer ;
typedef struct nodestruc
{
    int no;
    float cost;
    nodePointer link ;
}ty_node;
   
nodePointer vertex[Max_vetex];

short int min[Max_vetex];
short int visited[Max_vetex];
short int visited_1[Max_vetex];

int AdjacentMatrix[][Max_vetex]= {    {0,0,1,1,0,0,0,0,1,0,0,0},
                                    {0,0,1,0,1,0,0,1,0,0,0,0},
                                    {0,0,0,1,0,1,0,1,0,0,0,1},
                                    {0,1,0,0,0,1,1,0,0,0,0,0},
                                    {0,0,1,0,0,0,0,0,0,0,1,1},
                                    {1,1,0,0,0,0,1,0,1,0,0,0},
                                    {0,1,0,0,1,0,0,0,0,0,0,0},
                                    {0,0,0,0,1,0,0,0,0,1,0,0},
                                    {0,0,1,0,0,0,0,0,0,1,0,0},
                                    {0,0,1,0,0,0,0,0,0,0,0,1},
                                    {0,0,0,0,0,0,0,1,0,1,0,0},
                                    {0,0,0,0,0,0,0,1,0,0,1,0}};

void Read_and_make_graph() {
    nodePointer np = NULL, np2, curr = NULL;
    
    FILE *fp;
                
    int all_node;
    int _node;
    float _cost = 0.0;
    char com[2];
    int u,v,v2=0;
    int first_node = 0;

    _node = -1;

    fp = fopen("graph.txt","r");    // ∆ƒ¿œ ¿‘∑¬
    if(fp == NULL)
    {
        printf("graphdata.txt 파일을 읽어들일수 없습니다..\n");
        exit(1);
    }

    fscanf(fp, "%d", &all_node);
    printf("%d\n", all_node);

    while(1)
    {
        if(feof(fp))
            break;

        for(v=0; v<12; v++)
        {
            np2 = vertex[v];

            for(u=0; u<12; u++)
            {
                if(AdjacentMatrix[v][u] != 0)
                {
                    if(_node == -1)
                    {
                        if(v2 == v)
                        {
                            fscanf(fp, "%d %d %f %s", &first_node, &_node, &_cost, com);
                            printf("%d\t", first_node);
                        }
                    }

                    else if(v2 != v)
                    {
                        fscanf(fp,"%d %d %f %s", &first_node, &_node, &_cost, com);
                        printf("\n%d\t", first_node);
                    }
                    

                    else if(v2 == v)
                        fscanf(fp,"%d %f %s ",&_node, &_cost, com);
                    

                    np =(nodePointer)malloc(sizeof(struct nodestruc));
                    
                    np->no = _node;
                    np->cost = _cost;
                    np->link = NULL;

                    if(vertex[v] != np2)
                    {
                        v2 = v;
                        curr->link = np;
                        curr = np;
                        
                        printf("%d\t%.1f%s\t", np->no, np->cost, com);
                    }

                    else if (vertex[v] == np2)
                    {
                        v2 = v;
                        curr = np;
                        vertex[v] = np;
                        
                        printf("%d\t%.1f%s\t", np->no, np->cost, com);
                    }
                }
            }
            v2 = v;
            np->link = NULL;
        }
        printf("\n\n");
    }
}


void DFS_path(int s, int t)
{
    static float totalcost = 0;
    nodePointer w;

    w = vertex[s];
    visited[s] = 1;

    printf("%3d,",s);
   
    for( ; w!=NULL; w=w->link)
    {
        if (w->no == t)
        {
            printf("%3d\n", w->no);
            totalcost = totalcost + w->cost;
            printf("총비용: %.1f\n", totalcost);
            break;
        }

        else if ( visited[w->no] == NULL)
        {
            totalcost += w->cost;
            DFS_path(w->no,t);
            break;
        }
    }
    totalcost = 0;
    visited[s] = 0;
}


void Shortest_path_Dij(int s, int t)
{
    static float totalcost3 = 0;
    static float totalcost4 = 0;
    float mincost = -1;
    nodePointer a, b;

    a = vertex[s];
    b = a;
    visited_1[s] = 1;
    min[s] = 1;
    printf("%3d,",s);
   
   
    for( ; a!=NULL ; a = a->link)
    {
        mincost = a->cost;
        for(a=a->link; a!=NULL ;a=a->link)
        {
            if(mincost > a->cost)
            {
                if(a->no == t && min[a->no] != 1)
                    goto loop;

                mincost = a->cost;
                b = a;
                min[s] = 1;
            }
        }
    
        if (b->no == t)
        {
            printf("%3d\n", b->no);
            totalcost4 = totalcost3 + b->cost;
            printf("총비용: %.1f\n", totalcost4);
            break;
loop:
            printf("%3d\n", a->no);
            totalcost4 = totalcost3 + a->cost;
            printf("총비용: %.1f\n", totalcost4);
            break;
        }

        else if ( visited_1[b->no] == NULL)
        {
            totalcost3 += mincost;
            Shortest_path_Dij(b->no,t);
            break;
        }

        else if(b->no != t &&  visited_1[b->no] != NULL)
        {
            totalcost4 = -1;
            printf("...\n");
            printf("총비용: %.1f\n", totalcost4);
            break;
        }
    }
    totalcost4 = 0;
    totalcost3 = 0;
    visited_1[s] = 0;
}

float get_cost(int s, int t)
{
    static float totalcost3 = 0;
    static float totalcost4 = 0;
    float mincost=-1;
    nodePointer w, z;

    w = vertex[s];
    z = w;
    visited[s] = 1;

   
    for( ; w != NULL; w=w->link)
    {
        mincost = w->cost;
        for(w=w->link; w != NULL; w=w->link)
        {
            if(mincost > w->cost)
            {
                mincost = w->cost;
                z = w;
                min[s] = 1;
            }
        }
    
        if (z->no == t){
            totalcost4 = totalcost3 + z->cost;
            break;
        }

        else if ( visited[z->no] == NULL)
        {
            totalcost3 += mincost;
            get_cost(z->no,t);
            break;
        }

        else if(z->no != t && visited[z->no] != NULL)
        {
            totalcost4 = -1;
            return totalcost4;
        }
    }

    if(totalcost4 != 0)
        return totalcost4;

    totalcost4 = 0;
    totalcost3 = 0;
    visited[s] = 0;
    return 0;
}




int main()
{
    int a, b;
    char c;
    int i = 0;

    Read_and_make_graph();
    
    printf("\n");

    do{
        fflush(stdin);

        printf("\n선택(f/j),시작정점, 목적지정점번호)? ");
        scanf("%c %d %d", &c,&a,&b);
        
        
        if( c == 'f')
        {
            printf("\nDFS로 찾은 경로:");
            DFS_path(a,b);
        }

        if (c == 'e')
            exit(1);
        
        else if(c == 'j')
        {
            
            printf("\nDijkstra로 찾은 경로:");
            Shortest_path_Dij(a,b);
                
            for(i=0; i<Max_vetex; i++)
            {
                visited[i] = 0;
                visited_1[i] = 0;
                min[i] = 0;
            }
        }
    }
    while(c != 'e');
    return 0;
}



