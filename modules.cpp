/*Its all function file from module
structure*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int prior(char& in) {
  if(in == '+' || in == '-')
  return 1;
  else if(in == '*' || in == '/')
  return 2;
  else if(in == '^')
  return 3;
  else
  return 0;
}

bool is_digit(char& in) {
  return (in >= '0' && in <= '9');
}

bool is_var(char& in) {
  return ((in >= 'a' && in <= 'z') ||
    (in >= 'A' && in <= 'Z'));
}

bool is_oper(char& in) {
  return (in == '+' || in == '-' ||
    in == '*' || in == '/' ||
    in == '^');
}

queue<char> to_revpol(const string& in) {
  stack<char> stk;
  queue<char> gen;
  bool clbr = false;

  char i;
  for(int j = 0; j < in.size(); j++) {
    i = in[j];
    if(i == '.' || i == ',') {
    gen.push(i);
    } else if(is_digit(i)) {
      if((gen.empty() != true && is_var(gen.back()) == true) || clbr == true) {
        stk.push('^'); gen.push(';'); clbr = false;
      }
      gen.push(i);
    }
    else if(is_var(i)) {
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
        }
        else if(prior(i) < prior(stk.top())) {
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
          if(gen.back() != '_') {
            stk.push(i);
          }
        }
      }
    }
    else if(i == '(') {
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
      } else {
        throw "WRONG INPUT! Missing (";
      }
    }
  }
  while(stk.empty() != true) {
    gen.push(stk.top());
    stk.pop();
  }
  return gen;
}

double calc(queue<char> in) {
  stack<double> res;
  map<string, double> mem;
  string var_buf;
  bool minus = false,
  op = false;
  size_t fl = 0;
  double temp;
  res.push(0.0);
  while(in.empty() != true) {
    if(in.front() == '_') {
      minus = true;
      in.pop();
    } else if(is_digit(in.front()) == true) {
      if(op == true) {
        res.push(0.0); op = false;
      }
      while(in.empty() != true && is_digit(in.front()) == true) {
        if((in.front() == '0' && res.top() == 0.0) == false) {
            if(fl == 0)
            {
              res.top() = res.top() * 10 + in.front() - 48;
            }
            else
            {
              temp = in.front() - 48;
              for(size_t i = 0; i < fl; i++)
              temp /= 10;
              res.top() += temp;
              fl++;
            }
          }
        }
        in.pop();
        if(in.empty() != true && in.front() == '.') {
          fl = 1;
          in.pop();
        }
      fl = 0;
    } else if(is_var(in.front()) == true) {
      if(op == true) {
        res.push(0.0); op = false;
      }
      var_buf.clear();
      do {
        var_buf.push_back(in.front());
        in.pop();
      } while(in.empty() != true && is_var(in.front()) == true);

      if(mem.find(var_buf) != mem.end()) {
        res.top() = mem[var_buf];
      } else {
        cout << "Please enter the variable \'" << var_buf << "\': ";
        cin >> res.top();
        mem[var_buf] = res.top();
      }
    } else if(in.front() == ';' ||
      is_oper(in.front()) == true)
    {
      if(minus == true){
        minus = false;
        res.top() = -res.top();
      }
      if(in.front() == ';')
      {
        res.push(0.0);
        in.pop();
      } else if(res.size() > 1) {
        temp = res.top();
        res.pop();
        switch(in.front()) {
          case '+':
            res.top() += temp;
            break;
          case '-':
            res.top() -= temp;
            break;
          case '*':
            res.top() *= temp;
            break;
          case '/':
            res.top() /= temp;
            break;
          case '^':
            res.top() = pow(res.top(), temp);
            break;
        }
        op = true;
        in.pop();
      }
    }
  }
  if(res.size() > 1) {
    cout << "something went wrong!";
    while(res.empty() != true) {
      cout << res.top() << ' ';
      res.pop();
    }
    return 0.0;
  }
  return res.top();
}

template < class T >
ostream& operator<<(ostream& out, queue < T > cs) {
  while(cs.empty() != true) {
    out << cs.front();
    cs.pop();
  }
  return out;
}

int four () {
  cout << "4-numberic code: " << 1000 + rand() % 1000 << std::endl;
  return 0;
}

int six () {
  cout << "6-numberic code: " << 100000 + rand() % 100000 << std::endl;
  return 0;
}

int eight () {
  cout << "8-numberic code: " << 10000000 + rand() % 10000000 << std::endl;
  return 0;
}