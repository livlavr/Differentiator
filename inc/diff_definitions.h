#ifndef DIFF_DEFINITIONS_H_
#define DIFF_DEFINITIONS_H_

#include <stdio.h>
#include <math.h>

#include "tree.h"

const char* operation_symbol[] = {"+", "-", "*", "/"};
const char* variable_table  [] = {"x", "y", "z"}; //TODO change to template struct Buffer<...>

enum DifferentiatorError {

};

enum NodeType{
    number    = 0,
    variable  = 1,
    operation = 1 << 1,
};

enum Operations {
    ADD = 0,
    SUB = 1,
    MUL = 2,
    DIV = 3,
};

union NodeValue{
    double     double_value = NAN;
    size_t     variable_index;
    Operations operation;
};

struct DifferentiatorValue{
    NodeType   type;
    NodeValue  data = {.double_value = NAN};
};

// struct DifferentiatorNode{
//     DifferentiatorNode* parent = NULL;
//     DifferentiatorNode* left   = NULL;
//     DifferentiatorNode* right  = NULL;
//     NodeType            type;
//     NodeValue*          value;
// };

// template <>
// struct TreeNode<DiffValue> {
//     TreeNode<DiffValue>* parent;
//     TreeNode<DiffValue>* left;
//     TreeNode<DiffValue>* right;
//     TypeOfNode          type;
//     NodeValue           value;
//     int                 number_of_kids;
// };

#endif
