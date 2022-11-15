#include <iostream>

using namespace std;



class Base
{
    virtual ostream& print(ostream& out) const
    {
        out << "Base class";
        return out;
    }

protected:
    int value{};
public:
    Base(int value) : value{ value } {}
    virtual string GetName() const
    {
        return "Base class";
    }

    friend ostream& operator<<(ostream& out, const Base& base)
    {
        return base.print(out);
    }

    int GetValue() const { return value; }
    virtual ~Base() = default;
};



class Derived : public Base
{
    ostream& print(ostream& out) const override
    {
        out << "Derived class";
        return out;
    }
protected:
    string name{};
public:
    Derived(int value, const string& name) : Base(value), name{ name } {}
    string GetName() const override
    {
        return "Derived class " + name;
    }
    friend ostream& operator<<(ostream& out, const Derived& derived)
    {
        return derived.print(out);
    }
};

//void NamePrint(Base base)
//{
//    cout << base.GetName() << "\n";
//}

Base* ObjectFactory(bool flag)
{
    if (flag)
        return new Derived(100, "Joe");
    else
        return new Base(200);
}

int main()
{
    /*float x{ 10.3 };
    int n{ (int)x };*/

    /*Base* base = new Derived(10);
    cout << base->GetName() << "\n";

    NamePrint(*base);*/


    //Base* base = ObjectFactory(true);

    //cout << base->GetName() << "\n";

    //
    //Derived* derivaed = dynamic_cast<Derived*>(base);
    ////Derived* derivaed = (Derived*)base;
    //if(derivaed)
    //    cout << derivaed->GetName() << "\n";
    //else
    //    cout << "conversion error\n";
    
    //delete base;

    //Base* base = new Base(100);

    Derived derived(200, "Bob");

    Base& base = derived;

    cout << base << "\n";
    cout << derived << "\n";

    return 0;
}
