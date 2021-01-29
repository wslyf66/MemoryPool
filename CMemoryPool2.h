#ifndef CMEMORY_POOL2_H
#define CMEMORY_POOL2_H

#define EXPANSION_SIZE 32

template<typename T>
class CMemoryPool2
{
public:
    CMemoryPool2(unsigned int nItemCount = EXPANSION_SIZE)
    {
        ExpandFreeList(nItemCount);
    }

    ~CMemoryPool2()
    {

    }

    void* Alloc()
    {
        if(m_pFreeList == nullptr)
        {
            ExpandFreeList();
        }
        
        CMemoryPool2<T>* pHead = m_pFreeList;
        m_pFreeList
        return pHead;
    }

private:
    void ExpandFreeList(unsigned int nItemCount = EXPANSION_SIZE)
    {

    }

private:
    CMemoryPool2<T>* m_pFreeList;
};

#endif