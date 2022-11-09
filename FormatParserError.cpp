// FormatParserError.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


void SetWeAreCrashing();
void FailFast(const char * condition, const char * filename, const char * function, int linenumber, const char * msg);

#include <format>

template <typename PointerType>
class RelativePointer
{
public:
    void Set(uint8_t * memoryBase, PointerType * pointer)
    {
        if (!(((size_t(memoryBase) & 0xffff'0000'0000'0000) == 0)))
        {
            [[unlikely]]
            SetWeAreCrashing();
            FailFast("((size_t(memoryBase) & 0xffff000000000000) == 0)", __FILE__, __FUNCTION__, __LINE__, std::format("memoryBase = {0:016x} - shouldn't be a crazy number, something's wrong", size_t(memoryBase)).c_str());
        }
    }
};



int main()
{
}
