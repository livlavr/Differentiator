#ifndef DIFF_H_
#define DIFF_H_

#include "diff_definitions.h"
#include "diff_dump_specializations.h"
#include "diff_tree_specializations.h"
#include "simplifier.h"
#include "diff_DSL.h"
#include "diffIO.h"

TYPE_OF_ERROR DerivateTree(Tree<DifferentiatorValue>* tree);
TreeNode<DifferentiatorValue>* RecursiveSubtreeDerivation(Tree<DifferentiatorValue>* tree, TreeNode<DifferentiatorValue>* node);

#ifndef NDEBUG
    #define WriteIfDebug(expression) expression
#else
    #define WriteIfDebug(expression)
#endif

#endif
