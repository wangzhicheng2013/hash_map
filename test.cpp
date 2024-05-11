#include <iostream>
#include "hash_map.hpp"
#include "time_elapse.hpp"
int main() {
    std::string key;
    int value = 0;
    hash_map<int>hm;
    hm.init();
    const int LEN = 6;
    std::string keys[LEN] = {
        "ABC dsk122",
        "PPPPPPP _09#$",
        "009oPPPnb%4555_98*",
        "ghv$$#22_*----=====AAAAA",
        "ghv$$#22_*----=====cAbAAgg",
        "0------011111111111KK_aaaa@+!!~",
    };
    int values[LEN] = {
        901,
        -1000,
        89,
        1,
        -111,
        9000,
    };
    for (int i = 0;i < LEN;i++) {
        hm.put(keys[i], values[i]);
    }
    time_elapse te;
    while (true) {
        int id;
        std::cin >> id;
        if (id < 0 || id >= LEN) {
            std::cout << id << " is invalid!" << std::endl;
            break;
        }
        te.start();
        if (hm.get(keys[id], value)) {
            std::cout << te.end() << std::endl;
            std::cout << "value:" << value << std::endl;
        }
    }
    return 0;
}