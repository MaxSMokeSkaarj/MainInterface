/*Its all function file from module
structure*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <map>

//calculator

int priority(std::char& input) {
  if (input == '+' || input == '-') {
    return 1;
  } else if (input == '*' || input == '/') {
    return 2;
  } else if (input == 'sin' || input == 'cos' || input == 'tan' || input == 'ctg' || input == 'log' || input == 'log10') {
    return 3;
  } else if (input == 'abs' || input == 'pow' || input == 'sqrt' || input == 'cbrt') {
    return 4;
  } else {
    return 0;
  }
}

std::bool is_digital(std::char& input) {
  return input >= 0;
}
std::bool is_variable(std::char& input) {
  return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
}

std::bool is_operation(std::char& input) {
  return (input == '+' || input == '-' || input == '*' || input == '/' || input == 'sin' || input == 'cos' || input == 'tan' || input == 'ctg' || input == 'log' || input == 'log10' || input == 'abs' || input == 'pow' || input == 'sqrt' || input == 'cbrt')
}

queue<char> to_reversepolishnotation(const string& input) {
  stack<char> stk;
  queue<char> gen;
  bool clbr = false;
  char i;
  for(int j = 0; j < in.size(); j++) {
    i = in[j];
    if(i == '.' || i == ',') {
    gen.push(i);
    } else if(is_digit(i)) {
      gen.push(i);
    } else if(is_var(i)) {
      if(gen.empty() != true && is_digit(gen.back()) == true) {
        stk.push('*'); gen.push(';');
      }
      gen.push(i);
    }
    else if(is_oper(i)) {
      if(stk.empty() != true) {
        if(prior(i) == prior(stk.top())) {
          gen.push(stk.top());
          stk.top() = i;
        } else if(prior(i) < prior(stk.top())) {
          while(stk.empty() != true && stk.top() != '(') {
            gen.push(stk.top());
            stk.pop();
          }
          stk.push(i);
        }
      }
      if(stk.empty() == true || prior(i) > prior(stk.top())) {
        if(gen.empty() != true && is_digit(gen.back()) || is_var(gen.back())) {
          gen.push(';');
        } else if(((stk.empty() != true && stk.top() == '(') || gen.empty() == true) && i == '-') {
          gen.push('_');
        }
        if(gen.back() != '_') {
          stk.push(i);
        }
      }
    } else if(i == '(') {
      if(gen.empty() != true && (is_digit(gen.back()) || is_var(gen.back()))) {
        gen.push(';');
        stk.push('*');
      }
      stk.push(i);
    } else if(i == ')') {
      clbr = true;
      while(stk.empty() != true && stk.top() != '(') {
        gen.push(stk.top());
        stk.pop();
      }
      if(stk.empty() != true) {
      stk.pop();
      } else
      throw "WRONG INPUT! Missing (";
    }
  }

  while(stk.empty() != true) {
    gen.push(stk.top());
    stk.pop();
  }
  return gen;
}

//keygen

int four () {
  std::cout << "4-numberic code: " << 1000 + rand() % 1000 << std::endl;
  return 0;
}
int six () {
  std::cout << "6-numberic code: " << 100000 + rand() % 100000 << std::endl;
  return 0;
}
int eight () {
  std::cout << "8-numberic code: " << 10000000 + rand() % 10000000 << std::endl;
  return 0;
}

//converter