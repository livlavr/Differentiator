#ifndef DIFF_H_
#define DIFF_H_

#include "diff_definitions.h"
#include "diff_dump_specializations.h"
#include "diff_tree_specializations.h"
#include "simplifier.h"
#include "diff_DSL.h"
#include "diffIO.h"

#ifndef NDEBUG
    #define WriteIfDebug(expression) expression
#else
    #define WriteIfDebug(expression)
#endif

#endif
