#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node.
 * @node: A pointer to the node to find the sibling.
 * Return: If node is NULL || there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ancestor;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	ancestor = node->parent;
	if (ancestor->left == NULL || ancestor->right == NULL)
		return (NULL);

	if (ancestor->left->n == node->n)
		return (ancestor->right);
	else
		return (ancestor->left);
}

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: A pointer to the node to find the uncle.
 * Return: If node is NULL || has no uncle, NULL.
 *         Otherwise, a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *ancestor, *uncle;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	ancestor = node->parent;
	uncle = binary_tree_sibling(ancestor);

	return (uncle);
}
