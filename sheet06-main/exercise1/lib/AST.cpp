#include "lib/AST.hpp"
#include "lib/ASTVisitor.hpp"
#include "lib/EvaluationContext.hpp"
#include "lib/PrintVisitor.hpp"
#include <cmath>


namespace ast {

// Constant implementation
double Constant::evaluate(const EvaluationContext& /*context*/) const {
    return value;
}

void Constant::optimize(std::unique_ptr<ASTNode>& /*thisRef*/) {
    // Constants are already in their optimized form
}

void Constant::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

// Parameter implementation
double Parameter::evaluate(const EvaluationContext& context) const {
    return context.getParameterValue(index);
}

void Parameter::optimize(std::unique_ptr<ASTNode>& /*thisRef*/) {
    // Parameters are already in their optimized form
}

void Parameter::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

int Parameter::getIndex() const {
    return index;
}

// UnaryPlus implementation
double UnaryPlus::evaluate(const EvaluationContext& context) const {
    return operand->evaluate(context);
}

void UnaryPlus::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void UnaryPlus::optimize(std::unique_ptr<ASTNode>& thisRef) {
    operand->optimize(operand);

    // +E should be optimized to E
    if (Parameter* operandParameter = dynamic_cast<Parameter*>(operand.get())) {
        operandParameter = operandParameter;
        thisRef = std::move(operand);
        return;
    }

    // +E should be optimized to E
    if (UnaryPlus* operandUnaryPlus = dynamic_cast<UnaryPlus*>(operand.get())) {
        thisRef = std::move(operandUnaryPlus->operand);
        return;
    }
}

// UnaryMinus implementation
double UnaryMinus::evaluate(const EvaluationContext& context) const {
    return -operand->evaluate(context);
}

void UnaryMinus::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void UnaryMinus::optimize(std::unique_ptr<ASTNode>& thisRef) {
    operand->optimize(operand);

    // -(-E) should be optimized to E
    if (UnaryMinus* operandUnaryMinus = dynamic_cast<UnaryMinus*>(operand.get())) {
        thisRef = std::move(operandUnaryMinus->operand);
        return;
    }

    // Handle the case when the operand is a constant
    if (Constant* operandConstant = dynamic_cast<Constant*>(operand.get())) {
        thisRef = std::make_unique<Constant>(-operandConstant->getValue());
        return;
    }

    if (Subtract* operandSubtract = dynamic_cast<Subtract*>(operand.get())) {
        // -((-a) - b) -> b + a
        if (operandSubtract->getLeft().getType() == Type::UnaryMinus) {
            // Handle the case when the left operand of Subtract is UnaryMinus
            auto b = operandSubtract->releaseRight();
            auto a = dynamic_cast<UnaryMinus*>(operandSubtract->releaseLeft().get())->releaseInput();
            thisRef = std::make_unique<Add>(std::move(b), std::move(a));
            return;
        }

        // -(E1 - E2) should be optimized to E2 - E1
        thisRef = std::make_unique<Subtract>(std::move(operandSubtract->releaseRight()), std::move(operandSubtract->releaseLeft()));
        return;
    }
}

/////////////////////////////////////////////////////////////////////

// Add implementation
double Add::evaluate(const EvaluationContext& context) const {
    return left->evaluate(context) + right->evaluate(context);
}

void Add::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void Add::optimize(std::unique_ptr<ASTNode>& thisRef) {
    left->optimize(left);
    right->optimize(right);

    // 0 + E should be optimized to E
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (leftConstant->getValue() == 0) {
            thisRef = std::move(right);
            return;
        }
    }

    // E + 0 should be optimized to E
    if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
        if (rightConstant->getValue() == 0) {
            thisRef = std::move(left);
            return;
        }
    }

    // (-E1) + E2 should be optimized to E2 - E1
    if (UnaryMinus* leftUnaryMinus = dynamic_cast<UnaryMinus*>(left.get())) {
        thisRef = std::make_unique<Subtract>(std::move(right), std::move(leftUnaryMinus->releaseInput()));
        return;
    }

    // E1 + (-E2) should be optimized to E1 - E2
    if (UnaryMinus* rightUnaryMinus = dynamic_cast<UnaryMinus*>(right.get())) {
        thisRef = std::make_unique<Subtract>(std::move(left), std::move(rightUnaryMinus->releaseInput()));
        return;
    }

    // Handle the case where both operands are constants
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
            thisRef = std::make_unique<Constant>(leftConstant->getValue() + rightConstant->getValue());
            return;
        }
    }
}

// Subtract implementation
double Subtract::evaluate(const EvaluationContext& context) const {
    return left->evaluate(context) - right->evaluate(context);
}

void Subtract::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void Subtract::optimize(std::unique_ptr<ASTNode>& thisRef) {
    left->optimize(left);
    right->optimize(right);

    // E - 0 should be optimized to E
    if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
        if (rightConstant->getValue() == 0) {
            thisRef = std::move(left);
            return;
        }
    }

    // 0 - E should be optimized to -E
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (leftConstant->getValue() == 0) {
            thisRef = std::make_unique<UnaryMinus>(std::move(right));
            return;
        }
    }

    // Handle the case where both operands are constants
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
            // E1 - E2 should be optimized to a Constant with value (E1 - E2)
            thisRef = std::make_unique<Constant>(leftConstant->getValue() - rightConstant->getValue());
            return;
        }
    }

    // a - (-b) should be optimized to a + b
    if (UnaryMinus* rightUnaryMinus = dynamic_cast<UnaryMinus*>(right.get())) {
        thisRef = std::make_unique<Add>(std::move(left), std::move(rightUnaryMinus->releaseInput()));
        return;
    }
}

