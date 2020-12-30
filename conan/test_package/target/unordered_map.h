/*
 * @Author: your name
 * @Date: 2020-11-25 19:02:09
 * @LastEditTime: 2020-12-14 11:48:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /conan/test_package/target/unordered_map.h
 */
#include <unordered_map>
#include <stdio.h>
#include <mutex>
#include <array>

class unordered_map
{
private:
    std::mutex gMutex;
    std::unordered_map<std::string, size_t> gCIDList;
public:
    void test() {
        std::unordered_map<int, int> test;
        printf("size = %d\n", test.size());
        printf("9 index value %d\n", test[9]);
        printf("size = %d\n", test.size());

        std::array<std::string, 3> cidList = {"123", "456", "789"};
        for(const auto &s: cidList) {
            std::cout << s <<  " --- " << transformCID2ChannelId(std::move(s)) << "\n";
        }        
    }

    size_t transformCID2ChannelId(const std::string && cid) {
        std::lock_guard<std::mutex> lk(gMutex);

        auto channelId = -1;
        auto result = gCIDList.find(cid);
        if (result != gCIDList.end()) {
            channelId = result->second;            
        } else {
            channelId = gCIDList.size()+1;
            gCIDList.emplace(cid, channelId);
        }
        
        return channelId;
    }
};
