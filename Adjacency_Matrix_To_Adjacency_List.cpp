#include <iostream>

using namespace std;

class node
{
    public:
        int data;
        node *next;
};

void display(node **head)
{
    node *current;
    current = new node();

    cout << "HEAD --> ";
    current = *head;
    while(current != NULL)
    {
        cout << current->data << " --> ";
        current = current->next;
    }
    cout << "NULL";
}

void append(node **head, int d)
{
    node *current, *newnode;

    newnode = new node;

    newnode->data = d;
    if(*head == NULL)
    {
        *head = newnode;
        newnode->next = NULL;
    }
    else
    {
        current = *head;
        while((current->next) != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = NULL;
    }
}

int main()
{
    int n;
    int i;
    int j;

    cout << "ENTER NUMBER OF NODES : ";
    cin >> n;

    int m[n][n];
    node *head[n];

    for(i = 0; i < n; i++)
        head[i] = NULL;

    cout << endl << "ENTER ADJACENCY MATRIX : " << endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(m[i][j] != 0)
                append(&head[i], j);
        }
    }
    for(i = 0; i < n; i++)
    {
        cout << endl << i << " : ";
        display(&head[i]);
    }

    cout << endl;

    return 0;
}
