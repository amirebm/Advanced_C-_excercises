
#include "lib/EvaluationContext.hpp"

namespace ast {

// Constructor for EvaluationContext
EvaluationContext::EvaluationContext(std::vector<double> initialParameterValues)
    : parameterValues(std::move(initialParameterValues)) {}

// Get the parameter value at the specified index
double EvaluationContext::getParameterValue(int index) const {
    if (index >= 0 && static_cast<std::vector<double>::size_type>(index) < parameterValues.size()) {
        return parameterValues[index];
    } else {
        return 0.0; // Default value if the index is out of bounds
        // Alternatively, handle the case where the index is out of bounds.
    }
}

} // namespace ast
