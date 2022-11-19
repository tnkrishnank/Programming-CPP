#include<iostream>
#include<stdlib.h>

using namespace std;

class Stack
{
    public:
        Stack();
        const static int n = 100;
        int top;
        int stk[n];
        void push(int);
        int pop();
        void display_from_bottom(Stack);
        void display_from_top(Stack);
        void countElements();
};

Stack::Stack()
{
    top = -1;
}

void Stack::push(int value)
{
    if(top == (n - 1))
    {
        cout<<"Stack Overflow";
    }
    else
    {
        top++;
        stk[top] = value;
    }
}

int Stack::pop()
{
    if(top == - 1)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        top--;
        return(stk[top+1]);
    }
    return 0;
}

void Stack::display_from_bottom(Stack st)
{
    Stack temp;
    int t=0;

    cout<<"\nStack Elements from Bottom : "<<endl;
    for(int i=st.top;i>=0;i--)
    {
        t = st.pop();
        temp.push(t);
    }

    for(int i=temp.top;i>=0;i--)
    {
        cout<<temp.stk[temp.top]<<" ";
        t = temp.pop();
        st.push(t);
    }
    cout<<endl;
}

void Stack::display_from_top(Stack st)
{
    Stack temp;
    int t=0;

    cout<<"\nStack Elements from Top : "<<endl;
    for(int i=st.top;i>=0;i--)
    {
        t = st.pop();
        cout<<t<<" ";
        temp.push(t);
    }

    for(int i=temp.top;i>=0;i--)
    {
        t = temp.pop();
        st.push(t);
    }
}

void Stack::countElements()
{
    Stack temp;
    int t=0,c=0;


    for(int i=top;i>=0;i--)
    {
        t = pop();
        c++;
        temp.push(t);
    }

    for(int i=temp.top;i>=0;i--)
    {
        t = temp.pop();
        push(t);
    }

    cout<<"Number of Elements in the Stack = "<<c<<endl;
}

int main()
{
    Stack ob;
    char c;
    int value,ch;

    do
    {
        cout<<"\t What do You Want to do?"<<endl;
        cout<<"1.Push an Element"<<endl;
        cout<<"2.Pop an Element"<<endl;
        cout<<"3.Display Stack From Bottom"<<endl;
        cout<<"4.Display Stack From Top"<<endl;
        cout<<"5.Count Number of Elements in the Stack"<<endl;

        cout<<"\nEnter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\nEnter the Element to be Pushed : ";
                cin>>value;
                ob.push(value);
                break;
            case 2:
                value = ob.pop();
                cout<<"Popped Element = "<<value<<endl;
                break;
            case 3:
                ob.display_from_bottom(ob);
                break;
            case 4:
                ob.display_from_top(ob);
                break;
            case 5:
                ob.countElements();
                break;
            default:
                cout<<"INVALID CHOICE"<<endl;
        }
        cout<<"\nDo You Want to Perform Any Other Operation?(Y/N) : ";
        cin>>c;
        cout<<endl;
    }while((c=='Y')||(c=='y'));

    return 0;
}
