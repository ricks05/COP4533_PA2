#include <vector>
#include <queue>
#include <unordered_set>
#include <list>
#include <unordered_map>
#include <set>
#include <climits>

#pragma once

using namespace std;

class Cache {
protected:
    int k, m, i;
    vector<int> r;
public:
    int misses;
    Cache(int kk, int mm, vector<int>& rr);
    virtual bool nextItem() = 0;
};

class FIFO : public Cache {
    unordered_set<int> cache;
    queue<int> q;
public:
    FIFO(int kk, int mm, vector<int>& rr);
    bool nextItem() override;
};

class LRU : public Cache {
    list<int> cache;
    unordered_map<int, list<int>::iterator> pos;
public:
    LRU(int kk, int mm, vector<int>& rr);
    bool nextItem() override;
};

class OPTFF : public Cache {
    set<pair<int, int>, greater<>> cache;
    unordered_map<int, queue<int>> pos;
public:
    OPTFF(int kk, int mm, vector<int>& rr);
    bool nextItem() override;
};