#include <stdio.h>

#include "diff.h"

int main() {
    Tree<DifferentiatorValue> tree = {};
    TreeInit(&tree, DifferentiatorValue {});
    // TreeInit<DifferentiatorValue>(&tree,            DifferentiatorValue {.type = operation, .data = {.operation      = ADD}});
    // AddNode<DifferentiatorValue> (tree.root,        DifferentiatorValue {.type = operation, .data = {.operation      = MUL}}, LEFT_SIDE);
    // AddNode<DifferentiatorValue> (tree.root,        DifferentiatorValue {.type = operation, .data = {.operation      = ADD}}, RIGHT_SIDE);
    // AddNode<DifferentiatorValue> (tree.root->left,  DifferentiatorValue {.type = variable,  .data = {.variable_index = 1}},   RIGHT_SIDE);
    // AddNode<DifferentiatorValue> (tree.root->right, DifferentiatorValue {.type = number,    .data = {.double_value   = 66.0}}, RIGHT_SIDE);
    tree.root = _Div(_Mul(_Num(3), _Var(0)), _Add(_Sub(_Num(1000), _Mul(_Num(7), _Var(0))), _Num(15)));
    TreeDump(&tree);
    OpenDump(&tree);
    TreeDtor(&tree);
}
