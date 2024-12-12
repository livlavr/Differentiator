#include <stdio.h>
#include <cmath>

#include "diff.h"

int main() {
    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    Tree<DifferentiatorValue> tree2 = {};
    DiffTreeInit(&tree, {});
    ReplaceNodes(&tree, &(tree.root), GetG("(sin(x))^(0-1)", &p));
    TreeDump(&tree);
    SimplifyTree(&tree);
    TreeDump(&tree);
    OpenDump(&tree);

    // DiffTreeInit(&tree2, {});
    // ReplaceNodes(&tree2, &(tree2.root), CopySubtree(tree.root));
    // TreeDump(&tree2);
    // SimplifyTree(&tree2);
    // TreeDump(&tree2);
    // OpenDump(&tree2);

    TreeDtor(&tree);
    // TreeDtor(&tree2);
}
