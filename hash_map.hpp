#pragma once
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
template <class T>
struct hash_node {
    std::string key;
    T value;
    int freq = 0;
    hash_node(const std::string& k, const T& v) : key(k), value(v) {}
    bool operator == (const std::string& k) {
        return key == k;
    }
    hash_node& operator ++() {
        ++freq;
        return *this;
    }
    bool operator > (const hash_node& node) {
        return freq < node.freq;
    }
};
template <class T>
struct hash_map {
    using hash_node_array_type = std::vector<hash_node<T>>;
private:
    std::vector<hash_node_array_type>buckets;
    int size = 100;
    std::hash<std::string>hash_obj;
private:
    int hash_func(const std::string& key) {
        return hash_obj(key) % size;
    }
public:
    inline void set_size(int sz) {
        if (sz > 0 && sz < 100000) {
            size = sz;
        }
    }
    void init() {
        buckets.resize(size);
    }
    void put(const std::string& key, const T& value) {
        int index = hash_func(key);
        buckets[index].emplace_back(hash_node<T>(key, value));
    }
    bool get(const std::string& key, T& value) {
        int index = hash_func(key);
        auto& hash_node_array = buckets[index];
        bool found = false;
        for (auto& node : hash_node_array) {
            if (node == key) {
                ++node;
                found = true;
                value = node.value;
                break;
            }
        }
        if (false == found) {
            return false;
        }
        std::sort(std::begin(hash_node_array), std::end(hash_node_array), [&hash_node_array] (hash_node<T>& one, hash_node<T>& other) {
            return one > other;
        });
        return true;
    }
};