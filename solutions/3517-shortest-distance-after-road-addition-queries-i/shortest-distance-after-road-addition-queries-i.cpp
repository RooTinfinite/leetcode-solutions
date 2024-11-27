#define SANITIZER_DISABLE __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define FORCE_INLINE __attribute__((always_inline))
#define OPTIMIZE_HOT __attribute__((hot))
#define INLINE_OPTIMIZED noexcept FORCE_INLINE SANITIZER_DISABLE OPTIMIZE_HOT
#define OUTLINE_OPTIMIZED noexcept SANITIZER_DISABLE OPTIMIZE_HOT
#define LAMBDA_OPTIMIZED FORCE_INLINE SANITIZER_DISABLE OPTIMIZE_HOT noexcept

class Solution {
private:
    static constexpr uint16_t MAX_SIZE = 500;
    static bitset<MAX_SIZE> adjacencyMatrix[MAX_SIZE];

    static void resetMatrix(const uint16_t size) INLINE_OPTIMIZED {
        const uint8_t blockCount = (size + 63u) >> 6;
        
        uint64_t* firstRow = (uint64_t*)adjacencyMatrix;
        fill(firstRow, firstRow + blockCount, 0);

        for (uint16_t row = 1; row < size; row++) {
            uint64_t* currentRow = (uint64_t*)(adjacencyMatrix + row);
            fill(currentRow, currentRow + blockCount, 0);
            adjacencyMatrix[row].set(row - 1u);
        }
    }

    static void updateDistances(const uint16_t size, const uint16_t current, uint16_t distances[]) OUTLINE_OPTIMIZED {
        const uint16_t newDistance = distances[current] + 1u;
        const uint8_t blockCount = (size + 63u) >> 6;
        const uint64_t* currentRow = (const uint64_t*)(adjacencyMatrix + current);

        for (uint8_t block = 0; block < blockCount; block++) {
            const uint16_t baseIndex = block << 6;
            for (uint64_t bits = currentRow[block]; bits; ) {
                const uint8_t offset = countr_zero(bits);
                const uint16_t neighbor = baseIndex + offset;
                
                uint16_t& neighborDist = distances[neighbor];
                if (neighborDist > newDistance) {
                    neighborDist = newDistance;
                    updateDistances(size, neighbor, distances);
                }
                bits ^= 1ull << offset;
            }
        }
    }

public:
    static vector<int> shortestDistanceAfterQueries(const uint16_t size, vector<vector<int>>& queries) OUTLINE_OPTIMIZED {
        uint16_t distances[size], value = size;
        generate_n(distances, size, [&value]() LAMBDA_OPTIMIZED { return --value; });

        const uint16_t queryCount = queries.size();
        vector<int>& result = queries.front();
        
        {
            const uint16_t source = result[0], target = result[1];
            adjacencyMatrix[target].set(source);
            distances[source] = min(distances[source] + 0u, distances[target] + 1u);
            updateDistances(size, source, distances);
            
            result.clear();
            result.reserve(queryCount);
            result.push_back(*distances);
        }

        for (uint16_t i = 1; i < queryCount; i++) {
            const uint16_t source = queries[i][0], target = queries[i][1];
            adjacencyMatrix[target].set(source);
            distances[source] = min(distances[source] + 0u, distances[target] + 1u);
            updateDistances(size, source, distances);
            result.push_back(*distances);
        }

        resetMatrix(size);
        return move(result);
    }

    static void initialize() INLINE_OPTIMIZED {
        for (uint16_t i = 1; i < MAX_SIZE; i++)
            adjacencyMatrix[i].set(i - 1u);
    }
};

bitset<Solution::MAX_SIZE> Solution::adjacencyMatrix[MAX_SIZE];

auto initialize = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution::initialize();
    return 'c';
}();