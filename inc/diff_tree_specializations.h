#include <stdlib.h>
#include <string.h>

#include "custom_asserts.h"
#include "tree.h"
#include "diff.h"


#ifndef DIFF_TREE_SPECIALIZATIONS_H_
#define DIFF_TREE_SPECIALIZATIONS_H_

//FUNCTION DECLARATION-----------------------------------------------------------------------

template <>
inline TreeErrors TreeInit<DifferentiatorValue>(Tree<DifferentiatorValue>* tree, DifferentiatorValue diff_value) {
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
inline TreeErrors AddNode<DifferentiatorValue>(TreeNode<DifferentiatorValue>* node, DifferentiatorValue diff_value, int connection_side) {
    check_expression(node, NODE_POINTER_IS_NULL);

    TreeNode<DifferentiatorValue>* new_node = NULL;
    CreateNode(&new_node, diff_value          );
    LinkNodes (node, new_node, connection_side);

    return NO_TREE_ERRORS;
}

template <>
inline TreeErrors FindRepeats<DifferentiatorValue>(TreeNode<DifferentiatorValue>* parent, TreeNode<DifferentiatorValue>* child) {

    return NO_TREE_ERRORS;
}

#endif
