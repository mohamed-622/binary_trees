#include "binary_trees.h"


/**
 * _power - Calculate the power of a number
 * @a: Number
 * @b: Power
 * Return: @n Power of @b
 */
int _power(int a, int b)
{

	if (b == 0)
		return (1);
	if (b > 0)
		return (a * _power(a, b - 1));
	return (-1);
}

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: The binary tree.
 * Return: Number of nodes.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_value, right_value, max;

	if (tree == NULL)
		return (0);

	left_value = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_value = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	max = left_value > right_value ? left_value : right_value;
	return (max);
}

/**
 * binary_tree_size - Get the size of a binary tree.
 * @tree: The binary tree.
 * Return: Number of nodes in the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * (balanced & full).
 * @tree: The binary tree.
 * Return: 1 If perfect) || 0 If not.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size, height;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = _power(2, height + 1) - 1;

	if (size == (int)binary_tree_size(tree))
		return (1);

	return (0);
}
