#include <string>

#define protected public

#include "all_tests_s21.h"

using namespace s21;

TEST(Constructor, test1) {
  std::pair<int, int> init1(1, 10);
  std::pair<int, int> init2(2, 20);
  map<int, int> A({init1, init2});
  EXPECT_DOUBLE_EQ(A[1], 10);
}

TEST(Constructor, test2) {
  map<int, int> A;
  EXPECT_EQ(A.begin(), nullptr);
}

TEST(CopyConstructor, test1) {  // Equal keys and values
  std::pair<int, int> init1(1, 10);
  std::pair<int, int> init2(2, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(A);
  EXPECT_DOUBLE_EQ(B[3], 30);
}

TEST(CopyConstructor, test2) {  // Equal size
  std::pair<int, int> init1(1, 10);
  std::pair<int, int> init2(2, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(A);
  EXPECT_DOUBLE_EQ(A.size(), B.size());
}

TEST(CopyConstructor, test3) {  // Different end-iterators
  std::pair<char, char> init1(1, 10);
  std::pair<char, char> init2(2, 20);
  std::pair<char, char> init3(3, 30);
  map<char, char> A({init1, init2, init3});
  map<char, char> B(A);
  EXPECT_NE(A.end(), B.end());
}

TEST(CopyConstructor, test4) {  // Different begin-iterators
  std::pair<float, float> init1(1, 10);
  std::pair<float, float> init2(2, 20);
  std::pair<float, float> init3(3, 30);
  map<float, float> A({init1, init2, init3});
  map<float, float> B(A);
  EXPECT_NE(A.begin(), B.begin());
}

TEST(CopyConstructor,
     test5) {  // Checking that we have indeed two different maps
  std::pair<int, int> init1(1, 10);
  std::pair<int, int> init2(-2, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(A);
  EXPECT_NE(&A[1], &B[1]);
}

TEST(CopyConstructor, test6) {
  std::pair<int, int> init1(1, 10);
  std::pair<int, int> init2(-2, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(A);
  EXPECT_DOUBLE_EQ(A.begin_->key_, B.begin_->key_);
}

TEST(CopyConstructor, test7) {
  std::pair<int, int> init1(1, 10);
  std::pair<int, int> init2(-2, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(A);
  EXPECT_DOUBLE_EQ(A.end_->head_->key_, B.end_->head_->key_);
}

TEST(MoveConstructor, test1) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(1, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B = std::move(A);
  EXPECT_DOUBLE_EQ(B[3], 30);
}

TEST(MoveConstructor, test2) {  // Equal keys and values
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(1, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(std::move(A));
  EXPECT_DOUBLE_EQ(B[3], 30);
}

TEST(MoveConstructor, test3) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(1, 20);
  std::pair<int, int> init3(3, 30);
  map<int, int> A({init1, init2, init3});
  map<int, int> B(std::move(A));
  EXPECT_NE(B.end(), nullptr);
}

TEST(At, test1) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.at(3), 34);
}

TEST(At, test2) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  A.at(3) = 500;
  EXPECT_DOUBLE_EQ(A.at(3), 500);
}

TEST(At, test3) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_THROW(A.at(300), std::out_of_range);
}

TEST(At, test4) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(1, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_THROW(A.at(0), std::out_of_range);
}

TEST(At, test5) {
  map<int, int> A;
  EXPECT_THROW(A.at(0), std::out_of_range);
}

TEST(BraceOperator, test1) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  A[3] = 500;
  EXPECT_DOUBLE_EQ(A.at(3), 500);
}

TEST(BraceOperator, test2) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  A[300] = 500;
  EXPECT_DOUBLE_EQ(A.at(300), 500);
}

TEST(IteratorBegin, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.begin()->key_, init5.first);
}

TEST(IteratorBegin, test2) {
  map<float, float> A;
  EXPECT_EQ(A.begin(), nullptr);
}

TEST(IteratorConstBegin, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  const map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.begin()->key_, init5.first);
}

TEST(IteratorConstBegin, test2) {
  const map<float, float> A;
  EXPECT_EQ(A.begin(), nullptr);
}

