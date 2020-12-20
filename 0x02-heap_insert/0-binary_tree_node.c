#include "binary_trees.h"

/**
 *binary_tree_node - functon that creates a binary tree node
 *@parent: parent of the binary tree
 *@value: value to set
 *Return: new child
 **/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *aux = NULL;

	aux = malloc(sizeof(binary_tree_t));

	if (aux == NULL)
		return (NULL);

	if (parent == NULL)
		aux->parent = NULL;
	else
		aux->parent = parent;

	aux->left = NULL;
	aux->right = NULL;

	aux->n = value;
	return (aux);
}
