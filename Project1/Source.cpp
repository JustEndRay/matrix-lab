#include <iostream>
#include <iomanip>
using namespace std;
void create(int** a, const int n, const int m);
void print(int** a, const int n, const int m);
int symmetric(int** a, int n, int in, int j, int count);
int main()
{
    int n, m;
    cout << "n = ";cin >> n;
    cout << "m = ";cin >> m;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    create(a, n, m);
    print(a, n, m);
    if (n != m)
    {
        cout << "not simetric" << endl;
        return 0;
    }

    int f = symmetric(a, n, n-1, 0, 0);
    if (f == (n * n - n)) { cout << "simetric " << endl; }
    else { cout << "not simetric " << endl; }
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void create(int** a, const int n, const int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j<<"] = "; cin >> a[i][j];
        }
}
void print(int** a, const int n, const int m)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
int symmetric(int** a, int n,int in, int j, int count)
{
    if (in>-1)
    {
        if (j <n)
        {
            if (a[in][j]==a[j][in]) { symmetric(a, n, in, j + 1, count + 1); }
            else { symmetric(a, n, in, j + 1, count); }
        }
        symmetric(a, n, in-1, j, count);
    }
    return count;
}
