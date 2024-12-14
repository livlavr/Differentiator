#include <stdio.h>
#include <cmath>

#include "diff.h"

int main() {
    // sin(15*x^3) + cos(20*x)^3

    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    DiffTreeInit(&tree, {});
    ReplaceNodes(&tree, &(tree.root), GetG("", &p));
    TreeDump(&tree);
    SimplifyTree(&tree);
    OpenDump(&tree);

    TreeDtor(&tree);
}