TEST(IteratorEnd, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.end()->head_->key_, init6.first);
}

TEST(IteratorEnd, test2) {
  map<float, float> A;
  EXPECT_EQ(A.end(), nullptr);
}

TEST(IteratorConstEnd, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  const map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.end()->head_->key_, init6.first);
}

TEST(IteratorConstEnd, test2) {
  const map<float, float> A;
  EXPECT_EQ(A.end(), nullptr);
}

TEST(Empty, test1) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.empty(), false);
}

TEST(Empty, test2) {
  map<int, int> A;
  EXPECT_EQ(A.empty(), true);
}

TEST(ConstEmpty, test1) {
  std::pair<int, int> init1(2, 200);
  std::pair<int, int> init2(-1, 4);
  std::pair<int, int> init3(4, 30);
  std::pair<int, int> init4(0, 0);
  std::pair<int, int> init5(-12, 20);
  std::pair<int, int> init6(5, 15);
  std::pair<int, int> init7(3, 34);
  const map<int, int> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.empty(), false);
}

TEST(ConstEmpty, test2) {
  const map<int, int> A;
  EXPECT_EQ(A.empty(), true);
}

TEST(MaxSize, test1) {
  map<int, int> A;
  EXPECT_NE(A.max_size(), 0);
}

TEST(ConstMaxSize, test1) {
  const map<int, int> A;
  EXPECT_NE(A.max_size(), 0);
}

TEST(Size, test1) {
  map<int, int> A;
  EXPECT_EQ(A.size(), 0);
}

TEST(Size, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.size(), 7);
}

TEST(ConstSize, test1) {
  const map<int, int> A;
  EXPECT_EQ(A.size(), 0);
}

TEST(ConstSize, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  const map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_DOUBLE_EQ(A.size(), 7);
}

TEST(Clear, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.clear();
  EXPECT_DOUBLE_EQ(A.size(), 0);
}

TEST(Clear, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.clear();
  EXPECT_EQ(A.begin(), nullptr);
}

TEST(Clear, test3) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.clear();
  EXPECT_EQ(A.end(), nullptr);
}

TEST(Insert, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_NE(A.insert(10, 10).first, nullptr);
}

TEST(Insert, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.insert(10, 10).second, true);
}

TEST(Insert, test3) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  A.insert(10, 10);
  EXPECT_EQ(A.size(), ++cnt);
}

TEST(Insert, test4) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  A.insert(3.0, 34.0);
  EXPECT_EQ(A.size(), cnt);
}

TEST(Insert, test5) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.insert(3.0, 34.0).second, false);
}

TEST(Insert, test6) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  std::pair<float, float> insert_pair(10, 10);
  EXPECT_NE(A.insert(insert_pair).first, nullptr);
}

TEST(Insert, test7) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  std::pair<float, float> insert_pair(10, 10);
  EXPECT_EQ(A.insert(insert_pair).second, true);
}

TEST(Insert, test8) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  std::pair<float, float> insert_pair(10, 10);
  A.insert(insert_pair);
  EXPECT_EQ(A.size(), ++cnt);
}

TEST(Insert, test9) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  std::pair<float, float> insert_pair(3, 34);
  A.insert(insert_pair);
  EXPECT_EQ(A.size(), cnt);
}

TEST(Insert, test10) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  std::pair<float, float> insert_pair(3, 34);
  A.insert(insert_pair);
  EXPECT_EQ(A.insert(insert_pair).second, false);
}

TEST(Insert, test11) {
  map<float, float> A;
  A.insert(10, 8);
  EXPECT_EQ(A[10], 8);
}

TEST(Insert, test12) {
  map<float, float> A;
  A.insert(10, 8);
  EXPECT_EQ(A.size(), 1);
}

TEST(Insert, test13) {
  map<float, float> A;
  A.insert(10, 8);
  EXPECT_NE(A.begin(), nullptr);
}

TEST(Insert, test14) {
  map<float, float> A;
  A.insert(10, 8);
  EXPECT_NE(A.end(), nullptr);
}

