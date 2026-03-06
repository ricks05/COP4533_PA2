#include "Cache.h"

Cache::Cache(int kk, int mm, vector<int> &rr) : k(kk), m(mm), i(0), misses(0), r(rr) {}

FIFO::FIFO(int kk, int mm, vector<int> &rr) : Cache(kk, mm, rr) {}

bool FIFO::nextItem() {
    if (cache.find(r[i]) == cache.end()) {
        misses++;
        if (cache.size() == k) {
            int toRemove = q.front();
            q.pop();
            cache.erase(toRemove);
        }
        q.push(r[i]);
        cache.insert(r[i]);
    }

    return ++i < m;
}

LRU::LRU(int kk, int mm, vector<int> &rr) : Cache(kk, mm, rr) {}

bool LRU::nextItem() {
    auto it = pos.find(r[i]);
    if (it == pos.end()) {
        misses++;
        if (cache.size() == k) {
            int toRemove = cache.front();
            cache.pop_front();
            pos.erase(toRemove);
        }
    }
    else {
        cache.erase(pos[r[i]]);
    }
    cache.push_back(r[i]);
    pos[r[i]] = --cache.end();

    return ++i < m;
}