#include <stdio.h>
#include <math.h>

#include "diff.h"
#include "tree.h"

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

    if(((*node))->value.type == operation) {
        double result = 0;
        if((*node)->right) {
            if(((*node)->left->value.type == (*node)->right->value.type) && ((*node)->left->value.type == number)) {
                double left_value  = (*node)->left->value.data.double_value;
                double right_value = (*node)->right->value.data.double_value;
                (*simplifications_number)++;
                switch((*node)->value.data.operation) {
                    case ADD:
                        SimplifyTwoArgsOperation(+);
                    case SUB:
                        SimplifyTwoArgsOperation(-);
                    case MUL:
                        SimplifyTwoArgsOperation(*);
                    case DIV:
                        SimplifyTwoArgsOperation(/);
                    case POW:
                        SimplifyPow();
                    case UNDEF: default:
                        warning(false, PROGRAM_ERROR);
                }
            }
            else if(((*node)->left->value.type == number) || ((*node)->right->value.type == number)) {
                if((*node)->left->value.type == number) {
                    if(IsEqual((*node)->left->value.data.double_value, 0, EPS)) {
                        (*simplifications_number)++;
                        switch((*node)->value.data.operation) {
                            case ADD:
                                ReplaceNodes(tree, node, CopySubtree((*node)->right));
                                break;
                            case MUL: case DIV: case POW:
                                ReplaceNodes(tree, node, Num(0));
                                break;
                            case UNDEF: default:
                                warning(false, PROGRAM_ERROR);
                        }
                    }
                    else if(IsEqual((*node)->left->value.data.double_value, 1, EPS)) { //TODO isequal() function
                        switch((*node)->value.data.operation) {
                            case MUL:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, CopySubtree((*node)->right));
                                break;
                            case POW:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, Num(1));
                                break;
                            case UNDEF:
                                warning(false, PROGRAM_ERROR);
                            default:
                                break;
                        }
                    }
                }
                else if((*node)->right->value.type == number) {
                    if(fabs((*node)->right->value.data.double_value) < EPS) {
                        switch((*node)->value.data.operation) {
                            case ADD: case SUB:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, CopySubtree((*node)->left));
                                break;
                            case MUL:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, Num(0));
                                break;
                            case POW:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, Num(1));
                                break;
                            case UNDEF:
                                warning(false, PROGRAM_ERROR);
                            default:
                                break;
                        }
                    }
                    else if(IsEqual((*node)->right->value.data.double_value, 1, EPS)) {
                        switch((*node)->value.data.operation) {
                            case MUL: case DIV: case POW:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, CopySubtree((*node)->left));
                                break;
                            case UNDEF:
                                warning(false, PROGRAM_ERROR);
                            default:
                                break;
                        }
                    }
                    else if(IsEqual((*node)->right->value.data.double_value, -1, EPS)) {
                        switch((*node)->value.data.operation) {
                            case DIV:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, Mul(Num(-1), CopySubtree((*node)->left)));
                                break;
                            case POW:
                                (*simplifications_number)++;
                                ReplaceNodes(tree, node, Div(Num(1), CopySubtree((*node)->left)));
                                break;
                            case UNDEF:
                                warning(false, PROGRAM_ERROR);
                            default:
                                break;
                        }
                    }
                }
            }
        }
        else if((*node)->left->value.type == number){
            double left_value  = (*node)->left->value.data.double_value;
            (*simplifications_number)++;
            switch((*node)->value.data.operation) {
                case SQRT:
                    SimplifyOneArgOperation(sqrt);
                case SIN:
                    SimplifyOneArgOperation(sin);
                case COS:
                    SimplifyOneArgOperation(cos);
                case LN:
                    SimplifyOneArgOperation(log2);
                case EXP:
                    SimplifyOneArgOperation(exp);
                case UNDEF:
                default:
                    warning(false, PROGRAM_ERROR);
            }
        }
    }

    return SUCCESS;
}

TYPE_OF_ERROR CollapseConstant()
