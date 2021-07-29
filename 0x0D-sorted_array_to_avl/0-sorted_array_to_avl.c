#include "binary_trees.h"

/**
 * create_node - function to create a new node
 * @parent: parent of the struct
 * @n: new node
 * Return: new node
 **/

avl_t *create_node(avl_t *parent, int n)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
 * create_tree - create new node for avl tree
 * @array: pointer to the first element of the array
 * @start: start of the array
 * @size: size of the array
 * @parent: pointer to the parent node
 * Return: root of the tree
 **/

avl_t *create_tree(int *array, int start, int size, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > size)
		return (NULL);
	mid = (start + size) / 2;
	root = create_node(parent, array[mid]);

	if (!root)
		return (NULL);

	root->left = create_tree(array, start, mid - 1, root);
	root->right = create_tree(array, mid + 1, size, root);

	return (root);
}

/**
 * sorted_array_to_avl - convert an array to avl tree
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree
 **/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	printf("%ld", size);
	return (create_tree(array, 0, size - 1, NULL));
}
