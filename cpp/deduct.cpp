#include <string>

template<typename T>
class TypeOf<T>;

template<typename T>
void funclref(T& param)
{
  TypeOf<T> type_of_t;
  TypeOf<decltype(param)> type_of_param;
}

template<typename T>
void funclptr(T* param)
{
  TypeOf<T> type_of_t;
  TypeOf<decltype(param)> type_of_param;
}

template<typename T>
void funclval(T param)
{
  TypeOf<T> type_of_t;
  TypeOf<decltype(param)> type_of_param;
}

template<typename T>
void funcrref(T&& param)
{
  TypeOf<T> type_of_t;
  TypeOf<decltype(param)> type_of_param;
}

std::string rval()
{
  std::string str("rvalue");
  return str;
}

int main()
{
  std::string lval("lvalue");
  std::string& lval_ref = lval;
  std::string* lval_ptr = &lval;
  const std::string clval("clvalue");
  const std::string& clval_ref = clval;
  const std::string* clval_ptr = &clval;

  //funclref(lval);
  //funclref(lval_ref);
  //funclref(lval_ptr);
  //funclref(clval);
  //funclref(clval_ref);
  
  //funclval(lval);
  //funclval(lval_ref);
  //funclval(lval_ptr);
  //funclval(clval);
  //funclval(clval_ref);
  //funclval(rval());

  //funclptr(lval);
  //funclptr(lval_ref);
  //funclptr(lval_ptr);
  //funclptr(clval);
  //funclptr(clval_ptr);
  
  //funcrref(lval);
  //funcrref(lval_ref);
  //funcrref(lval_ptr);
  //funcrref(clval);
  //funcrref(clval_ref);
  funcrref(rlval());

  return 0;
}


