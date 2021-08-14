#ifndef __CALCULATOR__TEMPALTE_H_
#define __CALCULATOR__TEMPALTE_H_

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename P, typename K>
class Calculator
{
private:
    T num1;
    P num2;
    char operation;
public:
    Calculator() { };
    Calculator(T x, P y, char oper): num1(x), num2(y), operation(oper) {};

    T GetNum1();
    void SetNum1(T num);
    P GetNum2();
    void SetNum2(P num);
    char GetOperVal();
    void SetOperVal(char oper);
    K Plus();
    K Minus();
    K Divide();
    K Multiply();
};


template<typename T, typename P, typename K>
K Calculator<T, P, K>::Plus() { return num1 + num2; }

template<typename T, typename P, typename K>
K Calculator<T, P, K>::Minus() { return num1 - num2; }

template<typename T, typename P, typename K>
K Calculator<T, P, K>::Multiply() { return num1 * num2; }

template<typename T, typename P, typename K>
K Calculator<T, P, K>::Divide() 
{  
    if (num2 == 0) 
    {
        throw runtime_error("Math error: Attempted to divide by zero\n");
    }
    return num1 / num2; 
}

template<typename T, typename P, typename K>
T Calculator<T, P, K>::GetNum1() { return num1; }

template<typename T, typename P, typename K>
void Calculator<T, P, K>::SetNum1(T num) { num1 = num; }

template<typename T, typename P, typename K>
P Calculator<T, P, K>::GetNum2() { return num2; }

template<typename T, typename P, typename K>
void Calculator<T, P, K>::SetNum2(P num) { num2 = num; }

template<typename T, typename P, typename K>
char Calculator<T, P, K>::GetOperVal() { return operation; }

template<typename T, typename P, typename K>
void Calculator<T, P, K>::SetOperVal(char oper) { operation = oper; }

#endif