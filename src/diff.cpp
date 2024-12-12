#include <stdio.h>
#include <math.h>

#include "diff.h"
#include "tree.h"

static const int ROOT_NODE = 0;

TYPE_OF_ERROR DiffTreeInit(Tree<DifferentiatorValue>* tree, DifferentiatorValue root_value) {
    TreeInit(tree, &root_value);

    return SUCCESS;
}

TreeNode<DifferentiatorValue>* CreateDiffNode(DifferentiatorValue diff_value,
    TreeNode<DifferentiatorValue>* left, TreeNode<DifferentiatorValue>* right) {

    TreeNode<DifferentiatorValue>* new_node = NULL;
    CreateNode<DifferentiatorValue>(&new_node, &diff_value);

    if(left)  LinkNodes<DifferentiatorValue>(new_node, left,  LEFT_SIDE);
    if(right) LinkNodes<DifferentiatorValue>(new_node, right, RIGHT_SIDE);

    return new_node;
}

TYPE_OF_ERROR SimplifyTree(Tree<DifferentiatorValue>* tree) {
    size_t simplifications_number = 0;
    do {
        simplifications_number = 0;
        RecursiveSimplifyTree(tree, &(tree->root), &simplifications_number);
        TreeDump(tree);
    }while(simplifications_number != 0);

    return SUCCESS;
}

TYPE_OF_ERROR RecursiveSimplifyTree(Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node,
                                    size_t* simplifications_number) {
    check_expression(simplifications_number, POINTER_IS_NULL);
    if(!(*node)) return SUCCESS;

    RecursiveSimplifyTree(tree, &(*node)->left,  simplifications_number);
    RecursiveSimplifyTree(tree, &(*node)->right, simplifications_number);

    if(((*node))->value.type == operation) {
        double result = 0;
        if((*node)->right) {
            if(((*node)->left->value.type == (*node)->right->value.type) && ((*node)->left->value.type == number)) {
                double left_value  = (*node)->left->value.data.double_value;
                double right_value = (*node)->right->value.data.double_value;
                *simplifications_number++;
                switch((*node)->value.data.operation) {
                    case ADD:
                        SimplifyTwoArgumentsOperation(+);
                    case SUB:
                        SimplifyTwoArgumentsOperation(-);
                    case MUL:
                        SimplifyTwoArgumentsOperation(*);
                    case DIV:
                        SimplifyTwoArgumentsOperation(/);
                    case DEG:
                        SimplifyPow();
                    case UNDEF: default:
                        warning(false, PROGRAM_ERROR);
                }
            }
            else if((*node)->left->value.type == number || (*node)->left->value.type == number) {
                if((*node)->left->value.type == number) {
                    if(abs((*node)->left->value.data.double_value) < EPS) {
                        switch((*node)->value.data.operation) {
                            case ADD:
                                ReplaceNodes(tree, node, CopySubtree((*node)->right));
                                break;
                            case MUL: case DIV: case DEG:
                                ReplaceNodes(tree, node, Num(0));
                                break;
                            case UNDEF: default:
                                warning(false, PROGRAM_ERROR);
                        }
                    }
                    else if(abs((*node)->left->value.data.double_value - 1) < EPS) { //TODO isequal() function
                        switch((*node)->value.data.operation) {
                            case MUL:
                                ReplaceNodes(tree, node, CopySubtree((*node)->left));
                                break;
                            case DEG:
                                ReplaceNodes(tree, node, Num(1));
                                break;
                            case UNDEF: default:
                                warning(false, PROGRAM_ERROR);
                        }
                    }
                }
                else if((*node)->right->value.type == number) {
                    if(abs((*node)->right->value.data.double_value) < EPS) {
                        switch((*node)->value.data.operation) {
                            case ADD: case SUB:
                                ReplaceNodes(tree, node, CopySubtree((*node)->left));
                                break;
                            case MUL:
                                ReplaceNodes(tree, node, Num(0));
                                break;
                            case DEG:
                                ReplaceNodes(tree, node, Num(1));
                                break;
                            case UNDEF: default:
                                warning(false, PROGRAM_ERROR);
                        }
                    }
                    else if(abs((*node)->right->value.data.double_value - 1) < EPS) { //TODO isequal() function
                        switch((*node)->value.data.operation) {
                            case MUL: case DIV: case DEG:
                                ReplaceNodes(tree, node, CopySubtree((*node)->left));
                                break;
                            case UNDEF: default:
                                warning(false, PROGRAM_ERROR);
                        }
                    }
                    else if(abs((*node)->right->value.data.double_value - (-1)) < EPS) {
                        TreeNode<DifferentiatorValue>* left_subtree_copy = CopySubtree((*node)->left);
                        switch((*node)->value.data.operation) {
                            case DIV:
                                ReplaceNodes(tree, node, Mul(Num(-1), CopySubtree((*node)->left)));
                                break;
                            case DEG:
                                ReplaceNodes(tree, node, Div(Num(1), (*node)->left));
                                break;
                            case UNDEF: default:
                                warning(false, PROGRAM_ERROR);
                        }
                    }
                }
            }
        }
        else if((*node)->left->value.type == number){
            double left_value  = (*node)->left->value.data.double_value;
            *simplifications_number++;
            switch((*node)->value.data.operation) {
                case SQRT:
                    SimplifyOneArgumentOperation(sqrt);
                case SIN:
                    SimplifyOneArgumentOperation(sin);
                case COS:
                    SimplifyOneArgumentOperation(cos);
                case LN:
                    SimplifyOneArgumentOperation(log2);
                case EXP:
                    SimplifyOneArgumentOperation(exp);
                case UNDEF:
                default:
                    warning(false, PROGRAM_ERROR);
            }
        }
    }
    return SUCCESS;
}

TreeNode<DifferentiatorValue>* CopySubtree(TreeNode<DifferentiatorValue>* node) {
    if(!node) return NULL;

    return CreateDiffNode({.type = node->value.type, .data = node->value.data},
                   CopySubtree(node->left), CopySubtree(node->right));

}

//TODO in Tree.h
TYPE_OF_ERROR ReplaceNodes(Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>** node_before,
                           TreeNode<DifferentiatorValue>* node_after) {
    check_expression(*node_before, POINTER_IS_NULL);
    check_expression(node_after,   POINTER_IS_NULL);

    if((*node_before)->parent) {
        if((*node_before)->parent->left == *node_before) {
            ReplaceSubtree(LEFT_SIDE);
        }
        else {
            ReplaceSubtree(RIGHT_SIDE);
        }
    }
    else {
        DestroySubtree(node_before);
        tree->root = node_after;
    }

    return SUCCESS;
}

TYPE_OF_ERROR DestroySubtree(TreeNode<DifferentiatorValue>** node) {
    if(!(*node)) return SUCCESS;

    DestroySubtree(&((*node)->left));
    DestroySubtree(&((*node)->right));

    DestroySingleNode(node);

    return SUCCESS;
}

TYPE_OF_ERROR DestroySingleNode(TreeNode<DifferentiatorValue>** node) {
    check_expression(*node, POINTER_IS_NULL);

    free(*node);
    *node = NULL;

    return SUCCESS;
}
