#include <iostream>
#include <iomanip>
using namespace std;
void Create(int** a, const int n, const int m);
void Print(int** a, const int n, const int m);
int is_symmetric(int** a, int n, int in, int j, int count);
int main()
{
    int n;
    int m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    if (n != m)
    {
        cout << "not simetric" << endl;
        return 0;
    }

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    Create(a, n, m);
    Print(a, n, m);
    int f = is_symmetric(a, n, n-1, 0, 0);
    if (f == (n * n - n)) { cout << "simetric " <<f<< endl; }
    else { cout << "not simetric " <<f<< endl; }
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a, const int n, const int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j<<"] = "; cin >> a[i][j];
        }
}
void Print(int** a, const int n, const int m)
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
int is_symmetric(int** a, int n,int in, int j, int count)
{
    if (in>-1)
    {
        if (j <n)
        {
            if (a[in][j]==a[j][in]) { is_symmetric(a, n, in, j + 1, count + 1); }
            else { is_symmetric(a, n, in, j + 1, count); }
        }
        is_symmetric(a, n, in-1, j, count);
    }
    return count;
}