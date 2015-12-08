#include <iostream>
#include <vector>
#include <new>
using namespace std;

class BTreeNode {
public:
    int val;
    int leftCnt;
    int cnt;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int val) {
        this->val = val;
        this->leftCnt = 0;
        this->cnt = 1;
        this->left =NULL;
        this->right = NULL;
    }
};

class BST {
public:
    BTreeNode* root;

    BST() {
        this->root = NULL;
    }

    int insert(int val) {
        int cnt = 0;
        BTreeNode* node = new BTreeNode(val);
        if (root == NULL) {
            root = node;
            cout << "root is NULL" << endl;
            return cnt;
        }
        //cout << "val is " << val << endl;
        //cout << "root->val is " << root->val << endl; 
        BTreeNode* x = root;
        while (x != NULL) {
            if (x->val < val) {
                //cout << "right" << endl;
                //cout << "x->leftCnt is " << x->leftCnt << endl;
                //cout << "x->cnt is " << x->cnt << endl; 
                cnt = cnt + x->leftCnt + x->cnt;
                if (x->right == NULL) {
                    x->right = node;
                    break;
                }
                x = x->right;
            } else if (x->val > val) {
                x->leftCnt++;
                if (x->left == NULL) {
                    x->left = node;
                    break;
                }
                x = x->left;
            } else {
                cnt += x->leftCnt;
                x->cnt++;
                break;
            }
        }
        cout << "cnt is " << cnt << endl;
        return cnt;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BST tree = BST();
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            int cnt = tree.insert(nums[i]);
            result.insert(result.begin(), cnt);
        }
        return result;
    }
};

int main() {
    vector<int> test {5, 2, 6, 1};
    Solution s;
    vector<int> result = s.countSmaller(test);
    return 0;
}
