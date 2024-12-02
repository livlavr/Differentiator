#include <stdlib.h>
#include <string.h>

#include "custom_asserts.h"
#include "tree.h"
#include "diff_definitions.h"


#ifndef TREE_SPECIALIZATIONS_H_
#define TREE_SPECIALIZATIONS_H_

//FUNCTION DECLARATION-----------------------------------------------------------------------

template <>
TreeErrors TreeInit<DifferentiatorValue>(Tree<DifferentiatorValue>* tree, DifferentiatorValue diff_value) {
    check_expression(tree, NODE_POINTER_IS_NULL);

    tree->error           = NO_TREE_ERRORS;
    tree->root            = NULL;
    tree->dump_svg_file   = NULL;
    tree->dump_html_file  = NULL;
    CreateNode<DifferentiatorValue>(&(tree->root), diff_value);
    SetDumpFile(tree);

    return NO_TREE_ERRORS;
}

template <>
TreeErrors AddNode<DifferentiatorValue>(TreeNode<DifferentiatorValue>* node, DifferentiatorValue diff_value, int connection_side) {
    check_expression(node, NODE_POINTER_IS_NULL);

    TreeNode<DifferentiatorValue>* new_node = NULL;
    CreateNode(&new_node, diff_value          );
    LinkNodes (node, new_node, connection_side);

    return NO_TREE_ERRORS;
}

template <>
inline TreeErrors CreateNode<DifferentiatorValue>(TreeNode<DifferentiatorValue>** node, DifferentiatorValue diff_value) {
    check_expression(node, NODE_POINTER_IS_NULL);

    *node = (TreeNode<DifferentiatorValue>*)calloc(1, sizeof(TreeNode<DifferentiatorValue>));
    warning(*node, NODE_CALLOC_ERROR);

    (*node)->value          = diff_value;
    (*node)->error          = NO_TREE_ERRORS;
    (*node)->number_of_kids = CHILD_FREE;
    (*node)->left           = NULL;
    (*node)->right          = NULL;
    (*node)->parent         = NULL;

    return NO_TREE_ERRORS;
}

//DEFINES------------------------------------------------------------------------------------

//PREORDER_PRINT
#define PreorderPrintTree_(node_ptr) \
    PrintTree(node_ptr);             \
    printf("\n")

//-------------------------------------------------------------------------------------------

#endif
