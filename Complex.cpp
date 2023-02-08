

// 重载 +、-、取负-、++、--、后置++、后置-- 为类的友元函数 或 成员函数。
#include <iostream>
using namespace std;
class Complex {
    private:
        double real, image;
    public:
        Complex(double real = 50.0, double image = 0.0)
        {
            cout << "constructing " << endl;
            this->real = real, this->image = image;
        }
        Complex(Complex& RC)
        {
            cout << "copy constructing ..." << endl;
            real = RC.real;
            image = RC.image;
        }
        ~Complex()
        {
            // cout << real << endl;
            // cout << "destructing ..." << endl;
        }
        void display()
        {
            cout << "(" << real << ", " << image << ")" << endl;
        }
        // Complex& operator+ (Complex B);
        // Complex& operator- (Complex B);
        friend Complex operator+ (Complex A, Complex B);
        friend Complex operator- (Complex A, Complex B);

        Complex& operator- ();
        Complex operator++ ();
        Complex operator++ (int);
        //Complex operator= (Complex B);
        Complex operator+= (Complex B);
};
// 重载->
class PComplex 
{
    private:
        Complex * PC;
    public:
        PComplex(Complex * PC = NULL)
        {
            this->PC = PC;
        }
        Complex * operator->()
        {
            cout << "null comp  ";
            static Complex nullComplex = Complex(0, 0);
            cout << "asdfa" << endl;
            if (PC == NULL)
            {
                return &nullComplex;
            }
            
            return PC;
        }
};
/*
Complex& Complex::operator+ (Complex B)   
{
    return Complex(real + B.real, image + B.image);
}
Complex& Complex::operator- (Complex B)
{
    return Complex(real - B.real, image - B.image);
}
*/
Complex operator+ (Complex A, Complex B)
{
    return Complex(A.real + B.real, A.image + B.image);
}
Complex operator- (Complex A, Complex B)
{
    return Complex(A.real - B.real, A.image - B.image);
}

Complex& Complex::operator- ()
{
    *this = Complex(-real, -image);
    return *this;
}
Complex Complex::operator++ ()
{
    return Complex(++real, image);
}
Complex Complex::operator++ (int)
{
    return Complex(real++, image);
}

// 重载复数赋值=运算
// Complex Complex::operator= (Complex B)
// {
//     real = B.real, image = B.image;
//     return * this;
//     // return Complex(B.real, B.image);    // 错误；这样赋值的话，结果是 凡是有赋值的地方，其值都是形参B调用自身构造函数的默认形参值；
// }

// 重载复数 += 元算
Complex Complex::operator+= (Complex B)
{
    real += B.real, image += B.image;
    return * this;
}
int main()
{
    // B(-10.0, 20.0),
    Complex A(100.0, 200.0), C;
    
    // C = A + B;  // A + B 在编译的时候被编译成 A.operator+ (B), 然后匹配调用对应的重载函数；
                
    // C.display();
    // C = A - B;
    // C.display();
    // C = -A + B;
    // C.display();

    // C = A++;
    // C.display();
    // C = ++A;
    // C.display();
    // C = A + 5;
    // C.display();

    cout << "A: ";  A.display();
    C = A;
    C.display();

    // A += B;
    // A.display();
    PComplex P1;
    P1->display();
    
    P1 = &A;
    P1->display();

    return 0;
}