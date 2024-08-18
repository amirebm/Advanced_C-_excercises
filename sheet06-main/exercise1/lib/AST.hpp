
#ifndef H_lib_AST
#define H_lib_AST

#include <memory>
#include <cmath>

namespace ast {

// Forward declaration of EvaluationContext class
class EvaluationContext;

// Forward declaration of ASTVisitor class
class ASTVisitor;

/// Base class for AST nodes
class ASTNode {
public:
    /// All possible types of ASTNodes
    enum class Type {
        UnaryPlus,
        UnaryMinus,
        Add,
        Subtract,
        Multiply,
        Divide,
        Power,
        Constant,
        Parameter
    };

    virtual ~ASTNode() = default;

    // Pure virtual function to get the type of the ASTNode
    virtual Type getType() const = 0;

    // Evaluate the ASTNode given an EvaluationContext
    virtual double evaluate(const EvaluationContext& context) const = 0;

    // Optimize the ASTNode
    virtual void optimize(std::unique_ptr<ASTNode>& thisRef) = 0;

    // Accept an ASTVisitor for visiting the node
    virtual void accept(ASTVisitor& visitor) const = 0;
};

/////////////////////////////////////////////////////////////////////
// Definition of Constant and Parameter classes

// Constant class represents a constant value in the AST
class Constant : public ASTNode {
public:
    Constant(double value) : value(value) {}

    Type getType() const override { return Type::Constant; }
    double getValue() const { return value; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;

private:
    double value;
};

// Parameter class represents a named parameter in the AST
class Parameter : public ASTNode {
public:
    Parameter(int index) : index(index) {}

    Type getType() const override { return Type::Parameter; }
    int getIndex() const;

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;

private:
    int index;
};

/////////////////////////////////////////////////////////////////////
// Definition of BinaryASTNode and UnaryASTNode classes

// UnaryASTNode class represents unary operations in the AST
class UnaryASTNode : public ASTNode {
public:
    UnaryASTNode(std::unique_ptr<ASTNode> operand) : operand(std::move(operand)) {}

    const ASTNode& getInput() const { return *operand; }
    std::unique_ptr<ASTNode> releaseInput() { return std::move(operand); }

protected:
    std::unique_ptr<ASTNode> operand;
};

// BinaryASTNode class represents binary operations in the AST
class BinaryASTNode : public ASTNode {
public:
    BinaryASTNode(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : left(std::move(left)), right(std::move(right)) {}

    const ASTNode& getLeft() const { return *left; }
    const ASTNode& getRight() const { return *right; }

    std::unique_ptr<ASTNode> releaseLeft() { return std::move(left); }
    std::unique_ptr<ASTNode> releaseRight() { return std::move(right); }

protected:
    std::unique_ptr<ASTNode> left, right;
};

/////////////////////////////////////////////////////////////////////
// Definition of UnaryPlus, UnaryMinus

// UnaryPlus class represents the unary plus operation in the AST
class UnaryPlus : public UnaryASTNode {
public:
    UnaryPlus(std::unique_ptr<ASTNode> operand) : UnaryASTNode(std::move(operand)) {}

    Type getType() const override { return Type::UnaryPlus; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

// UnaryMinus class represents the unary minus operation in the AST
class UnaryMinus : public UnaryASTNode {
public:
    UnaryMinus(std::unique_ptr<ASTNode> operand) : UnaryASTNode(std::move(operand)) {}

    Type getType() const override { return Type::UnaryMinus; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

/////////////////////////////////////////////////////////////////////
// Definition of Add, Subtract, Multiply, Divide, Power classes

// Add class represents the addition operation in the AST
class Add : public BinaryASTNode {
public:
    Add(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : BinaryASTNode(std::move(left), std::move(right)) {}

    Type getType() const override { return Type::Add; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

// Subtract class represents the subtraction operation in the AST
class Subtract : public BinaryASTNode {
public:
    Subtract(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : BinaryASTNode(std::move(left), std::move(right)) {}

    Type getType() const override { return Type::Subtract; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

// Multiply class represents the multiplication operation in the AST
class Multiply : public BinaryASTNode {
public:
    Multiply(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : BinaryASTNode(std::move(left), std::move(right)) {}

    Type getType() const override { return Type::Multiply; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

// Divide class represents the division operation in the AST
class Divide : public BinaryASTNode {
public:
    Divide(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : BinaryASTNode(std::move(left), std::move(right)) {}

    Type getType() const override { return Type::Divide; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

// Power class represents the exponentiation operation in the AST
class Power : public BinaryASTNode {
public:
    Power(std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right)
        : BinaryASTNode(std::move(left), std::move(right)) {}

    Type getType() const override { return Type::Power; }

    double evaluate(const EvaluationContext& context) const override;
    void optimize(std::unique_ptr<ASTNode>& thisRef) override;
    void accept(ASTVisitor& visitor) const override;
};

} // namespace ast

#endif
