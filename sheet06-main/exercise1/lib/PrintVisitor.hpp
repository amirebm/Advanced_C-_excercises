#ifndef H_lib_PrintVisitor
#define H_lib_PrintVisitor

#include "lib/AST.hpp"
#include "lib/ASTVisitor.hpp"
#include "lib/EvaluationContext.hpp"
#include "lib/PrintVisitor.hpp"

namespace ast {

// PrintVisitor class is a concrete implementation of ASTVisitor
class PrintVisitor : public ASTVisitor {
    public:
    // Default constructor
    PrintVisitor() {}

    // Constructor with an EvaluationContext parameter
    PrintVisitor(const EvaluationContext& context) : context(context) {}

    // Visit method for Constant node
    void visit(const Constant& node) override;

    // Visit method for Parameter node
    void visit(const Parameter& node) override;

    // Visit methods for UnaryPlus and UnaryMinus nodes
    void visit(const UnaryPlus& node) override;
    void visit(const UnaryMinus& node) override;

    // Visit methods for Add, Subtract, Multiply, Divide, and Power nodes
    void visit(const Add& node) override;
    void visit(const Subtract& node) override;
    void visit(const Multiply& node) override;
    void visit(const Divide& node) override;
    void visit(const Power& node) override;

    private:
    // EvaluationContext used for Constant and Parameter evaluation
    const ast::EvaluationContext context;
};

} // namespace ast

#endif
