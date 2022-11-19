#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertion(vector<int> &arr, int n)
{
    int i;
    int j;
    int key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void selection(vector<int> &arr, int n)
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
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

bool isMinHeap(vector<int> &arr, int n)
{
    int i;
    for(i = n-1; i > 0; i--)
    {
        if(arr[(i-1)/2] > arr[i])
        {
            return false;
        }
    }

    return true;
}

void heapify(vector<int> &arr, int n)
{
    int i;
    int temp;

    while(!isMinHeap(arr,n))
    {
        for(i = n-1; i > 0; i--)
        {
            if(arr[(i-1)/2] > arr[i])
            {
                temp = arr[(i-1)/2];
                arr[(i-1)/2] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void heap(vector<int> &arr, int n)
{
    vector<int> a;
    int temp;
    int c = 0;

    while(n > 0)
    {
        heapify(arr,n);

        temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp;

        a.push_back(arr[n-1]);
        n--;
        c++;
    }

    arr.clear();
    arr = a;
}

bool hasMoreDigits(vector<int> &arr, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            return true;
        }
    }

    return false;
}

void radix(vector<int> &arr, int n)
{
    int i;
    int a[n];
    int d[10];
    int t = 10;

    vector<int> temp;

    for(i = 0; i < n; i++)
    {
        temp.push_back(arr[i]);
    }

    while(hasMoreDigits(temp,n))
    {
        for(i = 0; i < 10; i++)
        {
            d[i] = 0;
        }

        for(i = 0; i < n; i++)
        {
            d[temp[i] % 10]++;
        }

        for(i = 1; i < 10; i++)
        {
            d[i] = d[i] + d[i-1];
        }

        for(i = n-1; i >= 0; i--)
        {
            a[d[temp[i] % 10]-1] = arr[i];
            d[temp[i] % 10]--;
        }

        for(i = 0; i < n; i++)
        {
            arr[i] = a[i];
            temp[i] = a[i];
        }

        for(i = 0; i < n; i++)
        {
            temp[i] = temp[i] / t;
        }

        t = t * 10;
    }
}

void display(vector<int> &arr, int n)
{
    int i;

    cout << "SORTED ARRAY : " << endl;

    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    int i;
    int ch;
    float t = 0.0;
    string line;

    auto start = 0;
    auto stop = 0;

    vector<int> arr;

    srand(time(0));

    fstream file;
    file.open("data.txt",ios::out);

    for(i = 0; i < 500; i++)
    {
        file << (rand() % 50000) << endl;
    }

    file.close();

    while(1)
    {
        arr.clear();

        file.open("data.txt",ios::in);

        n = 0;
        while(getline(file,line))
        {
            arr.push_back(stoi(line));
            n++;
        }

        file.close();

        cout << "1. INSERTION SORT" << endl;
        cout << "2. SELECTION SORT" << endl;
        cout << "3. HEAP SORT" << endl;
        cout << "4. RADIX SORT" << endl;
        cout << "0. EXIT" << endl;

        cout << endl << "ENTER YOUR CHOICE : ";
        cin >> ch;

        cout << endl;

        switch(ch)
        {
        case 1:
        {
            cout << "INSERTION SORT" << endl;
            auto start = high_resolution_clock::now();
            insertion(arr,n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            t = duration.count();
            break;
        }
        case 2:
        {
            cout << "SELECTION SORT" << endl;
            auto start = high_resolution_clock::now();
            selection(arr,n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            t = duration.count();
            break;
        }
        case 3:
        {
            cout << "HEAP SORT" << endl;
            auto start = high_resolution_clock::now();
            heap(arr,n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            t = duration.count();
            break;
        }
        case 4:
        {
            cout << "RADIX SORT" << endl;
            auto start = high_resolution_clock::now();
            radix(arr,n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            t = duration.count();
            break;
        }
        case 0:
            exit(0);
        default:
            cout << "INVALID CHOICE !!!" << endl;
        }

        cout << endl << "TIME TAKEN : " << t << " ms OR " << (t / 1000) << " s" << endl << endl;

        if(ch >= 1 && ch <= 4)
        {
            //display(arr,n);
        }

        cout << endl;
    }

    return 0;
}