TEST(InsertOrAssign, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.insert_or_assign(10, 10);
  EXPECT_DOUBLE_EQ(A[10], 10);
}

TEST(InsertOrAssign, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.insert_or_assign(10, 10).second, true);
}

TEST(InsertOrAssign, test3) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.insert_or_assign(3, 34).second, false);
}

TEST(InsertOrAssign, test4) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.insert_or_assign(3, 34);
  EXPECT_DOUBLE_EQ(A[3], 34);
}

TEST(InsertOrAssign, test5) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  A.insert_or_assign(3, 34);
  EXPECT_EQ(cnt, A.size());
}

TEST(InsertOrAssign, test6) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  A.insert_or_assign(10, 10);
  EXPECT_EQ(++cnt, A.size());
}

TEST(Contains, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.contains(5.009), true);
}

TEST(Contains, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.contains(5.09), false);
}

TEST(ConstContains, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  const map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.contains(5.009), true);
}

TEST(ConstContains, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  const map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  EXPECT_EQ(A.contains(5.09), false);
}

TEST(Erase, test1) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_);
  EXPECT_DOUBLE_EQ(A.root_->key_, init3.first);
}

TEST(Erase, test2) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_->left_);
  EXPECT_DOUBLE_EQ(A.root_->left_->key_, init4.first);
}

TEST(Erase, test3) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_->left_->left_);
  EXPECT_EQ(A.root_->left_->left_, nullptr);
}

TEST(Erase, test4) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_->left_->right_);
  EXPECT_EQ(A.root_->left_->right_, nullptr);
}

TEST(Erase, test5) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_->right_->right_);
  EXPECT_EQ(A.root_->right_->right_, A.end_);
}

TEST(Erase, test6) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_->right_->left_);
  EXPECT_EQ(A.root_->right_->left_, nullptr);
}

TEST(Erase, test7) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.root_->right_);
  EXPECT_EQ(A.root_->right_->key_, init7.first);
}

TEST(Erase, test8) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  size_t cnt = A.size();
  A.erase(A.root_->right_);
  EXPECT_EQ(A.size(), --cnt);
}

TEST(Erase, test9) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.begin());
  EXPECT_DOUBLE_EQ(A.begin()->key_, init2.first);
}

TEST(Erase, test10) {
  std::pair<float, float> init1(2.1, 200.9);
  std::pair<float, float> init2(-1.1, 4.81);
  std::pair<float, float> init3(4.1, 30.30);
  std::pair<float, float> init4(0.25, 0.25);
  std::pair<float, float> init5(-12.07, 20.24);
  std::pair<float, float> init6(5.009, 15.45);
  std::pair<float, float> init7(3.0, 34.0);
  map<float, float> A({init1, init2, init3, init4, init5, init6, init7});
  A.erase(A.end()->head_);
  EXPECT_DOUBLE_EQ(A.end()->head_->key_, init3.first);
}

TEST(Erase, test11) {
  std::pair<float, float> init1(100, 100);
  map<float, float> A({init1});
  A.erase(A.root_);
  EXPECT_EQ(A.root_, nullptr);
}

TEST(Erase, test12) {
  std::pair<float, float> init1(100, 100);
  map<float, float> A({init1});
  A.erase(A.root_);
  EXPECT_EQ(A.begin(), nullptr);
}

TEST(Merge, test1) {
  map<int, int> A({{1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{1, 0}, {2, 0}, {4, 0}, {5, 0}, {8, 0}});
  int cnt = A.size();
  A.merge(B);
  EXPECT_EQ(A.size(), cnt + 3);
}

TEST(Merge, test2) {
  map<int, int> A({{1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {4, 0}, {5, 0}, {8, 0}});
  int cnt = A.size();
  A.merge(B);
  EXPECT_EQ(A.size(), cnt + 3);
}

TEST(Merge, test3) {
  map<int, int> A({{1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {4, 0}, {5, 0}, {8, 0}});
  A.merge(B);
  EXPECT_EQ(B.size(), 1);
}

TEST(Merge, test4) {
  map<int, int> A({{1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {4, 0}, {8, 0}});
  A.merge(B);
  EXPECT_EQ(B.size(), 0);
}

TEST(Merge, test5) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {-4, 0}, {4, 0}, {8, 0}, {-10, 10}});
  A.merge(B);
  EXPECT_EQ(B.size(), 1);
}

TEST(Merge, test6) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {-4, 0}, {4, 0}, {8, 0}, {-10, 10}});
  A.merge(B);
  EXPECT_NE(A.begin(), B.begin());
}

