#include "model.h"
#include <iostream>
#include <vector>
#include <stack>

#include <cctype>

static bool IsDigit(const char ch) {
  return std::isdigit(static_cast<unsigned char>(ch));
}

static bool IsAlpha(const char ch) {
  return std::isalpha(static_cast<unsigned char>(ch));
}

static bool IsFunction(const char ch) {
  return std::string("sctSCTqlg").find_first_of(ch);
}

static bool IsOperator(const char ch) {
  std::string s {"|~m+-/*^"};
  return s.find(ch) == std::string::npos ? false : true;
}

int SetPriority(const char c) {
  int p = 0;
  if (c == '*' || c == '/')
    p = 1;
  else if (c == '^' || c == 'm')
    p = 2;
  else if (c == '~' || c == '|')
    p = 3;
  return p;
}

static std::size_t FillDigit(std::string::const_iterator it, std::string& out) {
  std::size_t sz = 0;
  while (IsDigit(*it)) {
    out.push_back(*it);
    ++sz;
    ++it;
  }
  if (*it == '.') {
    out.push_back(*it++);
    ++sz;
    if (!IsDigit(*it)) throw std::logic_error("Invalid expression");
    while (IsDigit(*it)) {
      out.push_back(*it);
      ++sz;
      ++it;
    }
  }
  return sz;
}

static std::string MakePolish(const std::string& src) {
  std::string out;

  std::stack<char> sstack;

  for (std::string::const_iterator i = src.cbegin(); i != src.cend(); ++i) {
    if (*i == 'x') {
      out.push_back(*i);
    } else if (IsDigit(*i)) {
      i += FillDigit(i, out);
    } else if (IsFunction(*i) || *i == '(') {
      sstack.push(*i);
    } else if (*i == ')') {
      while (sstack.top() != '(') {
        out.push_back(sstack.top());
        sstack.pop();
      }
      sstack.pop();
    } else if (IsOperator(*i)) {
      int priority = SetPriority(*i);
      // continue here
    }
  }

  std::cout << "out:" << out << std::endl;
  return out;
}

static std::string ReplaceFunctionsWithSymbols(const std::string& src) {
  std::string result;
  std::vector<std::string> functions {"mod", "sin", "cos", "tan", "asin",
                                      "acos", "atan", "sqrt", "ln", "log"};
  std::string symb {"msctSCTqlg"};
  
  for (unsigned int i = 0; i < src.size(); ++i) {
    if (IsAlpha(src[i]))
      for (std::size_t k = 0; k < 10; ++k)
        if (src.compare(i, functions[k].size(), functions[k]) == 0) {
          result += symb[k];
          i += functions[k].size();
        }
    result += src[i];
  }
  return result;
}

Model::Model(const std::string& src) : expression{src} {
  if (255 < src.size())
    throw std::length_error("Expression length is too big. 255 is limit");
  expression = ReplaceFunctionsWithSymbols(expression);
}

double Model::CalculateExpression() const {
  std::cout << "Expression:" << expression << std::endl;
  std::string polish_string = MakePolish(expression);
  return 0.0;
}
