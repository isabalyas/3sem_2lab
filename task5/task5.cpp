#include <iostream>
#include <limits>
#include <memory>

#include "task5.hpp"

namespace {

struct Node {
    int key = 0;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    explicit Node(int k) : key(k) {}
};

std::unique_ptr<Node> insert(std::unique_ptr<Node> root, int key) {
    if (!root) return std::make_unique<Node>(key);
    if (key < root->key) {
        root->left = insert(std::move(root->left), key);
    } else if (key > root->key) {
        root->right = insert(std::move(root->right), key);
    }
    return root;
}

void inOrderTraversal(const std::unique_ptr<Node>& node) {
    if (!node) return;
    inOrderTraversal(node->left);
    std::cout << node->key << " ";
    inOrderTraversal(node->right);
}

}  // namespace

void runTask5() {
    std::cout << "Введите последовательность целых чисел, завершая 0:\n";
    std::unique_ptr<Node> root;
    int value = 0;
    while (std::cin >> value && value != 0) {
        root = insert(std::move(root), value);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Центрированный обход: ";
    inOrderTraversal(root);
    std::cout << "\n";
}