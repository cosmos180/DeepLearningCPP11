#include <stdio.h>
#include <vector>

class STDMove
{
public:
    void test()
    {
        std::vector<float> A;
        A.resize(256);

        auto B = std::move(A);

        printf("A size %u, B size %u", A.size(), B.size());
    }
};