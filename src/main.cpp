#include <stdio.h>

#include "diff.h"

int main() {
    Tree<DifferentiatorValue> tree = {};
    TreeInit(&tree, DifferentiatorValue {});
    tree.root = Div(Mul(Num(3), Var(0)), Add(Sub(Num(1000), Mul(Num(7), Var(0))), Num(15)));
    Dump(tree);
    TreeDtor(&tree);
}
