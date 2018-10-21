#pragma once
/**
 * @brief Declarations and definitions for generic binary operators
 */

#include <functional>

namespace arm {

namespace op {

/**
 * @brief Generic type for binary operation.
 */
template <typename T>
using BinaryOp = std::function<T(const T &, const T &)>;

/**
 * @brief Generic method for addition.
 * @tparam T operand data type.
 * @param lhs First operand.
 * @param rhs Second operand.
 * @return Result of adding lhs and rhs
 */
template <typename T>
T add(const T &lhs, const T &rhs) {
  return lhs + rhs;
}

/**
 * @brief Generic method for subtraction.
 * @tparam T operand data type.
 * @param lhs First operand.
 * @param rhs Second operand.
 * @return Result of subtracting rhs from lhs
 */
template <typename T>
T subtract(const T &lhs, const T &rhs) {
  return lhs - rhs;
}

/**
 * @brief Generic method for multiplication.
 * @tparam T operand data type.
 * @param lhs First operand.
 * @param rhs Second operand.
 * @return Result of multiplying lhs and rhs
 */
template <typename T>
T multiply(const T &lhs, const T &rhs) {
  return lhs * rhs;
}

}

}  // namespace arm
