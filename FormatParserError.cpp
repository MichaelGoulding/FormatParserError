#include <format>

void Foo(const char * msg);

template <typename PointerType>
class RelativePointer
{
public:
    void Set(uint8_t * memoryBase, PointerType * pointer)
    {
        Foo(std::format("memoryBase = {0:016x} - shouldn't be a crazy number, something's wrong", size_t(memoryBase)).c_str());

        // Below works
        //auto str = std::format("memoryBase = {0:016x} - shouldn't be a crazy number, something's wrong", size_t(memoryBase));
        //Foo(str.c_str());
    }
};



int main()
{

}
