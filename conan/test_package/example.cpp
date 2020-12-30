/*
 * @Author: your name
 * @Date: 2020-07-06 10:18:28
 * @LastEditTime: 2020-12-30 15:36:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /conan-zlib/test_package/test.cpp
 */
// Example program
#include <iostream>
#include <cstring>
#include <inttypes.h>
#include "target/BitmapCounter.h"
#include "target/CStringArray.h"
#include "target/Cache.h"
#include "target/STLType.h"
#include "target/unordered_map.h"
#include "target/network.h"

template<typename Target>
int runTargetMethod() {
    Target *t = new Target();
    t->test();
    delete t;
    t = nullptr;
}

#define RUN(T) runTargetMethod<T>()

int main(int argc, char *argv[])
{
    for (size_t i = 0; i < argc; i++)
    {
        printf("param %d is %s\n", i, argv[i]);
    }
    
    int ret = 0;
    ret = RUN(BitmapCounter<EightBitOneNumber>);
    // ret = RUN(BitmapCounter<FourBitOneNumber>);
    // ret = RUN(BitmapCounter<OneBitOneNumber>);
    // ret = RUN(CStringArray);
    // ret = RUN(Cache);
    // ret = RUN(STLType);
    // ret = RUN(unordered_map);
    // ret = RUN(Network);
    return ret;
}
