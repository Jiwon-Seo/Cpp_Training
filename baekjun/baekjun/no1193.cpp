#include<iostream>
using namespace std;

void Fraction(int);

int main()
{
    int num;
#if 1
    try
    {
        cin >> num;
        if ((num < 1) || (num > 10000000))
        {
            throw 0;
        }
    }
    catch (int ext)
    {
        cout << "Err: invalid number" << endl;
        return -1;
    }
    Fraction(num);
#endif
#if 0
    while (1)
    {
        cin >> num;
        Fraction(num);
    }
#endif
    return 0;
}

void Fraction(int num)
{
    int layer = 1;
    while (1)
    {
        if ((layer * (layer + 1) / 2) >= num)
            break;
        layer++;
    }
#if 1
    if (layer % 2 == 0)
    {
        int numerator = 0, denominator = layer + 1;
        for (int comp = (layer - 1) * layer / 2; comp < num; comp++)
        {
            numerator++;    denominator--;
        }
        cout << numerator << '/' << denominator << endl;
    }
    else
    {
        int numerator = layer + 1, denominator = 0;
        for (int comp = (layer - 1) * layer / 2; comp < num; comp++)
        {
            numerator--;    denominator++;
        }
        cout << numerator << '/' << denominator << endl;
    }
#endif
}