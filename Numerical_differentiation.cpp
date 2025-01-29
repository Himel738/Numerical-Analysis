#include<bits/stdc++.h>
using namespace std;

double numerical_differential_forward(vector<vector<double>> &a,int k,int n,double diff)
{
    double result = 0.00;
    int j  = 1;
    for(int i = 1; i <= n - k - 1; i++)
    {
        if((i % 2) != 0)
        {
            result += (1 /(double)i)*a[i][j];
        }
        else
        {
            result -= (1 /(double)i)*a[i][j];
        }
    }
    return (1.0 / diff) * result;
}

int main ()
{
    cout << "Enter The Number of Elemnts - ";
    int n;
    cin >> n;
    cout << endl;

    cout << "Enter The  Number of Y0 - ";
    double y0;
    cin >> y0;
    cout << endl;

    cout << "Enter The Difference - ";
    double diff;
    cin >> diff;
    cout << endl;

    vector<vector<double>> a(n,vector<double>(n));

    for(int i  = 0; i < 1; i++)
    {
        for(int j = 0; j <n; j++)
        {
            cin >> a[i][j];
        }
    }
    int k= n-1;


    for(int i = 1; i < n; i++)
    {
        cout << "Del " << i << " " << endl;
        for(int j = 0; j < k; j++)
        {
            a[i][j] = a[i-1][j+1] - a[i-1][j];
            cout<< fixed << setprecision(6) << a[i][j] << endl;
        }
        k = k - 1;
    }
    for(int i = 0; i < 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == y0)
            {
                int k = j;
                break;
            }
        }
    }

    cout << numerical_differential_forward(a,k,n,diff) << endl;

}

// 2.7183 3.3201 4.0552 4.9530 6.0496 7.3891 9.0250