#include <iostream>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        int clr;
        int d;
        int pi;
        int st;
        int et;
};

void insertnode(node **vertex, int element)
{
    node *newnode, *current;

    newnode = new node;

    newnode->data = element;

    if(*vertex == NULL)
    {
        *vertex = newnode;
        newnode->next = NULL;
    }
    else
    {
        current = *vertex;
        while((current->next) != NULL)
        {
            current = current->next;
        }

        current->next = newnode;
        newnode->next = NULL;
    }
}

void display(node **vertex)
{
    node *current;
    current = new node;

    cout << "HEAD --> ";
    current = *vertex;
    while(current != NULL)
    {
        cout << current->data << " --> ";
        current = current->next;
    }
    cout << "NULL";
}

int dequeue(node **q)
{
    int element;
    node *current;

    current = *q;
    *q = current->next;
    element = current->data;
    delete current;

    return element;
}

void enqueue(node **q, int element)
{
    insertnode(q,element);
}

void bfs_algo(node **vertex, int n)
{
    int i;
    int j;
    int u;

    for(i = 0; i < n; i++)
    {
        vertex[i]->clr = 0;
        vertex[i]->d = 0;
        vertex[i]->pi = -1;
    }

    vertex[0]->clr = 1;
    vertex[0]->d = 0;
    vertex[0]->pi = -1;

    node *q;
    q = NULL;
    enqueue(&q,vertex[0]->data);
    display(&q);
    cout << endl;

    node *current;
    while(q != NULL)
    {
        u = dequeue(&q);

        for(i = 0; i < n; i++)
        {
            if(vertex[i]->data == u)
            {
                current = vertex[i]->next;
                break;
            }
        }

        while(current != NULL)
        {
            for(j = 0; j < n; j++)
            {
                if(current->data == vertex[j]->data)
                {
                    break;
                }
            }
            if(vertex[j]->clr == 0)
            {
                vertex[j]->clr = 1;
                vertex[j]->d = vertex[i]->d + 1;
                vertex[j]->pi = u;
                enqueue(&q,current->data);
                display(&q);
                cout << endl;
            }
            current = current->next;
        }
        vertex[i]->clr = 2;
    }
}

static int time;

void dfs_visit(node **vertex, int n, int data, int pos)
{
    int i;

    time = time + 1;

    vertex[pos]->st = time;
    vertex[pos]->clr = 1;

    node *current;

    current = vertex[pos];
    current = current->next;

    while(current != NULL)
    {
        for(i = 0; i < n; i++)
        {
            if(current->data == vertex[i]->data)
            {
                break;
            }
        }
        if(vertex[i]->clr == 0)
        {
            vertex[i]->pi = data;
            dfs_visit(vertex,n,vertex[i]->data,i);
        }
        current = current->next;
    }

    vertex[pos]->clr = 2;
    time = time + 1;
    vertex[pos]->et = time;
}

void dfs_algo(node **vertex, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        vertex[i]->clr = 0;
        vertex[i]->pi = -1;
    }

    time = 0;

    for(i = 0; i < n; i++)
    {
        if(vertex[i]->clr == 0)
        {
            dfs_visit(vertex,n,vertex[i]->data,i);
        }
    }
}

int main()
{
    int n;
    int i;
    int j;
    int adj;
    int data;

    cout << "ENTER NUMBER OF VERTICES : ";
    cin >> n;

    cout << endl << "ENTER THE VERTICES : ";

    node *vertex[n];
    int edge[n];

    for(i = 0; i < n; i++)
    {
        vertex[i] = NULL;
    }

    for(i = 0; i < n; i++)
    {
        cin >> data;
        insertnode(&vertex[i],data);
    }

    cout << endl << "ENTER NUMBER OF EDGES FOR EACH VERTEX : " << endl << endl;

    for(i = 0; i < n; i++)
    {
        cout << "NUMBER OF EDGES FOR VERTEX " << i+1 << " : ";
        cin >> edge[i];
    }

    cout << endl << "ENTER THE EDGE DATA : " << endl << endl;

    for(i = 0; i < n; i++)
    {
        j = edge[i];
        if(j > 0)
        {
            cout << "ENTER THE VERTICES CONNECTING VERTEX " << i+1 << " : ";
        }
        else
        {
            cout << "NO EDGES FOR VERTEX " << i+1 << endl;
        }
        while(j > 0)
        {
            cin >> adj;
            insertnode(&vertex[i],adj);
            j--;
        }
    }

    cout << endl << "ADJACENT LIST : " << endl << endl;
    for(i = 0; i < n; i++)
    {
        display(&vertex[i]);
        cout << endl;
    }

    cout << endl << "BFS ALGORITHM" << endl << endl;
    bfs_algo(vertex,n);

    cout << endl << "DFS ALGORITHM" << endl << endl;
    dfs_algo(vertex,n);

    cout << "CHECK USING TIME :" << endl << endl;
    for(i = 0; i < n; i++)
    {
        cout << vertex[i]->data << " -> " << vertex[i]->st << " " << vertex[i]->et;
        cout << endl;
    }

    return 0;
}
