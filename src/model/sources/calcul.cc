#include <vector>
#include <stack>
#include <cctype>
#include <cmath>
#include <stdexcept>

#include <iostream>

#include "../includes/calcul.h"

namespace {

bool IsDigit(char ch) {
  return std::isdigit(static_cast<unsigned char>(ch));
}

bool IsAlpha(char ch) {
  return std::isalpha(static_cast<unsigned char>(ch));
}

bool IsFunction(char ch) {
  return std::string("sctSCTqlg").find(ch) == std::string::npos ? false : true;
}

bool IsOperator(char ch) {
  return std::string("|~m+-/*^").find(ch) == std::string::npos ? false : true;
}

int SetPriority(char c) {
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

void AppendNumber(std::string::const_iterator& it, std::string& out) {
  while (IsDigit(*it)) out.push_back(*it++);

  if (*it == '.') {
    AppendToOutput(*it++, out);
    /* if (!IsDigit(*it)) throw std::logic_error("Invalid expression"); */

    while (IsDigit(*it)) AppendToOutput(*it++, out);
  }
  --it;
  AppendSpaceToOutput(out);
}

void ProcessClosingBracket(std::string& out, std::stack<char>& sstack) {
  if (sstack.empty()) throw std::logic_error("Invalid expression");

  while (sstack.top() != '(') {
    AppendToOutput(sstack.top(), out);
    AppendSpaceToOutput(out);
    sstack.pop();
    if (sstack.empty()) {
      throw std::logic_error("Invalid expression");
    }
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
      throw std::logic_error("Invalid expression");
    }
  }
}

std::string MakePolish(const std::string& src) {
  std::string out;
  std::stack<char> sstack;

  for (std::string::const_iterator i = src.cbegin(); i != src.cend(); ++i) {
    if (*i == ' ') continue;

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
    } else {
      throw std::logic_error("Incorrect expression");
    }
  }

  ProcessRemainingOperators(out, sstack);

  return out;
}

void FindUnary(std::string& src) {
  for (std::size_t i = 0; i < src.size(); ++i)
    if (src[i] == '+' || src[i] == '-')
      if (i == 0 || src[i - 1] == '(' || IsOperator(src[i - 1]) || src[i - 1] == 'm') {
        if (src[i] == '-') src[i] = '~';
        else src[i] = '|';
      }
}

bool Invalid(std::string::const_iterator it) {
  return !IsDigit(*(it - 1)) || !IsDigit(*(it + 1));
}

void IsInvalidDot(const char *point) {
  if (Invalid(std::string::const_iterator(point))) {
    throw std::logic_error("Invalid expression");
  }
}

void AddBracketsAroundExp(std::string& str) {
  // checking for incorrect exp
  for (auto it = str.begin(); it != str.end(); ++it) {

    // it --> e
    if (*it == 'e' && it != str.begin() && it != str.end() - 1) {
      std::cout << "HERE1\n";
      if (IsDigit(*(it - 1)) && (IsDigit(*(it + 1)) || *(it + 1) == '+' || *(it + 1) == '-')) {
        std::cout << "HERE2\n";
        int i = 2;
        --it;
        while ((IsDigit(*it) || *it == '.') && it != str.begin() - 1) {
          std::cout << *it << ' ';
          ++i;
          --it;
        }
        std::cout << "HERE3\n";
        str.insert(it + 1, '(');
        std::cout << "HERE4\n";
        it += i + 1;
        std::cout << "i = " << i << std::endl;
        std::cout << "\n*it = " << *it << std::endl;
        int count = 0;
        while (it != str.end() && (IsDigit(*it) || *it == '.' || *it == '+' || *it == '-')) {
          if (*it == '+' || *it == '-') ++count;
          if (count > 1) break;
          ++it;
        }
        str.insert(it, ')');
      }
    }

  }
}

void FindExpo(std::string& result) {
  std::cout << result << std::endl;

  AddBracketsAroundExp(result);

  for (std::size_t i = 0; i < result.size(); ++i) {
    if (result[i] == 'e') {
      if (i > 0 && i < result.size() - 1 && IsDigit(result[i - 1]) &&
          (result[i + 1] == '+' || result[i + 1] == '-' || IsDigit(result[i + 1])) ) {
        result.replace(i, 1, std::string("*10^"));
      }
    }
  }

  std::cout << result << std::endl;
}

