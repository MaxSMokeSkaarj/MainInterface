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

//calculator

int priority(char& input) {
  if (input == '+' || input == '-') {
    return 1;
  } else if (input == '*' || input == '/') {
    return 2;
  } else if (input == 'sin' || input == 'cos' || input == 'tan' || input == 'ctg' || input == 'log' || input == 'log10') {
    return 3;
  } else if (input == 'abs' || input == '^' || input == 'sqrt' || input == 'cbrt') {
    return 4;
  } else {
    return 0;
  }
}

bool is_digital(char& input) {
  return input >= 0;
}
bool is_variable(char& input) {
  return ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'));
}

bool is_operation(char& input) {
  return (input == '+' || input == '-' || input == '*' || input == '/' || input == 'sin' || input == 'cos' || input == 'tan' || input == 'ctg' || input == 'log' || input == 'log10' || input == 'abs' || input == '^' || input == 'sqrt' || input == 'cbrt');
}

queue<char> to_revpol(const string& in) {
  stack<char> stk; //создаем стак для хранения временных операция
  queue<char> gen; //создаем очередь, куда все будем пихать
  bool clbr = false;
  //for(auto i : in)//идем по строке
  char i;
  for(int j = 0; j < in.size(); j++) {
    i = in[j];
    if(i == '.' || i == ',')//если это просто точка, т.е. пользователь ввел число по типу 0.2,
    gen.push(i); //то тупо пихаем её внутрь
    else if(is_digit(i))//если сейчас число
    {
      if((gen.empty() != true && //если с gen что-то есть
        is_var(gen.back()) == true) || clbr == true)//и это переменная или поднят флаг закрытой скобки, то...
      {
        stk.push('^'); gen.push(';'); clbr = false;
      }//это нужно, чтобы не писать знак степени после переменных и скобко, например, x2 == x^2 или (1+2)2 == (1+2)^2
      gen.push(i);
    }
    else if(is_var(i))//если сейчас переменная
    {
      if(gen.empty() != true && //если с gen что-то есть
        is_digit(gen.back()) == true)//а сейчас у нас идет переменная, то...
      {
        stk.push('*'); gen.push(';');
      }//эта хрень нужна чтобы не ставить знак умножения перед переменной при вводе 5x == 5*x, например
      gen.push(i);
    }
    else if(is_oper(i))//если же это операция
    {
      //можно так же проверять по приоритетности, однако это ухудшит читаемость кода
      if(stk.empty() != true)//если в стэке что-то есть, то нужно посмотреть
      {
        if(prior(i) == prior(stk.top()))//если предыдущая и текущая операция имеют одинаковый приоритет,
        {
          gen.push(stk.top()); //то можно выгрузить предыдущую операцию
          stk.top() = i; //и заменить её
        }
        else if(prior(i) < prior(stk.top()))//иначе, если приоритет текущей операции меньше,то
        {
          while(stk.empty() != true && stk.top() != '(')//следует выгрузить все до открывающейся скобки, либо пока стек не опустеет
          {
            //зачем? А переведите на ОПН такое: a * b + c. Тут роль скобочки играет главное тело.
            gen.push(stk.top());
            stk.pop();
          }
          stk.push(i);
        }
      }
      if(stk.empty() == true || prior(i) > prior(stk.top()))//если же стек пуст или проиритет последний операции меньше текущей, то...
      {
        if(gen.empty() != true &&
          is_digit(gen.back()) || is_var(gen.back()))//если последнее, что было в gen - переменная или цифра,
        gen.push(';'); //то следует поставить ограничивающий знак
        else if(((stk.empty() != true && stk.top() == '(') || gen.empty() == true) && i == '-')//иначе,
        gen.push('_'); //если стек не пуст и последнее, что в него запили была открывающая скобка, либо у нас вообще пока ничего нет, а i == -, то я вставляю знак _
        //зачем? Ну, для того чтобы все не ломалось при таком вводе: -5 + 3 или 4 * (-2 + 1)
        if(gen.back() != '_')//если последнее в gen не _, которые мы могли только что записать => это какая-то операция
        stk.push(i);
      }
    }
    else if(i == '(')//если же у нас не цифра, не переменная и не операция, а откр. скобка, то...
    {
      if(gen.empty() != true &&
        (is_digit(gen.back()) || is_var(gen.back())))//если последнее что было в gen - переменная или цифра,
      {
        gen.push(';'); //ставим ограничивающий знак, а в стек записываем *
        stk.push('*'); //Опять же, зачем? А затем, чтобы не ставить его самим при записи типа: 23(13 + 1), например
      }
      stk.push(i); //запихиваем ( в стэк
    }
    else if(i == ')')//если же у нас закрылась скобка, следует выгрущить все операции из stk в gen
    {
      clbr = true;
      while(stk.empty() != true && stk.top() != '(')//пока стек не пустой (если он опустел значит пользователь ввел неправильное выражение) и до, конечно, открывающийся скобки
      {
        gen.push(stk.top());
        stk.pop();
      }
      if(stk.empty() != true)
      stk.pop();
      else
      throw "WRONG INPUT! Missing ("; //кидаем исключение, если пользователь был не очень внимателен
    }
  }

  while(stk.empty() != true)//по окончанию работы со строкой в стеке может что-то остаться, потому
  {
    //выносим все что осталось.
    gen.push(stk.top());
    stk.pop();
  }
  return gen; //и возвращаем результат
}

