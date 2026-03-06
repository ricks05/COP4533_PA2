#include "Cache.h"
#include <iostream>
#include <fstream>

int main() {
    ifstream input("..\\example.in");
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

    LRU lru(k, m, r);
    while (lru.nextItem()) {}
    cout << "LRU   : " << lru.misses << endl;

    return 0;
}
