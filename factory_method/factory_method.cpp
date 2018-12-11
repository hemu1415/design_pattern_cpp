#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Product
{
    public:
    virtual void show()=0;
};

class ConcreteProductA:public Product
{
    public:
            void show()
            {
                std::cout<<"ConcreteProductA:show"<<std::endl;
            }
};

class ConcreteProductB:public Product
{
    public:
            void show()
            {
                std::cout<<"ConcreteProductB:show"<<std::endl;
            }

};

class Creator
{
    public:
            virtual Product * factoryMethod()=0;

};

class ConcreteCreatorA:public Creator
{
    public:
            Product* factoryMethod()
            {
                return new ConcreteProductA();
            }

};

class ConcreteCreatorB:public Creator
{
    public:
            Product* factoryMethod()
            {
                return new ConcreteProductB();
            }

};


int main()
{
    Creator * creatorA=new ConcreteCreatorA;
    Creator * creatorB=new ConcreteCreatorB;

    Product * pa=creatorA->factoryMethod();
    Product* pb=creatorB->factoryMethod();

    pa->show();
    pb->show();

    delete creatorA;
    delete creatorB;
    delete pa;
    delete pb;
    return 0;
}
