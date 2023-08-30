#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as
 * the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
	{
		return (NULL);
	}
	new = binary_tree_node(parent, value);
	if (new == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;
	return (new);
}
