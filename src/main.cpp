#include <stdio.h>

#include "diff.h"

int main() {
    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("6 * (7^sqrt(2) / (5+1))", &p);
    // tree.root = GetG("2", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2*2", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2*sqrt(2)", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2^sqrt(2)*2 + 2 + (5 * sin(6*3)^cos(15)*ln(2)^exp(15) - 3*exp(sin(16)))", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2^sqrt(2)*2 + 2 + (5 * sin(6*3)^cos(15)*ln(2)^exp(15) - 3*exp(sin(16)))", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2^sqrt(2)*2 + 2 + (5 * sin(6*3)^cos(15)*ln(2)^exp(15) - 3*exp(sin(16)))", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2^sqrt(2)*2 + 2 + (5 * sin(6*3)^cos(15)*ln(2)^exp(15) - 3*exp(sin(16)))", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = GetG("2^sqrt(2)*2 + 2 + (5 * sin(6*3)^cos(15)*ln(2)^exp(15) - 3*exp(sin(16)))", &p);
    // Dump(tree);
    // TreeDtor(&tree);
    // p = 0;
    // TreeInit(&tree, DifferentiatorValue {});
    tree.root = GetG("2^sqrt(2)*2 + 2 + (5 * sin(6*3)^cos(15)*ln(2)^exp(15) - 3*exp(sin(16)))", &p);
    Dump(tree);
    TreeDtor(&tree);
}

// int main() {
    // Tree<DifferentiatorValue> tree = {};
    // TreeInit(&tree, DifferentiatorValue {});
    // tree.root = Div(Mul(Num(3), Var(0)), Add(Sub(Num(1000), Mul(Num(7), Var(0))), Num(15)));
    // Dump(tree);
    // TreeDtor(&tree);
// }
