#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in
 * a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: the depth of the node && f tree is NULL, your function must return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree->parent && tree != NULL) ? 1 + binary_tree_depth(tree->parent) : 0);
}
