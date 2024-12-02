#include <stdio.h>

#include "tree_specializations.h"
#include "diff_definitions.h"
#include "dump_specializations.h"

int main() {
    Tree<DifferentiatorValue> tree = {};
    TreeInit<DifferentiatorValue>(&tree, DifferentiatorValue {.type = operation, .data = ADD});
    TreeDump(&tree);
    OpenDump(&tree);
    TreeDtor(&tree);
}
