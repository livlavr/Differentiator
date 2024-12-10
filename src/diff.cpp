#include <stdio.h>

#include "diff.h"
#include "tree.h"

TYPE_OF_ERROR DiffTreeInit(Tree<DifferentiatorValue>* tree, DifferentiatorValue root_value) {
    TreeInit(tree, &root_value);

    return SUCCESS;
}

TreeNode<DifferentiatorValue>* CreateDiffNode(DifferentiatorValue diff_value,
    TreeNode<DifferentiatorValue>* left, TreeNode<DifferentiatorValue>* right) {

    TreeNode<DifferentiatorValue>* new_node = NULL;
    CreateNode<DifferentiatorValue>(&new_node, &diff_value);

    LinkNodes<DifferentiatorValue>(new_node, left,  LEFT_SIDE);
    LinkNodes<DifferentiatorValue>(new_node, right, RIGHT_SIDE);

    return new_node;
}
