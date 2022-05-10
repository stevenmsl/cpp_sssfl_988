#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1092;

/*
Input: [0,1,2,3,4,3,4]

Output: “dba”
*/

tuple<Node *, string>
testFixture1()
{
  auto root = new Node('a' - 'a');
  root->left = new Node('b' - 'a');
  root->left->left = new Node('d' - 'a');
  root->left->right = new Node('e' - 'a');
  root->right = new Node('c' - 'a');
  root->right->left = new Node('d' - 'a');
  root->right->right = new Node('e' - 'a');

  return make_tuple(root, "dba");
}

/*
Input: [25,1,3,1,3,0,2]

Output: “adz”
*/

tuple<Node *, string>
testFixture2()
{
  auto root = new Node('z' - 'a');
  root->left = new Node('b' - 'a');
  root->left->left = new Node('b' - 'a');
  root->left->right = new Node('d' - 'a');
  root->right = new Node('d' - 'a');
  root->right->left = new Node('a' - 'a');
  root->right->right = new Node('c' - 'a');

  return make_tuple(root, "adz");
}

/*
Input: [2,2,1,null,1,0,null,0]

Output: “abc”
*/

tuple<Node *, string>
testFixture3()
{
  auto root = new Node('c' - 'a');
  root->left = new Node('c' - 'a');
  root->left->right = new Node('b' - 'a');
  root->left->right->left = new Node('a' - 'a');
  root->right = new Node('b' - 'a');
  root->right->left = new Node('a' - 'a');

  return make_tuple(root, "abc");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findSmallest(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findSmallest(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findSmallest(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}