#include <stdio.h>

#include "diff.h"
#include "tree.h"

TYPE_OF_ERROR DerivateTree(Tree<DifferentiatorValue>* tree) {
    check_expression(tree, POINTER_IS_NULL);

    Tree<DifferentiatorValue> derivated_tree = {};
    DiffTreeInit(&derivated_tree, {});
    ReplaceNodes(tree, &(derivated_tree.root), RecursiveSubtreeDerivation(tree, tree->root));

    return SUCCESS;
}

TreeNode<DifferentiatorValue>* RecursiveSubtreeDerivation(Tree<DifferentiatorValue>* tree,
                                         TreeNode<DifferentiatorValue>* node) {
    if(!node) return NULL;

    TreeNode<DifferentiatorValue>* diff_result = NULL;

    if(node->value.type == variable) {
        diff_result = Num(1);
    }
    else if(node->value.type == number) {
        diff_result = Num(0);
    }

    #define OPERATOR(OP, OP_SIGN, EVAL_VALUE, LEFT_ZERO_SIMPLIFICATION,      RIGHT_ZERO_SIMPLIFICATION,\
                                              LEFT_ONE_SIMPLIFICATION,       RIGHT_ONE_SIMPLIFICATION,\
                                              LEFT_MINUS_ONE_SIMPLIFICATION, RIGHT_MINUS_ONE_SIMPLIFICATION,\
                                              DIFFERENTIATED, ...)\
        if(node->value.type == operation && node->value.data.operation == OP) {\
            DIFFERENTIATED;\
        }

    #include "codegen.def"

    return diff_result;
}
