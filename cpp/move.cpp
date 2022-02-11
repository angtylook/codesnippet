#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// cc -O0 -fno-elide-constructors

static int c = 0;

class Vector {
  public:
    Vector(): id_(c), size_(0), arr_(nullptr) {
      std::cout << "Default construct: " << id_ << std::endl;
      c++;
    }

    Vector(const Vector& rhs) {
      id_ = c;
      c++;

      std::cout << "lhs " << id_ << " rhs " << rhs.id_ << " Copy construct" << std::endl;
      size_ = rhs.size_;
      arr_ = new double[size_];
      for(int i = 0; i < size_; ++i) {
	    arr_[i] = rhs.arr_[i];
      }
    }

    Vector(Vector&& rhs) {
      std::cout << "lhs " << id_ << " rhs " << rhs.id_ << " Move construct" << std::endl;

      arr_ = rhs.arr_;
      id_ = rhs.id_;
      size_ = rhs.size_;

      rhs.size_ = 0;
      rhs.arr_ = nullptr;
    }


    ~Vector() {
      std::cout << "Destroy: " << id_ << std::endl;
      if(arr_)
      	delete[] arr_;
    }
  private:
    int id_;
    int size_;
    double* arr_;
};

void foo(Vector& v) {
  std::cout << "in foo&" << std::endl;
}

void foo(Vector&& v) {
  std::cout << "in foo&&" << std::endl;
}

/*
void foo(Vector v) {
  std::cout << "in foo" << std::endl;
}
*/

Vector createVector() {
  Vector v;
  std::cout << "before return" << std::endl;
  return v;
}

int main() {
  Vector resuable = createVector();
  std::cout << "before call" << std::endl;
  foo(resuable);

  foo(createVector());

  std::vector<std::string> test1{"1", "2", "3"};
  std::unordered_map<int, std::string> m;
  for(auto& e : test1)
  {
    m[std::stoi(e)] = std::move(e);
    std::cout << e << std::endl;
  }

  for(auto it : m)
  {
    std::cout << it.first << " " << it.second << std::endl;
  }

  return 0;
}


