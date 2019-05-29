class NoDtor {
public:
    NoDtor() = default;
    ~NoDtor() = delete;
};

class PriDtor{
public:
    static PriDtor* New() { return new PriDtor(); };
    static void Del(PriDtor* p) { delete p; };
private:
    PriDtor() = default;
    ~PriDtor() = default;
};

int main()
{
    // NoDtor d;  // invalid
    auto d = new NoDtor();
    // delete d; // invalid

    // PriDtor p;  // invalid
    auto p = PriDtor::New();
    PriDtor::Del(p);
    return 0;
}
