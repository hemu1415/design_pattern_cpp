#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class AbstractProduct
{
public:
        virtual void getResult()=0;

};

class ConcreteProductA:public AbstractProduct
{
public:
        void getResult(){
            std::cout<<"ConcreteProductA::getResult()"<<std::endl;
        }
};

class ConcreteProductB:public AbstractProduct
{
public:
        void getResult(){
            std::cout<<"ConcreteProductB::getResult()"<<std::endl;
        }
};

class ConcreteProductC:public AbstractProduct
{
public:
        void getResult(){
            std::cout<<"ConcreteProductC::getResult()"<<std::endl;
        }
};

class SimpleFactory
{
    public:
    static AbstractProduct* createProduct(char type);
};

AbstractProduct* SimpleFactory::createProduct(char type)
{
    AbstractProduct * result;
    switch(type)
    {
        case 'a':
        {
            result=new ConcreteProductA();
            break;
        }   
        case 'b':
        {
            result=new ConcreteProductB();
            break;
        }
        case 'c':
        {
            result=new ConcreteProductC();
            break;
        }
        default :
        {
            result=NULL;
            break;          
        }
    }
}

//client
int main()
{
    SimpleFactory::createProduct('a')->getResult();
    SimpleFactory::createProduct('b')->getResult();
    SimpleFactory::createProduct('c')->getResult();
    return 0;
}
