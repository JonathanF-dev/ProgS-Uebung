
#include <iostream>
#include <string>

void scan(std::string& str) {
  std::string::iterator itEnd = str.end();
  std::string::iterator it = str.begin();
  
  while (it != itEnd) {
    if (isspace(*it)) {
      ++it;
    } else {
      if (*it == '+' || *it == '-') {
        std::cout << "add_op(" << *it << ")" << std::endl;
        ++it;
      } else if (*it == '*' || *it == '/') {
        std::cout << "mult_op(" << *it << ")" << std::endl;
        ++it;
      } else if (*it >= '0' && *it <= '9') { // DIGIT
        std::string digit;
        digit.push_back(*it);
        ++it;
        while ((*it >= '0' && *it <= '9') && it != itEnd) {
          digit.push_back(*it);
          ++it;
        }
        std::cout << "integer(" << digit << ")" << std::endl;
      } else if ((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z')) {
        std::string id;
        id.push_back(*it);
        ++it;
        while (((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z')) && it != itEnd) {
          id.push_back(*it);
          ++it;
        }
        std::cout << "id(" << id << ")" << std::endl;
      } else {
        std::cout << "INVALID TOKEN (" << *it << ")!" << std::endl;
        it++;
      }
    }
  }
  std::cout << "EOF" << std::endl;
}

int main() {
  bool exit = false;

  while (!exit) {
    std::string str;

    std::cout << "> ";
    std::getline(std::cin, str);
    if (str == "quit") {
      std::cout << std::endl << "Good bye!" << std::endl;
      exit = true;
    } else {
      // std::cout << str << std::endl;
      scan(str);
    }
  }
  return 0;
}