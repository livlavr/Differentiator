#include <stdio.h>
#include <cmath>

#include "tree.h"
#include "tree_dump.h"
#include "diff_definitions.h"
#include "diff_dump_specializations.h"
#include "diff_tree_specializations.h"
#include "simplifier.h"
#include "diffIO.h"
#include "latex_output.h"
#include "diff.h"

int main() {
    // // cos(15*x^3)*45*x^2 - 3*cos(20*x)^2*20*sin(20^x)
    size_t p = 0;
    Tree<DifferentiatorValue> tree = {};
    DiffTreeInit(&tree, {});
    BeginLatexFile();
    ReplaceNodes(&tree, &(tree.root), GetEquation("3*cos(20*x)^2*20*sin(20^x)", &p));
    TreeDump(&tree);
    SimplifyTree(&tree);
    TreeDump(&tree);
    DerivateTree(&tree);
    TreeDump(&tree);
    SimplifyTree(&tree);
    EndLatexFile();
    OpenDump(&tree);
    TreeDtor(&tree);
}
