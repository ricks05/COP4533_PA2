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
    if (cache.find(make_pair(lastUsed[r[i]], r[i])) == cache.end()) {
        misses++;
        if (cache.size() == k) {
            cache.erase(cache.begin());
        }
    }
    else {
        cache.erase(make_pair(lastUsed[r[i]], r[i]));
    }
    cache.insert(make_pair(m-i-1, r[i]));
    lastUsed[r[i]] = m-i-1;

    return ++i < m;
}