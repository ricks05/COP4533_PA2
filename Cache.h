#include <vector>
#include <queue>
#include<unordered_set>

#pragma once

using namespace std;

class Cache {
protected:
    int k, m, i;
    vector<int> r;
    unordered_set<int> inCache;
public:
    int misses;
    Cache(int kk, int mm, vector<int>& rr);
    virtual bool nextItem() = 0;
};

class FIFO : public Cache {
    queue<int> q;
public:
    FIFO(int kk, int mm, vector<int>& rr);
    bool nextItem() override;
};