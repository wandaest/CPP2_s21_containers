#include <deque>
#include <stack>

#include "all_tests_s21.h"

using IntStack = s21::stack<int>;

TEST(StackTest, DefaultConstructor) {
  IntStack stack;
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, PushAndTop) {
  IntStack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);
  EXPECT_EQ(stack.top(), 30);
  EXPECT_EQ(stack.size(), 3);
}

TEST(StackTest, Pop) {
  IntStack stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  stack.pop();
  EXPECT_EQ(stack.top(), 20);
  EXPECT_EQ(stack.size(), 2);

  stack.pop();
  EXPECT_EQ(stack.top(), 10);
  EXPECT_EQ(stack.size(), 1);

  stack.pop();
  EXPECT_TRUE(stack.empty());
  EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, CopyConstructor) {
  IntStack stack1;
  stack1.push(1);
  stack1.push(2);
  stack1.push(3);

  IntStack stack2 = stack1;

  EXPECT_EQ(stack1.size(), stack2.size());
  EXPECT_EQ(stack1.top(), stack2.top());

  stack1.pop();
  EXPECT_EQ(stack1.size(), 2);
  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
}

TEST(StackTest, MoveConstructor) {
  IntStack stack1;
  stack1.push(1);
  stack1.push(2);
  stack1.push(3);

  IntStack stack2 = std::move(stack1);

  EXPECT_EQ(stack2.size(), 3);
  EXPECT_EQ(stack2.top(), 3);
  EXPECT_TRUE(stack1.empty());
}

TEST(StackTest, CopyAssignment) {
  IntStack stack1;
  stack1.push(1);
  stack1.push(2);

  IntStack stack2;
  stack2.push(3);

  stack2 = stack1;

  EXPECT_EQ(stack1.size(), stack2.size());
  EXPECT_EQ(stack1.top(), stack2.top());

  stack1.pop();
  EXPECT_EQ(stack1.size(), 1);
  EXPECT_EQ(stack2.size(), 2);
  EXPECT_EQ(stack2.top(), 2);
}

TEST(StackTest, MoveAssignment) {
  IntStack stack1;
  stack1.push(1);
  stack1.push(2);

  IntStack stack2;
  stack2.push(3);

  stack2 = std::move(stack1);

  EXPECT_EQ(stack2.size(), 2);
  EXPECT_EQ(stack2.top(), 2);
  EXPECT_TRUE(stack1.empty());
}

TEST(StackTest, Swap) {
  IntStack stack1;
  stack1.push(1);
  stack1.push(2);

  IntStack stack2;
  stack2.push(3);
  stack2.push(4);
  stack2.push(5);

  stack1.swap(stack2);
  EXPECT_EQ(stack1.size(), 3);
  EXPECT_EQ(stack1.top(), 5);

  EXPECT_EQ(stack2.size(), 2);
  EXPECT_EQ(stack2.top(), 2);
}

TEST(StackTest, InitializerListConstructor) {
  IntStack stack{1, 2, 3, 4, 5};
  EXPECT_EQ(stack.size(), 5);
  EXPECT_EQ(stack.top(), 5);

  stack.pop();
  EXPECT_EQ(stack.top(), 4);
}

TEST(StackInsertManyBack, Test1) {
  std::deque deq{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::stack container{deq};
  s21::stack<int> s21_container;
  s21_container.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test2) {
  std::stack<int> container;
  s21::stack<int> s21_container;
  s21_container.insert_many_back();
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test3) {
  std::deque deq{1};
  std::stack container{deq};
  s21::stack<int> s21_container;
  s21_container.insert_many_back(1);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test4) {
  std::deque deq{1, 2, 3};
  std::stack container{deq};
  s21::stack<int> s21_container;
  s21_container.insert_many_back(1, 2, 3);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test5) {
  std::deque deq{1, 2, 3};
  std::stack container{deq};
  s21::stack s21_container{1, 2, 3};
  s21_container.insert_many_back();
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test6) {
  std::deque deq{1, 2, 3, 4, 5, 6};
  std::stack container{deq};
  s21::stack s21_container{1, 2, 3};
  s21_container.insert_many_back(4, 5, 6);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test7) {
  std::deque deq{1, 2, 3, 5};
  std::stack container{deq};
  s21::stack s21_container{1, 2, 3};
  s21_container.insert_many_back(5);
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}

TEST(StackInsertManyBack, Test8) {
  std::deque deq{'a',  'b',  'c',  'x',  'y',  'z',
                 '\t', '\v', '\r', '\b', '\f', ' '};
  std::stack container{deq};
  s21::stack s21_container{'a', 'b', 'c', 'x', 'y', 'z'};
  s21_container.insert_many_back('\t', '\v', '\r', '\b', '\f', ' ');
  EXPECT_EQ(s21_container.size(), container.size());
  while (!s21_container.empty()) {
    EXPECT_EQ(s21_container.top(), container.top());
    s21_container.pop();
    container.pop();
  }
  EXPECT_EQ(s21_container.empty(), container.empty());
}
