#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include<unordered_set>

using namespace std;

class Cache {
protected:
    int k, m, i;
    vector<int> r;
    unordered_set<int> inCache;
public:
    int misses;
    Cache(int kk, int mm, vector<int>& rr) : k(kk), m(mm), i(0), misses(0), r(rr) {}
    virtual bool nextItem() = 0;
};

class FIFO : public Cache {
    queue<int> q;
public:
    FIFO(int kk, int mm, vector<int>& rr) : Cache(kk, mm, rr) {}
    bool nextItem() override {
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
};

int main() {
    ifstream input(".\\COP4533_PA2\\example.in");
    if (!input) {
        cerr << "Failed to open example.in";
        return 1;
    }

    int k, m;
    input >> k >> m;

    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        input >> r[i];
    }

    FIFO fifo(k, m, r);
    while (fifo.nextItem()) {}
    cout << "FIFO  : " << fifo.misses << endl;

    return 0;
}
