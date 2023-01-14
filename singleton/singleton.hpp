#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_
#include <memory>
#include <mutex>

class Singleton
{
    public:

    static Singleton& getInstance();
    Singleton(const Singleton& ) = delete;
    Singleton& operator = (const Singleton& ) = delete;
    ~Singleton() = default;
    
    private: 
        Singleton() = default;

};
#endif //SINGLETON_HPP_