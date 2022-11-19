#include <iostream>

using namespace std

void merge_sort(vector<int> arr)
{
    int i;

    vector<int> a;
    vector<int> b;

    int n = arr.size();

    for(i = 0; i < (n/2); i++)
    {
        a.append(arr[i]);
    }

    for(i = (n/2); i < n; i++)
    {
        b.append(arr[i]);
    }

    if(n == 1)
    {
        if(a)
    }

    if(n > 1)
    {
        merge_sort(a);
        merge_sort(b);
        merging(b,c,a);
    }
}

int main()
{
    int i;
    int n;
    vector<int> arr;

    cout << "ENTER NUMBER OF ELEMENTS : ";
    cin >> n;

    cout << "ENTER THE NUMBERS : ";

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr);
}
