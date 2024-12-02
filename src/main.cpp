#include <stdio.h>

#include "diff.h"

int main() {
    Tree<DifferentiatorValue>* tree = NULL;
    TreeInit<DifferentiatorValue>(tree, DifferentiatorValue {.type = operation, .value = ADD});
}
