#include <stdio.h>
#include <cmath>

#include "diff.h"

int main() {
    // sin(15*x^3) + cos(20*x)^3

    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    DiffTreeInit(&tree, {});
    ReplaceNodes(&tree, &(tree.root), GetG("x - 0", &p));
    OpenDump(&tree);
    SimplifyTree(&tree);
    OpenDump(&tree);
    // ReplaceNodes(&tree, &(tree.root), GetG("0 - x", &p));
    // OpenDump(&tree);
    // SimplifyTree(&tree);
    // OpenDump(&tree);
    // ReplaceNodes(&tree, &(tree.root), GetG("x - 1", &p));
    // OpenDump(&tree);
    // SimplifyTree(&tree);
    // OpenDump(&tree);
    // ReplaceNodes(&tree, &(tree.root), GetG("1 - x", &p));
    // OpenDump(&tree);
    // SimplifyTree(&tree);
    // OpenDump(&tree);
    // ReplaceNodes(&tree, &(tree.root), GetG("x - (0 - 1)", &p));
    // OpenDump(&tree);
    // SimplifyTree(&tree);
    // OpenDump(&tree);
    // ReplaceNodes(&tree, &(tree.root), GetG("(0 - 1) - x", &p));
    // OpenDump(&tree);
    // SimplifyTree(&tree);
    // OpenDump(&tree);

    TreeDtor(&tree);
}
