#include "Cache.h"

Cache::Cache(int kk, int mm, vector<int> &rr) : k(kk), m(mm), i(0), misses(0), r(rr) {}

FIFO::FIFO(int kk, int mm, vector<int> &rr) : Cache(kk, mm, rr) {}

bool FIFO::nextItem() {
    if (inCache.find(r[i]) == inCache.end()) {
        misses++;
        if (inCache.size() == k) {
            int toRemove = q.front();
            q.pop();
            inCache.erase(toRemove);
        }
        q.push(r[i]);
        inCache.insert(r[i]);
    }

    return ++i < m;
}