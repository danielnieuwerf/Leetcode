#pragma once
/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and 
the nodes have the same value.
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// If either p or q is NULL
		if (p == NULL && q == NULL)
			return 1;
		if (p == NULL && q != NULL)
			return 0;
		if (q == NULL && p != NULL)
			return 0;

		// Neither are null so check value
		if (p->val != q->val)
			return 0;

		// Recursively check right and left
		return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
	}
};