double calc(queue<char> in) {
  stack<double> res; //временное хранилище значений
  map<string,double> mem; //чтобы дважды не запрашивать одну и ту же переменную
  string var_buf; //буфер строки при для переменных
  bool minus = false,
  op = false; //флаги на минус, либо на оперцию
  size_t fl = 0; //переменная для правильного ввода значений с плавающей точкой
  double temp; //и просто временная переменная

  res.push(0.0); //добавляем одно значение
  while(in.empty() != true)//пока очередь не опустеет
  {
    if(in.front() == '_')//если встретился знак _, значит был ввод типа: -3 + 2 или 5 * (-4 + 3) и т.д.
    {
      minus = true; //поднимаем флаг минуса
      in.pop(); //убираем эл.
    }
    else if(is_digit(in.front()) == true)//если получили цифру
    {
      if(op == true) {
        res.push(0.0); op = false;
      }//если была какая-то операция и сейчас нам нужно записать новое значение, то добавляем память и опускаем флаг
      while(in.empty() != true && is_digit(in.front()) == true)//пока в очереди что-то есть и пока это цифры
      {
        if((in.front() == '0' && res.top() == 0.0) == false)//чтобы не умножать 0 на 10 и не прибавлять (48 - 48) {
        if(fl == 0)//если не встречалось ., т.е. пока у нас обычное, целое число
        {
          res.top() = res.top() * 10 + in.front() - 48;
        }
        else//иначе
        {
          temp = in.front() - 48; //переводим символьное число в обычное
          for(size_t i = 0; i < fl; i++)//и по счетчику разряда делим на 10
          temp /= 10;
          res.top() += temp; //и просто добавляем к текущему
          fl++; //увеличиваем разряд
        }
      }
      in.pop(); //убираем эл.
      if(in.empty() != true && in.front() == '.')//если встретилась точка и очередь не пуста, то
      {
        fl = 1; //счетчик разряда ставим в 1
        in.pop(); //и удаляем .
      }
    }
    fl = 0; //после считывания числа, обнуляем счетчик разрядов
  }
  else if(is_var(in.front()) == true)//если же нам встретилась переменная
  {
    if(op == true) {
      res.push(0.0); op = false;
    }//если до этого была операция, а теперь нам нужно ввести новое значение, то выделяем память
    var_buf.clear(); //очищаем буфер
    do
    {
      //вносим название переменной в буфер. А в цикле за тем, чтобы можно было писать переменные не в одну букву
      var_buf.push_back(in.front());
      in.pop();
    }while(in.empty() != true && is_var(in.front()) == true);

    if(mem.find(var_buf) != mem.end())//проверяем, была ли такая переменная
    {
      res.top() = mem[var_buf]; //если да, то присваиваем топу то запомненное значение
    }
    else//если же мы не нашли, то просим ввести новое значение
    {
      cout << "Please enter the variable \'" << var_buf << "\': "; //просим пользователя её ввести
      cin >> res.top(); //вводим значение переменной с клавиатуры
      mem[var_buf] = res.top(); //запоминаем переменную и её значение
    }
  }
  else if(in.front() == ';' ||
    is_oper(in.front()) == true)//если же нам наконец попалась операция
  {
    if(minus == true)//если флаг минуса поднят
    {
      minus = false; //опускаем флаг
      res.top() = -res.top(); //умножаем текущее значение на -1
    }
    if(in.front() == ';')//если это знак разделитель, значит надо добавить памяти
    {
      res.push(0.0); //добавляем
      in.pop(); //убираем знак
    }
    else if(res.size() > 1)//иначе, если у нас уже что-то есть в стеке
    {
      temp = res.top(); //пихаем в temp последнее значение
      res.pop(); //убираем его из стека
      switch(in.front())//смотрим что это и делаем необходимые операции
      {
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
        case 'sin':
        res.top() = sin(res(top));
        break;
        case 'cos':
        res.top() = cos(res.top());
        break;
        case 'tan':
        res.top() = tan(res.top());
        break;
        case 'ctg':
        res.top() = 1/tan(res.top());
        break;
        case '√':
        res.top() = sqrt(res.top());
        break;
        case '√3':
        res.top() = cbrt(res.top());
        break;
      }
      op = true; //ставим флаг операции
      in.pop(); //убираем символ операции из очереди
    }
  }
}
if(res.size() > 1)//если вдруг в стеке осталось что-то кроме результата, выводим сообщение об ошибке и все, что осталось в стеке
{
  cout << "something went wrong!";
  while(res.empty() != true) {
    cout << res.top() << ' ';
    res.pop();
  }
  return 0.0;
}
return res.top(); //если же все хорошо, возвращаем результат
}


//keygen

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

//converter