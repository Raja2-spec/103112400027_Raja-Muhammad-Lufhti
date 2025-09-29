#include<iostream>
using namespace std;
int main(){
    int n; //3
    int x = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << "*" ;
        
        for (int k = 1; k <= i; k++)
        {
            cout << k;
        }
        cout << endl;
        
        for (int l = 1; l <= x; l++)
        {
            cout << " ";
        }
        x++;
    }
    cout << "*";
}



