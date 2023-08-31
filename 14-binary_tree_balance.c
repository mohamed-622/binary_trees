#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_v, right_v, max_v;

	if (tree == NULL)
		return (0);

	left_v = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_v = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	max_v = left_v > right_v ? left_v : right_v;
	return (max_v);
}

/**
 * binary_tree_balance - check if a binary tree is balanced or not
 * Description: check if all nodes have a left/right nodes
 *
 * @tree: the binary tree
 * Return: 0 not balanced | 1 balanced
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_v, right_v;

	if (tree == NULL)
		return (0);

	left_v = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_v = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_v - right_v);
}
