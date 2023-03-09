/* write a class employee  with employ id and name
derived class for full time employ with salary
derived class for part time employ with daily wages
output name id and wages */

#include <iostream>
using namespace std;

class employee
{
private:
    string name;
    int id;

public:
    employee(string n = "0", int l = 0)
    {
        name = n;
        id = l;
    }
    int getid()
    {
        return id;
    }
    string getname()
    {
        return name;
    }
    void setid(int l)
    {
        id = l;
    }
    void setname(string n)
    {
        name = n;
    }
};
class fullemployee : public employee
{
private:
    int salary;

public:
    fullemployee(string n, int l, int s)
    {
        salary = s;
        setname(n);
        setid(l);
    }
    void setsalary(int p)
    {
        salary = p;
    }
    int getsalary()
    {
        return salary;
    }
};
class partemployee : public employee
{
private:
    int wage;

public:
    partemployee(string n, int o, int p)   // also can inherit the constructor
    {
        wage = p;
        setname(n);
        setid(o);
    }
    void setwage(int l)
    {
        wage = l;
    }
    int getwage()
    {
        return wage;
    }
};
int main(int argc, char const *argv[])
{
    fullemployee p1("conan", 31, 31675);
    partemployee p2("sid", 78, 789);
    cout << p2.getname() << " " << p2.getid() << " " << p2.getwage() << endl;
    cout << p1.getname() << " " << p1.getid() << " " << p1.getsalary() << endl;
    return 0;
}
