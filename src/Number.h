//
// Created by Дмитрий Соколов on 26.04.2020.
//

#ifndef UNTITLED2_NUMBER_H
#define UNTITLED2_NUMBER_H

#endif //UNTITLED2_NUMBER_H
#include <iostream>

class Number
{
private:
    std::string number;

public:

    Number()
    {
        number = "0";
    }

    Number(std::string& a)
    {
        number = a;
    }

    int operator[](size_t i)
    {
        return number[i] - '0';
    }

    const int operator[] (size_t i) const
    {
        return number[i] - '0';
    }

    Number addZeros(int pos,int n)
    {
        int len = n - number.length();
        std::string zeros(len,'0');
        number.insert(pos, zeros);
        return *this;
    }

    std::pair<Number, Number> split(int n) const
    {
        int len = number.length();
        int m = len - (n/2);
        std::string left,right;
        left = number.substr(0,m);
        right = number.substr(m,len-m);
        Number a(left);
        Number b(right);
        std::pair<Number, Number> res;
        res.first = a;
        res.second = b;
        return res;
    }

    int size() const
    {
        return number.size();
    }

    std::string& get_str()
    {
        return number;
    }

    Number operator +(const Number& numb2) const
    {
        std::string num1 = number, num2 = numb2.number;
        if (num1.length() > num2.length())
            swap(num1, num2);
        std::string r_num = "";
        int n1 = num1.length(), n2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int rem = 0;
        for (size_t i = 0; i < n1; i++)
        {
            int sum = ((num1[i] - 48) + (num2[i] - 48) + rem);
            r_num.push_back(sum % 10 + 48);
            rem = sum / 10;
        }
        for (size_t i = n1; i < n2; i++)
        {
            int sum = ((num2[i] - 48) + rem);
            r_num.push_back(sum % 10 + 48);
            rem = sum / 10;
        }
        if (rem)
            r_num.push_back(rem + 48);
        for(int i = r_num.size()-1; i > 0 ; i--)
        {
            if(r_num[i] == '0')
                r_num.pop_back();
            else
                break;
        }
        std::reverse(r_num.begin(), r_num.end());
        Number result = r_num;
        return result;
    }

    Number operator - (const Number& numb2) const
    {
        std::string num1 = number;
        std::string num2 = numb2.number;
        std::string rslt = "";
        int n1 = num1.length(), n2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int rem = 0;
        for (int i = 0; i < n2; i++)
        {
            int sub = ((num1[i] - '0') - (num2[i] - '0') - rem);
            if (sub < 0)
            {
                sub = sub + 10;
                rem = 1;
            }
            else
                rem = 0;

            rslt.push_back(sub + '0');
        }
        for (int i = n2; i < n1; i++)
        {
            int sub = ((num1[i] - '0') - rem);
            if (sub < 0)
            {
                sub = sub + 10;
                rem = 1;
            }
            else
                rem = 0;
            rslt.push_back(sub + '0');
        }
        for(int i = rslt.size() - 1; i > 0 ; i--)
        {
            if(rslt[i] == '0')
                rslt.pop_back();
            else
                break;
        }
        reverse(rslt.begin(), rslt.end());
        return rslt;
    }

    Number operator * (const Number& numb2) const  // that miltiplication is called only for numbers less then 10
    {
        int a = atoi(number.c_str());
        int b = atoi(numb2.number.c_str());
        int c = a * b;
        std::string numb_r = std::to_string(c);
        Number numb_return(numb_r);
        return numb_return;
    }

    ~Number() {}
};