// Multiply implementation
double Multiply::evaluate(const EvaluationContext& context) const {
    return left->evaluate(context) * right->evaluate(context);
}

void Multiply::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void Multiply::optimize(std::unique_ptr<ASTNode>& thisRef) {
    left->optimize(left);
    right->optimize(right);

    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        // 0 * E should be optimized to 0
        if (leftConstant->getValue() == 0) {
            thisRef = std::make_unique<Constant>(0);
            return;
        }
        // 1 * E should be optimized to E
        if (leftConstant->getValue() == 1) {
            thisRef = std::move(right);
            return;
        }
    }

    if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
        // E * 0 should be optimized to 0
        if (rightConstant->getValue() == 0) {
            thisRef = std::make_unique<Constant>(0);
            return;
        }
        // E * 1 should be optimized to E
        if (rightConstant->getValue() == 1) {
            thisRef = std::move(left);
            return;
        }
    }

    // (-E1) * (-E2) should be optimized to E1 * E2
    if (UnaryMinus* leftUnaryMinus = dynamic_cast<UnaryMinus*>(left.get())) {
        if (UnaryMinus* rightUnaryMinus = dynamic_cast<UnaryMinus*>(right.get())) {
            thisRef = std::make_unique<Multiply>(std::move(leftUnaryMinus->releaseInput()), std::move(rightUnaryMinus->releaseInput()));
            return;
        }
    }

    // Handle the case where both operands are constants
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
            thisRef = std::make_unique<Constant>(leftConstant->getValue() * rightConstant->getValue());
            return;
        }
    }
}

// Divide implementation
double Divide::evaluate(const EvaluationContext& context) const {
    return left->evaluate(context) / right->evaluate(context);
}

void Divide::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void Divide::optimize(std::unique_ptr<ASTNode>& thisRef) {
    left->optimize(left);
    right->optimize(right);

    // Handle the case where both operands are constants
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
            // if (rightConstant->getValue() != 0)
            {
                thisRef = std::make_unique<Constant>(leftConstant->getValue() / rightConstant->getValue());
                return;
            }
        }
    }

    // E / 1 should be optimized to E
    if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
        if (rightConstant->getValue() == 1) {
            thisRef = std::move(left);
            return;
        }
    }

    // 0 / E should be optimized to 0
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (leftConstant->getValue() == 0) {
            thisRef = std::make_unique<Constant>(0);
            return;
        }
    }

    // E / CONST should be optimized to E * (1 / CONST)
    if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
        thisRef = std::make_unique<Multiply>(std::move(left), std::make_unique<Constant>(1.0 / rightConstant->getValue()));
        return;
    }

    // (-E1) / (-E2) should be optimized to E1 / E2
    if (UnaryMinus* leftUnaryMinus = dynamic_cast<UnaryMinus*>(left.get())) {
        if (UnaryMinus* rightUnaryMinus = dynamic_cast<UnaryMinus*>(right.get())) {
            thisRef = std::make_unique<Divide>(std::move(leftUnaryMinus->releaseInput()), std::move(rightUnaryMinus->releaseInput()));
            return;
        }
    }
}

// Power implementation
double Power::evaluate(const EvaluationContext& context) const {
    return std::pow(left->evaluate(context), right->evaluate(context));
}

void Power::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

void Power::optimize(std::unique_ptr<ASTNode>& thisRef) {
    left->optimize(left);
    right->optimize(right);

    // Handle the case where both operands are constants
    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
            // E1 - E2 should be optimized to a Constant with value (E1 - E2)
            thisRef = std::make_unique<Constant>(std::pow(leftConstant->getValue(), rightConstant->getValue()));
            return;
        }
    }

    if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
        // E ^ 0 should be optimized to 1
        if (rightConstant->getValue() == 0) {
            thisRef = std::make_unique<Constant>(1);
            return;
        }
        // E ^ 1 should be optimized to E
        if (rightConstant->getValue() == 1) {
            thisRef = std::move(left);
            return;
        }
    }

    if (Constant* leftConstant = dynamic_cast<Constant*>(left.get())) {
        // 0 ^ E should be optimized to 0
        if (leftConstant->getValue() == 0) {
            thisRef = std::make_unique<Constant>(0);
            return;
        }
        // 1 ^ E should be optimized to 1
        if (leftConstant->getValue() == 1) {
            thisRef = std::make_unique<Constant>(1);
            return;
        }
    }

    // E ^ -1 should be optimized to 1 / E
    if (Parameter* leftParameter = dynamic_cast<Parameter*>(left.get())) {
        leftParameter = leftParameter;
        if (Constant* rightConstant = dynamic_cast<Constant*>(right.get())) {
            if (rightConstant->getValue() == -1) {
                thisRef = std::make_unique<Divide>(std::make_unique<Constant>(1), std::move(left));
                return;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////

} // namespace ast
