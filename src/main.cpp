#include <stdio.h>

#include "diff.h"

int main() {
    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    TreeInit(&tree, DifferentiatorValue {});
    tree.root = GetG("6 * (7 + 15 / (5+1))", &p);
    Dump(tree);
}

// int main() {
//     // Tree<DifferentiatorValue> tree = {};
//     // TreeInit(&tree, DifferentiatorValue {});
//     // tree.root = Div(Mul(Num(3), Var(0)), Add(Sub(Num(1000), Mul(Num(7), Var(0))), Num(15)));
//     // Dump(tree);
//     // TreeDtor(&tree);
// }
