#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node -  creates a binary tree node
 * @parent: node parent
 * @node_value: node value
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int node_value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = node_value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
