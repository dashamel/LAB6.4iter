#include <iostream>
#include <cmath>  
using namespace std;

int MinMod(int mas[], int n)  
{
    int minMod = abs(mas[0]);  
    for (int i = 1; i < n; ++i)    
    { 
        if (abs(mas[i]) < minMod)  
        {
            minMod = abs(mas[i]);   
        }
    }
    return minMod;
}

int Sumzero(int mas[], int n)
{ 
    bool foundZero = true;  
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (foundZero) 
        {
            sum += abs(mas[i]); 
        }
        if (mas[i] == 0) 
        {
            foundZero = false;
        } 
    }
    return sum;
}

void Modifmas(int* mas, const int n)  
{
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < n - i; j++) 
            if (mas[j] % 2 != 0) 
            {
                int tmp = mas[j]; 
                mas[j] = mas[j + 1];
                mas[j + 1] = tmp; 
            }
           

}

int main()
{
    int n;
    cout << "Count elements n: ";          
    cin >> n;

    int* mas = new int[n];

    cout << "Elements of mas: " ;
    for (int i = 0; i < n; ++i)
    {
        cin >> mas[i]; 
    }

    int minMod = MinMod(mas, n);  
    cout << "Min element in abs: " << minMod << endl;

    int sumMod = Sumzero(mas, n); 
    cout << "Summ: " << sumMod << endl;

    Modifmas(mas, n);  
    cout << "Modifmas: ";
    for (int i = 0; i < n; ++i)
    {
        cout << mas[i] << " "; 
    }
    cout << endl;

    delete[] mas; 

    return 0;
}
