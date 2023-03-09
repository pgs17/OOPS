/* wap to demonstrTE polymorphism
base class shape
derived class
rectangle , circle
output = area and perimeter */
#include <iostream>
using namespace std;

class shape
{
public:
    virtual int area() = 0;
    virtual int perimeter() = 0;
};
class rectangle : public shape
{
private:
    int length;
    int breadth;

public:
    rectangle(int l = 0, int b = 0)
    {
        length = l;
        breadth = b;
    }
    rectangle(rectangle &r)
    {
        r.length = length;
        r.breadth = breadth;
    }
    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};
class circle : public shape
{
private:
    int radius;

public:
    circle(int r = 0)
    {
        radius = r;
    }
    circle(circle &c)
    {
        c.radius = radius;
    }
    int area()
    {
        return 3.14 * radius * radius;
    }
    int perimeter()
    {
        return 2 * 3.14 * radius;
    }
};
int main(int argc, char const *argv[])
{
    int l, b;
    cout << "enter length and breadth:";
    cin >> l >> b;
    int r;
    cout << "enter radius:";
    cin >> r;
    shape *ptr = new rectangle(l, b);
    cout << "rectangle area is " << ptr->area() << endl;
    cout << "rectangle perimeter is" << ptr->perimeter() << endl;
    ptr = new circle(r);
    cout << "area of circle is " << ptr->area() << endl;
    cout << "perimeter of circle is " << ptr->perimeter() << endl;
    return 0;
}
