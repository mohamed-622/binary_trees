#include "binary_trees.h"
#include <stdio.h>

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
binary_tree_t *array_comp(binary_tree_t **first_to_root_array,
		binary_tree_t **second_to_root_array, int i, int y);

/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 * of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * if no common ancestor was found, your function must return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t **first_to_root_array, **second_to_root_array;
	binary_tree_t *root;
	int i, y;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	root = (binary_tree_t *)first;
	first_to_root_array = malloc(sizeof(binary_tree_t *));
	for (i = 0; !(root != NULL && root->parent == NULL); i++)
	{
		first_to_root_array = realloc(first_to_root_array,
				(sizeof(binary_tree_t *) * (i + 1)));
		first_to_root_array[i] = root;
		root = root->parent;
	}
	first_to_root_array = realloc(first_to_root_array,
			(sizeof(binary_tree_t *) * (i + 1)));
	first_to_root_array[i] = root;
	root = (binary_tree_t *)second;
	second_to_root_array = malloc(sizeof(binary_tree_t *));
	for (y = 0; !(root != NULL && root->parent == NULL); y++)
	{
		second_to_root_array = realloc(second_to_root_array,
				(sizeof(binary_tree_t *) * (y + 1)));
		second_to_root_array[y] = root;
		root = root->parent;
	}
	second_to_root_array = realloc(second_to_root_array,
			(sizeof(binary_tree_t *) * (y + 1)));
	second_to_root_array[y] = root;
	return (array_comp(first_to_root_array, second_to_root_array, i, y));
}

/**
 * array_comp - a function that compare two array to find a common ancestor
 * @first_to_root_array: the first node array route
 * @second_to_root_array: the seconde node array route
 * @i: first_to_root_array size
 * @y: second_to_root_array size
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * if no common ancestor was found, your function must return NULL
 */

binary_tree_t *array_comp(binary_tree_t **first_to_root_array,
		binary_tree_t **second_to_root_array, int i, int y)
{
	int a, b;

	for (a = 0; a < i + 1; a++)
	{
		for (b = 0; b < y + 1; b++)
		{
			if ((first_to_root_array[a]) == (second_to_root_array[b]))
			{
				return (first_to_root_array[a]);
			}
		}
	}
	return (NULL);
}
