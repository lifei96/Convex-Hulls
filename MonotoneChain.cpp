//
// Created by Fei Li on 2018/5/26.
//

#include "MonotoneChain.h"
#include "util.h"

std::vector<Point> MonotoneChain::monotoneChain(std::vector<Point> &dataset) {
    int n = (int) dataset.size();
    std::vector<Point> CH( 2U * n);
    sort(dataset.begin(), dataset.end(), xOrder());
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && util::getArea(CH[k - 2], CH[k - 1], dataset[i]) <= 0) {
            k--;
        }
        CH[k++] = dataset[i];
    }
    for (int i = n - 1, t = k + 1; i > 0; i--) {
        while (k >= t &&
               util::getArea(CH[k - 2], CH[k - 1], dataset[i - 1]) <= 0) {
            k--;
        }
        CH[k++] = dataset[i - 1];
    }
    CH.resize(k - 1U);
    return CH;
}