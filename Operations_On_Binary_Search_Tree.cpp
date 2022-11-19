#include <iostream>

using namespace std;

class Tree
{
    public:
        int data;
        Tree *left;
        Tree *right;
};

void insertele(Tree **root, Tree *newnode)
{
    if(*root == NULL)
    {
        *root = newnode;
        cout << "ELEMENT INSERTED SUCCESSFULLY";
        return;
    }
    if(newnode->data == (*root)->data)
    {
        cout << "ELEMENT ALREADY EXIST";
        return;
    }
    else if(newnode->data < (*root)->data)
    {
        insertele(&(*root)->left,newnode);
    }
    else if(newnode->data > (*root)->data)
    {
        insertele(&(*root)->right,newnode);
    }
}

void inorder(Tree *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Tree *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Tree *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int highele(Tree *root)
{
    if(root->right == NULL)
        return (root->data);
    else
        highele(root->right);
}

int lowele(Tree *root)
{
    if(root->left == NULL)
        return (root->data);
    else
        lowele(root->left);
}

void div5(Tree *root)
{
    if(root != NULL)
    {
        if((root->data % 5) == 0)
            cout << root->data << " ";
        div5(root->left);
        div5(root->right);
    }
}

void odd(Tree *root)
{
    if(root != NULL)
    {
        if((root->data % 2) != 0)
            cout << root->data << " ";
        odd(root->left);
        odd(root->right);
    }
}

void decorder(Tree *root)
{
    if(root != NULL)
    {
        decorder(root->right);
        cout << root->data << " ";
        decorder(root->left);
    }
}

void incorder(Tree *root)
{
    if(root != NULL)
    {
        incorder(root->left);
        cout << root->data << " ";
        incorder(root->right);
    }
}

int check(int n)
{
    int c = 0;
    int i;

    for(i = 1; i <= n; i++)
        if((n % i) == 0)
            c++;

    if(c == 2)
        return 1;
    else
        return 0;
}

void prime(Tree *root)
{
    if(root !=NULL)
    {
        prime(root->left);
        if(check(root->data))
            cout << root->data << " ";
        prime(root->right);
    }
}

int searchele(Tree *root, int num)
{
    if((root->data) == num)
        return 1;
    else if((root->left == NULL) && (root->right == NULL))
        return 0;
    else if((root->data) > num)
        searchele(root->left,num);
    else if((root->data) < num)
        searchele(root->right,num);
}

int main()
{
    Tree *root = NULL;
    Tree *newnode;
    int num;
    int ch;

    cout << "BINARY SEARCH TREE" << endl << endl;

    while(1)
    {
        cout << "1.  INSERT AN ELEMENT" << endl;
        cout << "2.  INORDER" << endl;
        cout << "3.  PREORDER" << endl;
        cout << "4.  POSTORDER" << endl;
        cout << "5.  HIGHEST ELEMENT" << endl;
        cout << "6.  LOWEST ELEMENT" << endl;
        cout << "7.  ELEMENTS DIVISIBLE BY 5" << endl;
        cout << "8.  ODD ELEMENTS" << endl;
        cout << "9.  DECREASING ORDER" << endl;
        cout << "10. INCREASING ORDER" << endl;
        cout << "11. PRIME NUMBERS" << endl;
        cout << "12. SEARCH AN ELEMENT" << endl;
        cout << "0.  EXIT" << endl << endl;

        cout << "ENTER YOUR CHOICE : ";
        cin >> ch;

        cout << endl;

        switch(ch)
        {
        case 1:
            newnode = new Tree();
            cout << "ENTER AN ELEMENT TO INSERT : ";
            cin >> newnode->data;
            newnode->right = NULL;
            newnode->left = NULL;
            insertele(&root,newnode);
            break;
        case 2:
            cout << "INORDER : ";
            inorder(root);
            break;
        case 3:
            cout << "PREORDER : ";
            preorder(root);
            break;
        case 4:
            cout << "POSTORDER : ";
            postorder(root);
            break;
        case 5:
            num = highele(root);
            cout << "HIGHEST ELEMENT : " << num;
            break;
        case 6:
            num = lowele(root);
            cout << "LOWEST ELEMENT : " << num;
            break;
        case 7:
            cout << "ELEMENTS DIVISIBLE BY 5 : ";
            div5(root);
            break;
        case 8:
            cout << "ODD ELEMENTS : ";
            odd(root);
            break;
        case 9:
            cout << "DECREASING ORDER : ";
            decorder(root);
            break;
        case 10:
            cout << "INCREASING ORDER : ";
            incorder(root);
            break;
        case 11:
            cout << "PRIME NUMBERS : ";
            prime(root);
            break;
        case 12:
            cout << "ENTER AN ELEMENT TO SEARCH : ";
            cin >> num;
            if(root == NULL)
                cout << "TREE IS EMPTY";
            else
            {
                num = searchele(root,num);
                if(num == 1)
                {
                    cout << "ELEMENT FOUND";
                }
                else
                {
                    cout << "ELEMENT NOT FOUND";
                }
            }
            break;
        case 0:
            exit(0);
        default:
            cout << "INVALID CHOICE";
            break;
        }

        cout << endl << endl;
    }

    return 0;
}
