#include <stdio.h>
#include <math.h>

#include "diff.h"
#include "tree.h"

#define EvalTwoArgsOperation(operation) \
    double result = 0;\
    result = (*node)->left->value.data.double_value operation (*node)->right->value.data.double_value;\
    ReplaceNodes(tree, node, Num(result))

#define EvalFunction(function) \
    double result = 0;\
    result = function((*node)->left->value.data.double_value);\
    ReplaceNodes(tree, node, Num(result))

#define  D(x) RecursiveSubtreeDerivation(x)
#define CP(x) CopySubtree(x)

TYPE_OF_ERROR SimplifyTree(Tree<DifferentiatorValue>* tree) {
    size_t simplifications_number = 0;
    do {
        simplifications_number = 0;
        RecursiveSimplifyTree(tree, &(tree->root), &simplifications_number);
    }while(simplifications_number != 0);

    return SUCCESS;
}

TYPE_OF_ERROR RecursiveSimplifyTree(Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node,
                                    size_t* simplifications_number) {
    check_expression(simplifications_number, POINTER_IS_NULL);
    if(!(*node)) return SUCCESS;

    RecursiveSimplifyTree(tree, &(*node)->left,  simplifications_number);
    RecursiveSimplifyTree(tree, &(*node)->right, simplifications_number);

    #define OPERATOR(OP, OP_SIGN, EVAL_VALUE, LEFT_ZERO_SIMPLIFICATION,      RIGHT_ZERO_SIMPLIFICATION,\
                                              LEFT_ONE_SIMPLIFICATION,       RIGHT_ONE_SIMPLIFICATION,\
                                              LEFT_MINUS_ONE_SIMPLIFICATION, RIGHT_MINUS_ONE_SIMPLIFICATION,\
                                              ...)\
        if((*node)->value.type == operation && (*node)->value.data.operation == OP) {\
            if((*node)->right) {\
                if((*node)->left->value.type == number) {\
                    if((*node)->right->value.type == number) {\
                        EVAL_VALUE;\
                        TreeDump(tree);\
                    }\
                    else if(IsEqual((*node)->left->value.data.double_value,  0, EPS)) {\
                        LEFT_ZERO_SIMPLIFICATION;\
                        TreeDump(tree);\
                    }\
                    else if(IsEqual((*node)->left->value.data.double_value,  1, EPS)) {\
                        LEFT_ONE_SIMPLIFICATION;\
                        TreeDump(tree);\
                    }\
                    else if(IsEqual((*node)->left->value.data.double_value, -1, EPS)) {\
                        LEFT_MINUS_ONE_SIMPLIFICATION;\
                        TreeDump(tree);\
                    }\
                }\
                else if((*node)->right->value.type == number) {\
                    if(IsEqual((*node)->right->value.data.double_value,       0, EPS)) {\
                        RIGHT_ZERO_SIMPLIFICATION;\
                        TreeDump(tree);\
                    }\
                    else if(IsEqual((*node)->right->value.data.double_value,  1, EPS)) {\
                        RIGHT_ONE_SIMPLIFICATION;\
                        TreeDump(tree);\
                    }\
                    else if(IsEqual((*node)->right->value.data.double_value, -1, EPS)) {\
                        RIGHT_MINUS_ONE_SIMPLIFICATION;\
                        TreeDump(tree);\
                    }\
                }\
            }\
            else if((*node)->left->value.type == number) {\
                EVAL_VALUE;\
                TreeDump(tree);\
            }\
        }

    #include "codegen.def"

    return SUCCESS;
}
