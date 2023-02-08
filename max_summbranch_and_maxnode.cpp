// Finding max-summ branch of tree and max node

#include <iostream>
#include <memory>
#include <cassert>
#include <functional>

struct Node {
    Node(int value_, std::shared_ptr<Node> left_, std::shared_ptr<Node> right_) : 
    value(value_), left(left_), right(right_) {}
    
    int value;
    std::shared_ptr<Node> left, right;
};

int getMaxNode(int value, int left, int right) {
    return std::max( std::max(left, value), std::max(right, value) );
}

int getMaxSumm(int value, int left, int right) {
    return std::max(left + value, right + value); 
}

int goThruTree(std::shared_ptr<Node> N, std::function<int(int, int, int)> func) {
    int left{}, right{};
    if (N->left)
        left = goThruTree(N->left, func);
    if (N->right)
        right = goThruTree(N->right, func);
    return func(N->value, left, right); 
}

//       1
//    2      3
// 4             5(2)     



int main() {
    auto n4 = std::make_shared<Node>(4, nullptr, nullptr);
    auto n5 = std::make_shared<Node>(5, nullptr, nullptr);
    auto n2 = std::make_shared<Node>(2, n4, nullptr);
    auto n3 = std::make_shared<Node>(3, nullptr, nullptr);
    auto n1 = std::make_shared<Node>(1, n2, n3);

    int res = goThruTree(n1, getMaxSumm);
    std::cout << res << '\n';
    assert(res == 7);
    
    n3->right = n5;
    res = goThruTree(n1, getMaxSumm);
    std::cout << res << '\n';
    assert(res == 9);

    res = goThruTree(n1, getMaxNode);
    std::cout << res << '\n';
    assert(res == 5);
}
