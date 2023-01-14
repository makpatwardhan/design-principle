#include "singleton.hpp"

Singleton& Singleton::getInstance()
{
   static Singleton s;
   return s;
}


int main(void)
{
    Singleton &s = Singleton::getInstance();
}