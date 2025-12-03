#pragma once
#include "grid.h"
#include "rules.h"
#include <vector>

class TestTools {
public:
    static bool compare(const Grid& g, const std::vector<std::vector<int>>& expected);
    static bool runTest(const std::vector<std::vector<int>>& start,
        const std::vector<std::vector<int>>& expected,
        int iterations,
        Rules& rules);
};