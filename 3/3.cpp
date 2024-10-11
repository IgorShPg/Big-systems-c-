#include <iostream>
#include <memory>

template <typename T, typename Y = T>
struct My_Allocator
{
    typedef T value_type;
    My_Allocator() noexcept {}

    template <class U>
    My_Allocator(const My_Allocator<U> &) noexcept {};

    T *allocate(std::size_t n)
    {
        return static_cast<T *>(Y::operator new(sizeof(T) * n));
    }

    void deallocate(T *p, std::size_t n)
    {
        return Y::operator delete(p, sizeof(T) * n);
    }
};

class A
{
public:
    static void *operator new(size_t size)
    {
        std::cout << "operator new!" << std::endl;
        return ::operator new(size);
    }
    static void operator delete(void *p, size_t size)
    {
        std::cout << "operator delete!" << std::endl;
        return ::operator delete(p);
    }
};

int main()
{
    std::shared_ptr<A> sp = std::allocate_shared<A>(My_Allocator<A>());
    //auto sp=std::make_shared<A>();
    return 0;
}