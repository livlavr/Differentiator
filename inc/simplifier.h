#ifndef SIMPLIFIER_H_
#define SIMPLIFIER_H_

#include "diff.h"
#include "tree.h"

TYPE_OF_ERROR SimplifyTree         (Tree<DifferentiatorValue>* tree);
TYPE_OF_ERROR RecursiveSimplifyTree(Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node,
                                    size_t* simplifications_number);
TreeNode<DifferentiatorValue>* CopySubtree(TreeNode<DifferentiatorValue>* node);
TYPE_OF_ERROR ReplaceNodes         (Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node_before,
                                    TreeNode<DifferentiatorValue>* node_after);
bool IsEqual(double first_value, double second_value, double eps);

#define SimplifyOperation()

//TODO maybe add only in cpp file
#define ReplaceSubtree(side, new_node)\
    TreeNode<DifferentiatorValue>* parent_node = (*node_before)->parent;\
    DestroySubtree(node_before);\
    LinkNodes(parent_node, new_node, side)

#define SimplifyTwoArgsOperation(operator)\
    result = left_value operator right_value;\
    ReplaceNodes(tree, node, Num(result));\
    break

#define SimplifyOneArgOperation(operator)\
    result = operator(left_value);\
    ReplaceNodes(tree, node, Num(result));\
    break

#define SimplifyPow()\
    result = pow(left_value, right_value);\
    ReplaceNodes(tree, node, Num(result));\
    break

#define EvalTwoArgsOperation(operation) \
    double result = 0;\
    result = (*node)->left->value.data.double_value operation (*node)->right->value.data.double_value;\
    ReplaceNodes(tree, node, Num(result))

#define EvalFunction(function) \
    double result = 0;\
    result = function((*node)->left->value.data.double_value);\
    ReplaceNodes(tree, node, Num(result))

#define  D(x) RecursiveSubtreeDerivation(tree, x)

#define CP(x) CopySubtree(x)


#endif
