

// 重载 +、-、取负-、++、--、后置++、后置-- 为类的友元函数
#include <iostream>
using namespace std;
class Complex {
    private:
        double real, image;
    public:
        Complex(double real = 0.0, double image = 0.0)
        {
            // cout << "constructing " << endl;
            this->real = real, this->image = image;
        }
        Complex(Complex& RC)
        {
            // cout << "copy constructing ..." << endl;
            real = RC.real;
            image = RC.image;
        }
        ~Complex()
        {
            // cout << real << endl;
            // cout << "destrucing ..." << endl;
        }
        void display()
        {
            cout << "(" << real << ", " << image << ")" << endl;
        }
        Complex operator+ (Complex B);
        Complex operator- (Complex B);
        Complex operator- ();
        Complex operator++ ();
        Complex operator++ (int);
};
Complex Complex::operator+ (Complex B)   
{
    return Complex(real + B.real, image + B.image);
}
Complex Complex::operator- (Complex B)
{
    return Complex(real - B.real, image - B.image);
}
Complex Complex::operator- ()
{
    return Complex(-real, -image);
}
Complex Complex::operator++ ()
{
    return Complex(++real, image);
}
Complex Complex::operator++ (int)
{
    return Complex(real++, image);
}
int main()
{
    Complex A(100.0, 200.0), B(-10.0, 20.0), C;
    
    C = A + B;  // A + B 在编译的时候被编译成 A.operator+ (B), 然后匹配调用对应的重载函数；
    C.display();
    C = A - B;
    C.display();
    C = -A + B;
    C.display();

    C = A++;
    C.display();
    C = ++A;
    C.display();
    C = A + 5;
    C.display();

    return 0;
}