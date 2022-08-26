/*
 * @Author: your name
 * @Date: 2020-07-06 10:18:28
 * @LastEditTime: 2021-03-29 14:19:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /conan-zlib/test_package/test.cpp
 */
// Example program
#include <iostream>
#include <cstring>
#include <inttypes.h>
#include <atomic>
#include <string>
#include <cinttypes>
#include <sstream>

#include "target/BitmapCounter.h"
#include "target/CStringArray.h"
#include "target/Cache.h"
#include "target/STLType.h"
#include "target/unordered_map.h"
#include "target/network.h"
#include "target/STDMove.h"
#include "target/ifstream.h"

static std::vector<std::string> split(const std::string &input, const std::string &regex)
{
    std::regex re(regex);
    std::sregex_token_iterator
        first{input.begin(), input.end(), re, -1},
        last;
    return {first, last};
}

template <typename Target>
int runTargetMethod()
{
    Target *t = new Target();
    t->test();
    delete t;
    t = nullptr;
}

// DECLARATION(timestamp, tag, now); \

#define RUN(T) runTargetMethod<T>()

#define CONTACT_STR(tag) #tag.c_str()
#define DECLARATION_VALUE(name, tag, now) static auto name##_tag = now;
#define FPSBenchmarkDefine(tag)                                                                                                        \
    do                                                                                                                                 \
    {                                                                                                                                  \
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); \
        static uint64_t frameIndex = 0;                                                                                                \
        printf("----cid %s fps %f\n", tag.c_str(), 1000.0f * (++frameIndex) / (now - mFirstFrameTimestamp));                           \
    } while (0);

#define FPSBenchmarkDeclareation uint64_t mFirstFrameTimestamp = 0

#define CONCAT(a, b) CONCAT_INNER(a, b)
#define CONCAT_INNER(a, b) a##b

#define UNIQUE_NAME(base) CONCAT(base, __COUNTER__)

int main(int argc, char *argv[])
{
    // for (size_t i = 0; i < argc; i++)
    // {
    //     printf("param %d is %s\n", i, argv[i]);
    // }

    int ret = 0;
    // ret = RUN(BitmapCounter<EightBitOneNumber>);
    // ret = RUN(BitmapCounter<FourBitOneNumber>);
    // ret = RUN(BitmapCounter<OneBitOneNumber>);
    // ret = RUN(CStringArray);
    // ret = RUN(Cache);
    // ret = RUN(STLType);
    // ret = RUN(UnorderedMap);
    // ret = RUN(Network);

    // char *key = "TupuTech-Mobile@Huawei@31415926+";
    // // uint8_t key_v[32] = {"TupuTech-Mobile@Huawei@31415926+"};
    // printf("sizeof %d", strlen(key));

    // uint8_t key[32] = {0};
    // memcpy(key, "TupuTech-Mobile@Huawei@31415926+", 32);
    // printf("key %s size %d\n", key, sizeof(key));

    // uint32_t w = 1920, h = 1080;
    // std::vector<float> _points = {0.3281, 0.4583, 0.5039, 0.6146, 0.75, 0.4722};

    // std::string err = "tupu-smart-endpoint:1.0/box_6c:16:32:16:90:e9\n";
    // printf("%s\n", err.c_str());
    // printf("%s\n", err.erase(string(err).rfind("\n")).c_str());
    // // for (auto i=0;i<6;i+=2) {
    // //     printf("x %f y %f\n", _points[i]*1920, _points[i+1]*1080);
    // // };

    // std::string cid = "07954979912410420101#6026099c0cb4434b988bf6deadbe9ac6";
    // printf("real cid %s\n", split(cid, "#")[0].c_str());

    // std::unordered_map<std::string, std::atomic_bool> mHWCameraStatusList;
    // mHWCameraStatusList.emplace("123", true);
    // printf("%d\n", mHWCameraStatusList["456"].load());
    // printf("%d\n", mHWCameraStatusList["123"].load());
    // ret = RUN(STDMove);

    uint32_t valueLen = 10 * 1024;
    // printf("sizeof(valueLen) %d\n", sizeof(valueLen));

    printf("valueLen p %p\n", (void *)(&valueLen));

    auto p = static_cast<uint64_t>(reinterpret_cast<std::uintptr_t>(&valueLen));

    std::string address = std::to_string(p);
    // snprintf(address.data(), sizeof, "%lx", p);
    // // const char *add = reinterpret_cast<const char *>(&valueLen);

    printf("address: %s\n", address.c_str());
    // auto ptr = std::stoll(address.c_str());

    // uint64_t value;
    // std::istringstream iss(address);
    // // p = std::stoull(address);
    // iss >> p;

    p = strtoull(address.c_str(), nullptr, 10);

    printf("typeid(p) %lx %s %p\n", p, typeid(p).name(), p);
    printf("value: %u\n", *(reinterpret_cast<uint32_t *>(p)));

    RUN(IF_STREAM);

    return ret;
}
