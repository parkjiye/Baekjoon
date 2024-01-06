#include <iostream>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    int biggest, smallest = 0;

    string big_A = A;
    string sml_A = A;
    string big_B = B;
    string sml_B = B;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '5')
        {
            big_A[i] = '6';
        }

        if (A[i] == '6')
        {
            sml_A[i] = '5';
        }
    }

    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] == '5')
        {
            big_B[i] = '6';
        }

        if (B[i] == '6')
        {
            sml_B[i] = '5';
        }
    }

    biggest = stoi(big_A) + stoi(big_B);
    smallest = stoi(sml_A) + stoi(sml_B);

    cout << smallest << " " << biggest << "\n";
}