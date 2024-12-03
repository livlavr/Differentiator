#include <stdio.h>

#include "diff.h"

TreeNode<DifferentiatorValue>* CreateDiffNode(DifferentiatorValue diff_value,
    TreeNode<DifferentiatorValue>* left, TreeNode<DifferentiatorValue>*    right) {

    TreeNode<DifferentiatorValue>* new_node = NULL;
    CreateNode<DifferentiatorValue>(&new_node, DifferentiatorValue {.type = diff_value.type, .data = diff_value.data});

    LinkNodes<DifferentiatorValue>(new_node, left,  LEFT_SIDE);
    LinkNodes<DifferentiatorValue>(new_node, right, RIGHT_SIDE);

    return new_node;
}
