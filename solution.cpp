#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>
using namespace sol1092;
using namespace std;

/*takeaways
  - traverse the tree and pick the smaller string from
    one of the child
  - be careful of how to handle the case where a node
    only have one child. Make sure it's picked
*/

string Solution::findSmallest(Node *root)
{
  if (root == nullptr)
    /* return something bigger than 'z'
       so this node will never be picked
       by the parent node
    */
    return string(1, char('z' + 1));

  auto val = string(1, char('a' + root->val));

  /* reach a leaf node */
  if (root->left == nullptr && root->right == nullptr)
    return val;

  auto l = findSmallest(root->left);
  auto r = findSmallest(root->right);

  return min(l, r) + val;
}