std::string ReplaceFunctionsWithSymbols(const std::string& src) {
  std::string result;
  std::vector<std::string> functions {"mod", "sin", "cos", "tan", "asin",
                                      "acos", "atan", "sqrt", "ln", "log"};
  std::string symb {"msctSCTqlg"};
  
  for (std::size_t i = 0; i < src.size(); ++i) {
    if (src[i] == '.') IsInvalidDot(&src[i]);

    if (IsAlpha(src[i]))
      for (std::size_t k = 0; k < 10; ++k)
        if (src.compare(i, functions[k].size(), functions[k]) == 0) {
          result += symb[k];
          i += functions[k].size();
        }
    result += src[i];
  }

  FindExpo(result);
  FindUnary(result);

  return result;
}


double StringToDouble(std::string::const_iterator& it,
                             std::string::const_iterator cend) {
  double doubleNum {0.0}, integerPart {0.0}, fractionalPart {0.0};
  std::string::const_iterator buf {it}, end, unknown;
  int j = 0;
  while (buf != cend && IsDigit(*buf)) ++buf;
  unknown = buf--;
  while (buf >= it) integerPart += (double)(*buf-- - '0') * pow(10.0, j++);
  end = unknown;
  if (*unknown == '.') {
    int k = 0;
    buf = ++unknown;
    while (unknown != cend && IsDigit(*unknown)) ++unknown;
    end = unknown--;
    while (unknown >= buf)
      fractionalPart += (double)(*unknown-- - '0') * pow(10.0, k++);
    fractionalPart /= pow(10.0, k);
  }
  doubleNum = integerPart + fractionalPart;
  it += end - it;
  return doubleNum;
}

void OperatorAction(std::stack<double>& nstack, char s) {
  if (nstack.empty()) {
    throw std::logic_error("Invalid expression");
  }

  if (s == '|') return;
  else if (s == '~') {
    nstack.top() = -nstack.top();
  } else {
    double right = nstack.top();
    nstack.pop();

    if (nstack.empty()) {
      throw std::logic_error("Invalid expression");
    }

    double left = nstack.top();
    nstack.pop();

    double res;

    switch (s) {
      case 'm': res = fmod(left, right); break;
      case '+': res = left + right; break;
      case '-': res = left - right; break;
      case '/': res = left / right; break;
      case '*': res = left * right; break;
      case '^': res = pow(left, right); break;
    }

    nstack.push(res);
  }
}

void FunctionAction(std::stack<double>& nstack, char s) {
  if (nstack.empty()) {
    throw std::logic_error("Invalid expression");
  }

  double n = nstack.top(), res;
  nstack.pop();

  switch (s) {
    case 's': res = sin(n); break;
    case 'c': res = cos(n); break;
    case 't': res = tan(n); break;
    case 'S': res = asin(n); break;
    case 'C': res = acos(n); break;
    case 'T': res = atan(n); break;
    case 'q': res = sqrt(n); break;
    case 'l': res = log(n); break;
    case 'g': res = log10(n); break;
  }

  nstack.push(res);
}
}  // namespace

s21::Model::Model(const std::string& src) : expression{src} {
  expression = MakePolish(ReplaceFunctionsWithSymbols(expression));
}

double s21::Model::CalculateExpression(const double x) const {

  std::stack<double> nstack;

  for (std::string::const_iterator it = expression.cbegin(); it != expression.cend(); ++it) {
    if (IsDigit(*it)) {
      nstack.push(StringToDouble(it, expression.cend()));
    } else if (*it == 'x') {
      nstack.push(x);
    } else if (IsOperator(*it)) {
      OperatorAction(nstack, *it);
    } else if (IsFunction(*it)) {
      FunctionAction(nstack, *it);
    }
  }

  double result {nstack.top()};
  nstack.pop();

  if (!nstack.empty()) throw std::logic_error("Invalid expression");

  return result;
}
