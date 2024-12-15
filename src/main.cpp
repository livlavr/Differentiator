#include <stdio.h>
#include <cmath>

#include "diff.h"

int main() {
    // sin(15*x^3) + cos(20*x)^3
    // cos(15*x^3)*45*x^2 - 3*cos(20*x)^2*20*sin(20^x)
    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    DiffTreeInit(&tree, {});
    BeginLatexFile();
    ReplaceNodes(&tree, &(tree.root), GetG("sin(15*x^3) + cos(20*x)^3", &p));
    TreeDump(&tree);
    SimplifyTree(&tree);
    TreeDump(&tree);
    DerivateTree(&tree);
    TreeDump(&tree);
    SimplifyTree(&tree);
    EndLatexFile();
    TreeDtor(&tree);
}
