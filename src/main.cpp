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
    ReplaceNodes(&tree, &(tree.root), GetG("cos(15*x^3)*45*x^2 - 3*cos(20*x)^2*20*sin(20^x)", &p));
    TreeDump(&tree);
    SimplifyTree(&tree);
    DerivateTree(&tree);
    // TreeDump(&tree);
    SimplifyTree(&tree);
    // TreeDump(&tree);
    // OpenDump(&tree);
    EndLatexFile();
    TreeDtor(&tree);
}
