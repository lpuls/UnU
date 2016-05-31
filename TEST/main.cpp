#include <iostream>

class Tyy
{
public:
    Tyy();
    ~Tyy();

    virtual void a();

private:
    
};

Tyy::Tyy()
{
    std::cout << "Say hi" << std::endl;
}

Tyy::~Tyy()
{
}

void Tyy::a()
{
    std::cout << "hi hi hi ~~~" << std::endl;
}

class Wek : public Tyy
{
public:
    Wek();
    ~Wek();
    
    void fuck();
    
    void a();
private:
    
};

Wek::Wek()
{
    std::cout << "Say hello" << std::endl;
}

Wek::~Wek()
{
}

void Wek::a()
{
    std::cout << "yo yo yo ~~~~" << std::endl;
}

void Wek::fuck()
{
    std::cout << "fuck fuck !!" << std::endl;  
}

int main()
{
    auto wek = new Wek();
    Tyy *t = wek;
    t->a();
    return 0;
}