TEST(Merge, test7) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {-4, 0}, {4, 0}, {8, 0}, {-10, 10}});
  A.merge(B);
  EXPECT_NE(A.end(), B.end());
}

TEST(Merge, test8) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {-4, 0}, {4, 0}, {8, 0}, {-10, 10}, {10, 0}});
  A.merge(B);
  EXPECT_NE(A.end(), B.end());
}

TEST(Merge, test9) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {-4, 0}, {4, 0}, {8, 0}, {-10, 10}, {10, 0}});
  A.merge(B);
  EXPECT_NE(A.end()->head_, B.end()->head_);
}

TEST(Merge, test10) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  A.merge(B);
  EXPECT_NE(A.end()->head_, B.end()->head_);
}

TEST(Merge, test11) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  A.merge(B);
  EXPECT_NE(A.end(), B.end());
}

TEST(Merge, test12) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  A.merge(B);
  EXPECT_NE(A.begin(), B.begin());
}

TEST(Merge, test13) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  A.merge(B);
  EXPECT_EQ(A.size(), B.size());
}

TEST(Merge, test14) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{2, 0}, {-4, 0}, {4, 0}, {8, 0}, {-10, 10}});
  A.merge(B);
  EXPECT_EQ(B.end()->head_->key_, -10);
}

TEST(Merge, test15) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B;
  A.merge(B);
  EXPECT_EQ(A.end()->head_->key_, 10);
}

TEST(Merge, test16) {
  map<int, int> A({{-5, 0}, {-10, 0}, {1, 0}, {5, 0}, {10, 0}});
  map<int, int> B;
  A.merge(B);
  EXPECT_EQ(A.size(), 5);
}

TEST(Merge, test17) {
  map<int, int> A({{1, 0}, {5, 0}, {10, 0}});
  map<int, int> B({{1, 0}, {2, 0}, {4, 0}, {5, 0}, {8, 0}});
  A.merge(B);
  EXPECT_EQ(A[2], 0);
}

TEST(Swap, test1) {
  map<int, int> A({{-5, 5}, {-10, 6}, {1, 7}, {5, 8}, {10, 9}});
  map<int, int> B({{2, 1}, {-4, 2}, {4, 3}, {8, 4}, {-10, 10}});
  A.swap(B);
  EXPECT_EQ(A[2], 1);
}

TEST(Swap, test2) {
  map<int, int> A({{-5, 5}, {-10, 6}, {1, 7}, {5, 8}, {10, 9}});
  map<int, int> B({{2, 1}, {-4, 2}, {4, 3}, {8, 4}, {-10, 10}});
  A.swap(B);
  EXPECT_EQ(B[-10], 6);
}

TEST(Swap, test3) {
  map<int, int> A({{-5, 5}, {-10, 6}, {1, 7}, {5, 8}, {10, 9}});
  map<int, int> B({{2, 1}, {-4, 2}, {4, 3}, {8, 4}, {-10, 10}});
  size_t size = B.size();
  A.swap(B);
  EXPECT_EQ(A.size(), size);
}

TEST(Swap, test4) {
  map<int, int> A({{-5, 5}, {-10, 6}, {1, 7}, {5, 8}, {10, 9}});
  map<int, int> B({{2, 1}, {-4, 2}, {4, 3}, {8, 4}, {-10, 10}});
  map<int, int>::iterator end(B.end());
  A.swap(B);
  EXPECT_EQ(A.end(), end);
}

