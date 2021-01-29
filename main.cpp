#include <iostream>
#include <vector>
#include <ctime>
#include "MemoryPool.h"
#include "StackAlloc.h"

#define ELEMS 10000
#define REPS 10

int main(int argc, char* argv[])
{
    clock_t start,end;
    //---------Stack default------//
    StackAlloc<int, std::allocator<int>> stackDefault;
    start = clock();
    for(int i=0;i<REPS;i++)
    {
        for(int j=0;j<ELEMS;j++)
            stackDefault.push(j);

        for(int j=0;j<ELEMS;j++)
            stackDefault.pop();
    }
    end = clock();
    std::cout << "Stack default execute time: " << (double)(end - start)/CLOCKS_PER_SEC << "s" << std::endl;
    //------------vector----------//
    std::vector<int> stackVector;
    start = clock();
    for(int i=0;i<REPS;i++)
    {
        for(int j=0;j<ELEMS;j++)
            stackVector.push_back(j);

        for(int j=0;j<ELEMS;j++)
            stackVector.pop_back();
    }
    end = clock();
    std::cout << "Vector execute time: " << (double)(end - start)/CLOCKS_PER_SEC << "s" << std::endl;
    //----------MemoryPool--------//
    StackAlloc<int, MemoryPool<int>> stackPool;
    start = clock();

    for(int i=0;i<REPS;i++)
    {
        for(int j=0;j<ELEMS;j++)
            stackPool.push(j);

        for(int j=0;j<ELEMS;j++)
            stackPool.pop();
    }

    end = clock();
    std::cout << "Memory Pool execute time: " << (double)(end - start)/CLOCKS_PER_SEC << "s" << std::endl;
    return 0;
}
