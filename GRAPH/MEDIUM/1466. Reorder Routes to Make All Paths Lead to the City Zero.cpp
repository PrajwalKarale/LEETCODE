#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
namespace impl {
    template <typename T>
    inline void do_print(const T& v, std::ostream& stm) { 
        stm << v << ' '; 
    }

    template <typename F, typename S> // print pair
    inline void do_print(const std::pair<F, S>& p, std::ostream& stm) {
        stm << '{' << p.first << ',' << p.second << "} ";
    }

    // Overload for vector of pairs
    template <typename T>
    inline void do_print(const std::vector<T>& vec, std::ostream& stm) {
        stm << "[ ";
        for (const auto& v : vec) {
            do_print(v, stm);
        }
        stm << "] ";
    }
}

template <typename... ARGS, template <typename...> class SEQ>
void print(const SEQ<ARGS...>& seq, std::ostream& stm = std::cout, typename SEQ<ARGS...>::iterator* = 0) {
    stm << "[ ";
    for (const auto& v : seq) {
        impl::do_print(v, stm);
    }
    stm << "]\n";
}

// Overload for C-style array
template <typename T, std::size_t N>
void print(T (&seq)[N], std::ostream& stm = std::cout) {
    stm << "[ ";
    for (const auto& v : seq) {
        impl::do_print(v, stm);
    }
    stm << "]\n";
}

// Overload for std::array
template <typename T, std::size_t N>
void print(const std::array<T, N>& seq, std::ostream& stm = std::cout) {
    stm << "[ ";
    for (const auto& v : seq) {
        impl::do_print(v, stm);
    }
    stm << "]\n";
}

// Overload for std::unordered_map
template <typename K, typename V>
void print(const std::unordered_map<K, V>& map, std::ostream& stm = std::cout) {
    stm << "{ ";
    for (const auto& kv : map) {
        stm << kv.first << ": ";
        impl::do_print(kv.second, stm);
        stm << ", ";
    }
    stm << "}\n";
}

auto initialize = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
    typedef std::pair<int, int> p;
public:
    void dfs(unordered_map<int, std::vector<p>> &adjList, int u, int parent, int &count){
        for(auto &it: adjList[u]){
            if(it.first != parent){
                if(it.second == 1){
                    count++;
                }
                dfs(adjList, it.first, u, count);
            }
        }
    }
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        int count = 0;
        unordered_map<int, std::vector<p>> adjList;
        for (auto& connect : connections) {
            int u = connect[0];
            int v = connect[1];
            // Asli edge
            adjList[u].push_back({v, 1});
            // Nakli edge
            adjList[v].push_back({u, 0});
        }
        dfs(adjList, 0, -1, count);
        return count;
    }
};
