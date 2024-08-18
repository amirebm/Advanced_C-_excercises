
#include "lib/PrintVisitor.hpp"
#include <iostream>

namespace ast {

// Visit method for Constant node
void PrintVisitor::visit(const ast::Constant& node) {
    std::cout << node.evaluate(context);
}

// Visit method for Parameter node
void PrintVisitor::visit(const ast::Parameter& node) {
    std::cout << "P" << node.getIndex();
}

// Visit method for UnaryPlus node
void PrintVisitor::visit(const ast::UnaryPlus& node) {
    std::cout << "(+";
    // Recursively visit the operand
    node.getInput().accept(*this);
    std::cout << ")";
}

// Visit method for UnaryMinus node
void PrintVisitor::visit(const ast::UnaryMinus& node) {
    std::cout << "(-";
    // Recursively visit the operand
    node.getInput().accept(*this);
    std::cout << ")";
}

// Visit method for Add node
void PrintVisitor::visit(const ast::Add& node) {
    std::cout << "(";
    // Recursively visit the left and right operands
    const ast::ASTNode* left = &(node.getLeft());
    const ast::ASTNode* right = &(node.getRight());
    left->accept(*this);
    std::cout << " + ";
    right->accept(*this);
    std::cout << ")";
}

// Visit method for Subtract node
void PrintVisitor::visit(const ast::Subtract& node) {
    std::cout << "(";
    // Recursively visit the left and right operands
    const ast::ASTNode* left = &(node.getLeft());
    const ast::ASTNode* right = &(node.getRight());
    left->accept(*this);
    std::cout << " - ";
    right->accept(*this);
    std::cout << ")";
}

// Visit method for Multiply node
void PrintVisitor::visit(const ast::Multiply& node) {
    std::cout << "(";
    // Recursively visit the left and right operands
    const ast::ASTNode* left = &(node.getLeft());
    const ast::ASTNode* right = &(node.getRight());
    left->accept(*this);
    std::cout << " * ";
    right->accept(*this);
    std::cout << ")";
}

// Visit method for Divide node
void PrintVisitor::visit(const ast::Divide& node) {
    std::cout << "(";
    // Recursively visit the left and right operands
    const ast::ASTNode* left = &(node.getLeft());
    const ast::ASTNode* right = &(node.getRight());
    left->accept(*this);
    std::cout << " / ";
    right->accept(*this);
    std::cout << ")";
}

// Visit method for Power node
void PrintVisitor::visit(const ast::Power& node) {
    std::cout << "(";
    // Recursively visit the left and right operands
    const ast::ASTNode* left = &(node.getLeft());
    const ast::ASTNode* right = &(node.getRight());
    left->accept(*this);
    std::cout << " ^ ";
    right->accept(*this);
    std::cout << ")";
}

} // namespace ast