TEST(Swap, test5) {
  map<int, int> A({{-5, 5}, {-10, 6}, {1, 7}, {5, 8}, {10, 9}});
  map<int, int> B({{2, 1}, {-4, 2}, {4, 3}, {8, 4}, {-10, 10}});
  map<int, int>::iterator begin(B.begin());
  A.swap(B);
  EXPECT_EQ(A.begin(), begin);
}

TEST(InsertMany, test1) {
  map<int, int> A({{-5, 8}});
  A.insert_many(std::pair<int, int>{-3, 5}, std::pair<int, int>{2, 1},
                std::pair<int, int>{12, 12}, std::pair<int, int>{25, 4},
                std::pair<int, int>{-36, 0});
  EXPECT_EQ(A[-3], 5);
}

TEST(InsertMany, test2) {
  map<int, int> A({{-5, 8}});
  A.insert_many(std::pair<int, int>{-3, 5}, std::pair<int, int>{2, 1},
                std::pair<int, int>{12, 12}, std::pair<int, int>{25, 4},
                std::pair<int, int>{-36, 0});
  EXPECT_EQ(A.size(), 6);
}

TEST(InsertMany, test3) {
  map<int, int> A;
  A.insert_many(std::pair<int, int>{-3, 5}, std::pair<int, int>{2, 1},
                std::pair<int, int>{12, 12}, std::pair<int, int>{25, 4},
                std::pair<int, int>{-36, 0});
  EXPECT_EQ(A[-3], 5);
}

TEST(InsertMany, test4) {
  map<int, int> A;
  A.insert_many(std::pair<int, int>{-3, 5}, std::pair<int, int>{2, 1},
                std::pair<int, int>{12, 12}, std::pair<int, int>{25, 4},
                std::pair<int, int>{-36, 0});
  EXPECT_EQ(A.size(), 5);
}

TEST(EmptyMap, test1) {
  map<int, int> A;
  A[4] = 400;
  EXPECT_EQ(A[4], 400);
}

TEST(EmptyMap, test2) {
  map<int, int> A;
  A[4] = 400;
  EXPECT_NE(A.begin(), nullptr);
}

TEST(EmptyMap, test3) {
  map<int, int> A;
  A[4] = 400;
  EXPECT_NE(A.end(), nullptr);
}

TEST(EmptyMap, test4) {
  map<int, int> A;
  A[4] = 400;
  EXPECT_EQ(A.size(), 1);
}

TEST(EmptyMap, test5) {
  map<int, int> A;
  EXPECT_EQ(A.begin(), nullptr);
}

TEST(EmptyMap, test6) {
  map<int, int> A;
  EXPECT_EQ(A.end(), nullptr);
}

TEST(EmptyMap, test7) {
  map<int, int> A;
  EXPECT_EQ(A.size(), 0);
}

TEST(String, test1) {
  map<std::string, int> A;
  A["abcd"] = 100;
  EXPECT_EQ(A["abcd"], 100);
}

TEST(String, test2) {
  map<std::string, std::string> A;
  A["abcd"] = "dcba";
  EXPECT_EQ(A["abcd"], "dcba");
}

TEST(String, test3) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  EXPECT_EQ(A["A"], "a");
}

TEST(String, test4) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  map<std::string, std::string> B = A;
  EXPECT_EQ(B["A"], "a");
}

TEST(String, test5) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  map<std::string, std::string> B = std::move(A);
  EXPECT_EQ(B["A"], "a");
}

TEST(String, test6) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  EXPECT_EQ(A.at("A"), "a");
}

TEST(String, test7) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  EXPECT_EQ(A["D"], "");
}

TEST(String, test8) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  map<std::string, std::string> B({{"D", "d"}, {"E", "e"}, {"F", "f"}});
  A.swap(B);
  EXPECT_EQ(A["D"], "d");
}

TEST(String, test9) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  A.erase(A.begin());
  EXPECT_EQ(A.contains("A"), false);
}

TEST(String, test10) {
  map<std::string, std::string> A({{"A", "a"}, {"B", "b"}, {"C", "c"}});
  EXPECT_EQ(A.contains("B"), true);
}
