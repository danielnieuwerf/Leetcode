#pragma once

/*
Problem:

Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool isBalanced(TreeNode* x) {
		if (x == NULL)
			return true;
		if (x->left == NULL) {
			if (x->right == NULL)
				return true;
			if (x->right->left == NULL && x->right->right == NULL)
				return true;
			return false;
		}
		if (x->right == NULL) {
			if (x->left == NULL)
				return true;
			if (x->left->left == NULL && x->left->right == NULL)
				return true;
			return false;
		}

		// Depth of right and left nodes should not exceed 1
		if (abs(depthOfNode(x->right) - depthOfNode(x->left)) >= 2)
			return false;

		return isBalanced(x->right) && isBalanced(x->left);
	}


	int depthOfNode(TreeNode* x) {
		if (x == NULL)
			return 0;
		return 1 + max(depthOfNode(x->left), depthOfNode(x->right));
	}
};