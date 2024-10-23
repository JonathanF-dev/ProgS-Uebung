
// This program shows how you can display the stack and memory layout for
// variables and structures that is created by your compiler.
// Feel free to adapt for your own structs and classes as needed.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>

class StackLayout {
public:
  template <typename T>
  void addValue(std::string const& name, T* addr) {
    addrList_.push_back(std::make_pair(name, std::make_pair((size_t)addr, sizeof(T))));
  }

  void prettyPrint() {
    // Now sort accordingt to memory address stored
    std::sort(addrList_.begin(), addrList_.end(), [] (AddrTextType a, AddrTextType b) { return a.second.first < b.second.first; } );

    // Now print out the information, including padding
    std::cout << "The stack memory layout for function foo is (read from bottom to top!): " << std::endl << std::endl;
    size_t totalStackBytes   = 0;
    size_t totalStackPadding = 0;
    for (int i = 0; i < addrList_.size(); ++i) {
      std::cout << "Variable " << std::setw(5) << addrList_[i].first << " at memory address " << std::hex << "0x" << addrList_[i].second.first;
      std::cout << " (" << addrList_[i].second.second << " bytes)" << std::endl;
      totalStackBytes += addrList_[i].second.second;
      // Check if there is padding inserted. If so, print it.
      if (i < addrList_.size()-1) {
        size_t addrDiff = addrList_[i+1].second.first - addrList_[i].second.first;
        if (addrDiff != addrList_[i].second.second) {
          size_t padding = addrDiff - addrList_[i].second.second;
          std::cout << "\t########### Padding ########### (" << std::dec << padding << " bytes)" << std::endl;
          totalStackPadding += padding;
        }
      }
    }
    std::cout << std::endl;
    std::cout << "The stack of function foo requires a total of " << std::dec << totalStackBytes+totalStackPadding << " bytes from which " << totalStackPadding << " bytes are padding." << std::endl << std::endl;
  }
private:
  // Pair type, will hold Address - Sizeof Data
  typedef std::pair<size_t, size_t>            AddrSizeType;
  // Pair type, will hold Name - AddrSizeType
  typedef std::pair<std::string, AddrSizeType> AddrTextType;
  // Address/Text/TypeList
  typedef std::vector<AddrTextType> AddrListType;
  AddrListType addrList_;
};

enum class Color { Red, Green, Blue };

// The function whose stack layout should be printed
void foo() {
   bool b;
   short s;
   char16_t w;
   double d;
   unsigned char c;
   int i;
   Color e;
   int l;
   float f;
   char *p;

  // List of all elements - it is also on the stack
  StackLayout sl;
  sl.addValue("b", &b);
  sl.addValue("s", &s);
  sl.addValue("w", &w);
  sl.addValue("d", &d);
  sl.addValue("c", &c);
  sl.addValue("i", &i);
  sl.addValue("e", &e);
  sl.addValue("l", &l);
  sl.addValue("f", &f);
  sl.addValue("p", &p);
  sl.addValue("sl", &sl);
  sl.prettyPrint();
}

int main() {
  foo();
  return 0;
}
