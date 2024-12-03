#ifndef DIFF_DSL_H_
#define DIFF_DSL_H_

#include "diff.h"

#define _Num(amount     ) CreateDiffNode({.type = number   , .data = {.double_value   = amount   }}, NULL, NULL)
#define _Var(var_index  ) CreateDiffNode({.type = variable , .data = {.variable_index = var_index}}, NULL, NULL)
#define _Add(left, right) CreateDiffNode({.type = operation, .data = {.operation      = ADD      }}, left, right)
#define _Sub(left, right) CreateDiffNode({.type = operation, .data = {.operation      = SUB      }}, left, right)
#define _Mul(left, right) CreateDiffNode({.type = operation, .data = {.operation      = MUL      }}, left, right)
#define _Div(left, right) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, left, right)

#endif
