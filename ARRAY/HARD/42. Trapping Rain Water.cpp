#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

namespace impl
{
    template < typename T > inline void do_print( const T& v, std::ostream& stm ) { stm << v << ' ' ; }

    template < typename F, typename S > // print pair
    inline void do_print( const std::pair<F,S>& p, std::ostream& stm )
    { stm << '{' << p.first << ',' << p.second << "} " ; }
}

template < typename... ARGS, template < typename... > class SEQ  > // print for standard contaners
void print( const SEQ<ARGS...>& seq, std::ostream& stm = std::cout, typename SEQ<ARGS...>::iterator* = 0  )
{ stm << "[ " ; for( const auto& v : seq ) impl::do_print(v,stm) ; stm << "]\n" ; }

// overload for C-style array
template < typename T, std::size_t N > void print( T (&seq)[N], std::ostream& stm = std::cout )
{ stm << "[ " ; for( const auto& v : seq ) impl::do_print(v,stm) ; stm << "]\n" ; }

#include <array> // overload for std::array
template < typename T, std::size_t N > void print( const std::array<T,N>& seq, std::ostream& stm = std::cout )
{ stm << "[ " ; for( const auto& v : seq ) impl::do_print(v,stm) ; stm << "]\n" ; }

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int>getLeftMax(vector<int> &height, int n){
        vector<int>result(n);
        result[0] = height[0];
        for(int i = 1; i < n; i++){
            result[i] = max(result[i - 1], height[i]);
        }
        return result;
    }
    vector<int>getRightMax(vector<int> &height, int n){
        vector<int> result(n);
        result[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            result[i] = max(result[i + 1], height[i]);
        }
        return result;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int>leftMax = getLeftMax(height, n);
        vector<int>rightMax = getRightMax(height, n);
        print(leftMax);
        for(int i = 0; i < n; i++){
            ans  = ans + (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return ans;
    }
};
