#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

#include "model.h"

static bool IsDigit(char ch) {
  return std::isdigit(static_cast<unsigned char>(ch));
}

static bool IsAlpha(char ch) {
  return std::isalpha(static_cast<unsigned char>(ch));
}

static bool IsFunction(char ch) {
  return std::string("sctSCTqlg").find(ch) == std::string::npos ? false : true;
}

static bool IsOperator(char ch) {
  return std::string("|~m+-/*^").find(ch) == std::string::npos ? false : true;
}

static int SetPriority(char c) {
  int p = 0;

  if (c == '*' || c == '/') p = 1;
  else if (c == '^' || c == 'm') p = 2;
  else if (c == '~' || c == '|') p = 3;

  return p;
}

void AppendToOutput(char c, std::string& out) {
  out.push_back(c);
}

void AppendSpaceToOutput(std::string& out) {
  out.push_back(' ');
}

static void AppendNumber(std::string::const_iterator& it, std::string& out) {
  while (IsDigit(*it)) out.push_back(*it++);

  if (*it == '.') {
    AppendToOutput(*it++, out);
    if (!IsDigit(*it)) throw std::logic_error("Invalid expression");

    while (IsDigit(*it)) AppendToOutput(*it++, out);
  }
  --it;
  AppendSpaceToOutput(out);
}

void ProcessClosingBracket(std::string& out, std::stack<char>& sstack) {
  while (sstack.top() != '(') {
    AppendToOutput(sstack.top(), out);
    AppendSpaceToOutput(out);
    sstack.pop();
    if (sstack.empty()) throw std::logic_error("Incorrect input");
  }
  sstack.pop();
}

void ProcessOperator(char c, std::string& out, std::stack<char>& sstack) {
  int priority = SetPriority(c);
  if (!sstack.empty()) {
    char b = sstack.top();
    while (!sstack.empty() && (IsFunction(b) ||
          (IsOperator(b) && SetPriority(b) >= priority && priority != 3))) {
      if (priority == 2 && c == b) break;
      AppendToOutput(b, out);
      AppendSpaceToOutput(out);
      sstack.pop();
      if (!sstack.empty()) b = sstack.top();
    }
  }
  sstack.push(c);
}

void ProcessRemainingOperators(std::string& out, std::stack<char>& sstack) {
  while (!sstack.empty()) {
    char b = sstack.top();
    if (IsOperator(b) || IsFunction(b)) {
      AppendToOutput(b, out);
      sstack.pop();
      if (!sstack.empty()) AppendSpaceToOutput(out);
    } else {
      throw std::logic_error("Incorrect expression");
    }
  }
}

static std::string MakePolish(const std::string& src) {
  std::string out;
  std::stack<char> sstack;

  for (std::string::const_iterator i = src.cbegin(); i != src.cend(); ++i) {
    if (*i == 'x') {
      AppendToOutput(*i, out);
    } else if (IsDigit(*i)) {
      AppendNumber(i, out);
    } else if (IsFunction(*i) || *i == '(') {
      sstack.push(*i);
    } else if (*i == ')') {
      ProcessClosingBracket(out, sstack);
    } else if (IsOperator(*i)) {
      ProcessOperator(*i, out, sstack);
    }
  }

  ProcessRemainingOperators(out, sstack);

  return out;
}

static void FindUnary(std::string& src) {
  for (std::size_t i = 0; i < src.size(); ++i)
    if (src[i] == '+' || src[i] == '-')
      if (i == 0 || src[i - 1] == '(' || IsOperator(src[i - 1]) || src[i - 1] == 'm') {
        if (src[i] == '-') src[i] = '~';
        else src[i] = '|';
      }
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

  FindUnary(result);

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
  std::cout << "Polistring:" << polish_string << std::endl;
  return 0.0;
}
