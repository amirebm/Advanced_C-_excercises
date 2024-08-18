#ifndef H_lib_ASTVisitor
#define H_lib_ASTVisitor

namespace ast {
// ASTVisitor is an abstract base class for visiting AST nodes

class ASTVisitor {
    public:
    // Virtual destructor to ensure proper destruction of derived classes

    virtual ~ASTVisitor() = default;
    // Visit method for Constant node
    virtual void visit(const Constant& node) = 0;

    // Visit method for Parameter node
    virtual void visit(const Parameter& node) = 0;

    // Visit methods for UnaryPlus and UnaryMinus nodes
    virtual void visit(const UnaryPlus& node) = 0;
    virtual void visit(const UnaryMinus& node) = 0;

    // Visit methods for Add, Subtract, Multiply, Divide, and Power nodes
    virtual void visit(const Add& node) = 0;
    virtual void visit(const Subtract& node) = 0;
    virtual void visit(const Multiply& node) = 0;
    virtual void visit(const Divide& node) = 0;
    virtual void visit(const Power& node) = 0;
};

} // namespace ast
#endif