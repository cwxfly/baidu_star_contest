#include <iostream>
#include <vector>

using namespace std;

const int MAX_LEN = 42;
struct bigInt
{
    int digital[MAX_LEN];
    bigInt()
    {
        for (int i=0;i<MAX_LEN;++i)
            digital[i] = 0;
    }
    bigInt(int value)
    {
        int index = 0;
        for (int i=0;i<MAX_LEN;++i)
            digital[i] = 0;
        while(value > 0){
            digital[index] = value%10;
            value /= 10;
            ++ index;
        }
    }
    bigInt(const bigInt&);
    void assign(int value)
    {
        int index = 0;
        while(value > 0){
            digital[index] = value%10;
            value /= 10;
            ++ index;
        }
    }
    void printbig()
    {
        int i=MAX_LEN-1;
        for (;i>=0;--i)
            if (digital[i] != 0)
                break;
        for (int j=i;j>=0;--j)
            cout << digital[j];
        cout << endl;
    }
    //注意每个重载操作符的形参及返回类型
    bigInt& operator += (const bigInt &b); //复制操作符，复合复制操作符一般定义为成员函数
    // bigInt& operator [] (int n);
    bigInt& operator = (const bigInt &b);
    friend istream& operator >> (istream&,bigInt&); // 输入输出操作符定义友元函数
    friend ostream& operator << (ostream&,const bigInt&);
};

bigInt operator + (const bigInt &a,const bigInt &b){ //算术运算符及关系操作符定义非成员函数
    //operator + 一般利用 operator += 实现
    bigInt tmp = 0; 
    tmp += a;
    tmp += b;
    return tmp;
}

istream& operator >> (istream &in,bigInt &a){
    for (int i=0;i<MAX_LEN;++i)
        in >> a.digital[i];
    return in;
}

ostream& operator << (ostream &out,const bigInt &a){
    int i=MAX_LEN-1;
    for (;i>=0;--i)
        if (a.digital[i] != 0)
            break;
    for (int j=i;j>=0;--j)
        out << a.digital[j];
    return out;
}

bigInt::bigInt(const bigInt &a)
{
    for (int i=0;i<MAX_LEN;++i)
        digital[i] = a.digital[i];
}

bigInt& bigInt::operator = (const bigInt &b)
{
    for (int i=0;i<MAX_LEN;++i)
        digital[i] = b.digital[i];
    return *this;
}

// bigInt& bigInt::operator [](int n){
//     return *(this + (n*sizeof(bigInt)));
// }

bigInt& bigInt::operator += (const bigInt &b) {
    int carry = 0;
    int tmp = 0;
    for (int i = 0; i < MAX_LEN; ++i)
    {
        tmp = this->digital[i] + b.digital[i] + carry;
        carry = tmp/10;
        this->digital[i] = tmp%10;
    }
    // (*this) = (*this) + b;
    return (*this);
}

// bigInt bigInt::operator + (bigInt b){
//     bigInt addition;
//     int carry = 0;
//     int tmp = 0;

//     for (int i=0;i<MAX_LEN;++i){
//         tmp = digital[i] + b.digital[i] + carry;
//         carry = tmp/10;
//         addition.digital[i] = tmp%10;
//     }
//     return addition;
// }

bigInt solution(const int &number,const vector< vector<bigInt> > &C)
{
    int num_of_two = 0;
    int num_of_one = 0;
    bigInt total;

    num_of_two = number / 2;
    for (int i=0;i<=num_of_two;++i){
        num_of_one = number - i*2; // 1的个数，i是二的个数
        if (num_of_one < i)
            total += C[num_of_one+i][num_of_one];
        else
            total += C[num_of_one+i][i];
    }
    return total;
}

void cal(const int &n,const int &r,vector< vector<bigInt> > &C)
{
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k]);
    }
}

int main() {
    int n=200,r=100;

    int tmp = 0,num = 0;
    vector<int> in;

    vector< vector<bigInt> > array(n+1,vector<bigInt> (r+1,0));
    cal(n,r,array);
    while(cin >> tmp)
    {
        in.push_back(tmp);
        ++num;
    }
    for (int i=0;i<num;++i)
       // solution(in[i],array).printbig();
        cout << solution(in[i],array) << endl;
    cin >> tmp;
    return 0;
}

