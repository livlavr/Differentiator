#ifndef DIFF_SIMPLIFIER_H_
#define DIFF_SIMPLIFIER_H_

#include "diff.h"
#include "tree.h"

TYPE_OF_ERROR SimplifyTree         (Tree<DifferentiatorValue>* tree);
TYPE_OF_ERROR RecursiveSimplifyTree(Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node,
                                    size_t* simplifications_number);
TreeNode<DifferentiatorValue>* CopySubtree(TreeNode<DifferentiatorValue>* node);
TYPE_OF_ERROR ReplaceNodes         (Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node_before,
                                    TreeNode<DifferentiatorValue>* node_after);
bool IsEqual(double first_value, double second_value, double eps);

//TODO maybe add only in cpp file
#define ReplaceSubtree(side, new_node)\
    TreeNode<DifferentiatorValue>* parent_node = (*node_before)->parent;\
    DestroySubtree(node_before);\
    LinkNodes(parent_node, new_node, side)

#define SimplifyTwoArgumentsOperation(operator)\
    result = left_value operator right_value;\
    ReplaceNodes(tree, node, Num(result));\
    break

#define SimplifyOneArgumentOperation(operator)\
    result = operator(left_value);\
    ReplaceNodes(tree, node, Num(result));\
    break

#define SimplifyPow()\
    result = pow(left_value, right_value);\
    ReplaceNodes(tree, node, Num(result));\
    break

#endif
