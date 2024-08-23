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
    string fractionAddition(string expression) {
        int l = expression.length();
        int i = 0;
        int numerator = 0;
        int denominator = 1;
        while(i < l){
            int currentNumerator = 0;
            int currentDenominator = 0;
            bool isNegative = (expression[i] == '-');
            if(expression[i] == '+' || expression[i] == '-'){
                i++;
            }
            // Creating currentNumerator
            while(i < l && isdigit(expression[i])){
                int val = expression[i] - '0';
                currentNumerator = (currentNumerator * 10) + val;
                i++;
            }

            i++;
            if(isNegative){
                currentNumerator *= -1;
            }
            // Creating denominator
            while(i < l && isdigit(expression[i])){
                int val = expression[i] - '0';
                currentDenominator = (currentDenominator * 10) + val;
                i++;
            }
            numerator = numerator * currentDenominator + denominator * currentNumerator;
            denominator = denominator * currentDenominator;
        }
        int GCD = abs(__gcd(numerator, denominator));
        numerator = numerator / GCD;
        denominator = denominator / GCD;
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
