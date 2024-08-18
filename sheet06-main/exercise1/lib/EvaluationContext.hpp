#ifndef H_lib_EvaluationContext
#define H_lib_EvaluationContext

#include <vector>

namespace ast {

// EvaluationContext class holds parameter values for expression evaluation
class EvaluationContext {
    public:
    // Constructor with optional initial parameter values
    EvaluationContext(std::vector<double> initialParameterValues = {});

    // Get the parameter value at the specified index
    double getParameterValue(int index) const;

    // Push a new parameter value to the context
    void pushParameter(double value) { parameterValues.push_back(value); }

    private:
    // Vector to store parameter values
    std::vector<double> parameterValues;
};

} // namespace ast

#endif