#include <iostream>
#include <vector>


template <typename It>
It minnn(It first, It last){
    if (first == last) return last;
    
    It max = first;
    ++first;
    for ( ; first != last; ++first) {
        if ( *max < *first) 
            max = first;
    }
    
    return max;
        
}

int main() {
    std::vector<int> v {7, 5, 9, 4, 3, 2, 1};
    for (std::vector<int>::iterator it = v.begin(); it != v.end() - 2; ++it)
        std::cout << *it << " ";
    
    std::cout << '\n' << '\n';
    
    std::vector<int> v2 {7, 9, 5, 6, 4, 8, 3, 15, 26, 14, 19};
    auto y = minnn<std::vector<int>::iterator>(v2.begin(), v2.end() - 3);
    std::cout << *y;
    return 0;
}