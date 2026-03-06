#include "Cache.h"
#include <iostream>
#include <fstream>

int main() {
    ifstream input("..\\io\\example.in");
    if (!input) {
        cerr << "Failed to open example.in";
        return 1;
    }

    int k, m;
    input >> k >> m;
    if (k < 1) {
        cerr << "Invalid cache capacity k";
        return 1;
    }

    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        input >> r[i];
    }

    input.close();

    ofstream output("..\\io\\example.out");
    if (!output) {
        cerr << "Failed to open example.out";
        return 1;
    }

    FIFO fifo(k, m, r);
    while (fifo.nextItem()) {}
    output << "FIFO  : " << fifo.misses << endl;

    LRU lru(k, m, r);
    while (lru.nextItem()) {}
    output << "LRU   : " << lru.misses << endl;

    output.close();

    return 0;
}
