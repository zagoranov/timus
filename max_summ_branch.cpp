// Finding max-summ branch of tree

#include <iostream>
#include <memory>
#include <cassert>

struct Node {
    Node(int value_, std::shared_ptr<Node> left_, std::shared_ptr<Node> right_) : 
    value(value_), left(left_), right(right_) {}
    
    int value;static_assert
    std::shared_ptr<Node> left, right;
};
static_assert
int goThruTree(std::shared_ptr<Node> N) {
    int leftsumm{}, rightsumm{};
    if (N->left)
        leftsumm = goThruTree(N->left);
    if (N->right)
        rightsumm = goThruTree(N->right);
    return std::max(leftsumm + N->value, rightsumm + N->value); 
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

    int res = goThruTree(n1);
    std::cout << res;
    assert(res == 7);
    
    n3->right = n5;
    res = goThruTree(n1);
    std::cout << res;
    assert(res == 9);
}
