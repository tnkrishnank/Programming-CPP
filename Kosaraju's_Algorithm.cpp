#include <iostream>
#include <vector>

using namespace std;

class node
{
    public:
        int data;
        node* next;
        int clr;
        int pi;
        int st;
        int et;

        node();
};

node::node()
{
    clr = 0;
    pi = -1;
}

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

void selection(int arr[], int n)
{
    int i;
    int j;
    int temp;
    int min_index;

    for(i = 0; i < n-1; i++)
    {
        min_index = i;

        for(j = i+1; j < n; j++)
        {
            if(arr[j] > arr[min_index])
            {
                min_index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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

static int t = 0;

int main()
{
    int n;
    int c;
    int i;
    int j;
    int k;
    int y;
    int adj;
    int data;

    cout << "ENTER NUMBER OF VERTICES : ";
    cin >> n;

    cout << endl << "ENTER THE VERTICES : ";

    node *vertex[n];
    node *vertex_t[n];

    int arr[n];

    int edge[n];

    for(i = 0; i < n; i++)
    {
        vertex[i] = NULL;
        vertex_t[i] = NULL;
    }

    for(i = 0; i < n; i++)
    {
        cin >> data;
        insertnode(&vertex[i],data);
        insertnode(&vertex_t[i],data);
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

    dfs_algo(vertex,n);

    for(i = 0; i < n; i++)
    {
        node *current = vertex[i];
        current = current->next;
        while(current != NULL)
        {
            for(j = 0; j < n; j++)
            {
                if(vertex_t[j]->data == current->data)
                {
                    insertnode(&vertex_t[j],vertex[i]->data);
                }
            }
            current = current->next;
        }
    }

    cout << endl << "TRANSPOSE : " << endl << endl;
    for(i = 0; i < n; i++)
    {
        display(&vertex_t[i]);
        cout << endl;
    }

    for(i = 0; i < n; i++)
    {
        arr[i] = vertex[i]->et;
    }

    selection(arr,n);

    time = 0;
    y = n;
    while(y != 0)
    {
        for(i = 0; i < n; i++)
        {
            if((vertex[i]->et == arr[0]) && (vertex_t[i]->clr == 0))
            {
                dfs_visit(vertex_t,n,vertex_t[i]->data,i);
                t++;
            }

            for(c = 0; c < n; c++)
            {
                if(vertex_t[c]->clr == 2)
                {
                    for(j = 0; j < y; j++)
                    {
                        if(arr[j] == vertex[c]->et)
                        {
                            for(k = j; k < y; k++)
                            {
                                arr[k] = arr[k+1];
                            }
                            y--;
                        }
                    }
                }
            }
        }
    }

    cout << endl << "NUMBER OF SCC : " << t << endl;

    return 0;
}
