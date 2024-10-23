
#include <iostream>
#include <functional>
#include <exception>

class IntStack {
public:
  struct IntStackItem {
    int value;
    IntStackItem *next;
    IntStackItem *prev;

    ~IntStackItem() {
      std::cout << "Item " << value << " destroyed." << std::endl;
    }
  };

public:
  IntStack();
  ~IntStack();

  bool isEmpty();
  void push(int value);
  int pop();

  typedef std::function<void (int&)> StackOperation;
  void traverse(StackOperation fn);

private:
  IntStackItem* newItem(int value);
  IntStackItem *sp;
};

IntStack::IntStackItem* IntStack::newItem(int value) {
  IntStackItem *item = new IntStackItem;
  (*item).value = value;
  item->prev = nullptr;
  item->next = nullptr;
  return item;
}

IntStack::IntStack() : sp(nullptr) {}

IntStack::~IntStack() {
  if (!isEmpty()) {
    while (sp) {
      IntStackItem *itemToRemove = sp;
      sp = sp->prev;
      delete itemToRemove;
    }
  }
}

bool IntStack::isEmpty() {
  return sp == nullptr;
}

 void IntStack::push(int value) {
   IntStackItem *item = newItem(value);
   if (sp == nullptr) {
     sp = item;
   } else {
     sp->next   = item;
     item->prev = sp;
     sp         = item;
   }
 }

 int IntStack::pop() {
   if (isEmpty()) {
     throw std::out_of_range("Stack is empty!");
   }

    IntStackItem *itemToRemove = sp;
    sp = sp->prev;
    if (sp != nullptr) {
      sp->next = nullptr;
    }

    int valueToReturn = itemToRemove->value;
    delete itemToRemove;
    return valueToReturn;
 }

void IntStack::traverse(StackOperation fn) {
  if (isEmpty())
    return;

  for (IntStackItem *curr = sp; curr != nullptr; curr = curr->prev) {
    fn(curr->value);
  }
}

void foo() {
  IntStack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
}

int main() {

  IntStack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.pop();
  stack.push(6);

  stack.traverse( [](int& v) { v *= 2; } );

  while (!stack.isEmpty()) {
    std::cerr << "Popping value from the stack: " << stack.pop() << std::endl;
  }

  std::cout << "#######################" << std::endl;
  foo();

  return 0;
}
