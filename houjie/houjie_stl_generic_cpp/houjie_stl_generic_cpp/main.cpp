//
//  main.cpp
//  houjie_stl_generic_cpp
//
//  Created by 黄炜 on 2022/6/11.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int ia[6] = { 27, 210, 12, 47, 109, 83 };
    vector<int, allocator<int>> vi(ia, ia + 6);
    cout << count_if(vi.begin(), vi.end(), not1(std::bind2nd(less<int>(), 40)));
    return 0;
}
