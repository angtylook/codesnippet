class A
{
public:
    A() {};
};

class B {};

class C
{
    A a;
    B b;
};

int main()
{
    C c;
    return 0;
}
