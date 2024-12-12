#ifndef DIFF_DSL_H_
#define DIFF_DSL_H_

#include "diff.h"

#define D(x) Differentiate(x)
#define CP(x) CopySubtree(x)

#define  Num(amount     ) CreateDiffNode({.type = number   , .data = {.double_value   = amount   }}, NULL, NULL )
#define  Var(var_index  ) CreateDiffNode({.type = variable , .data = {.variable_index = var_index}}, NULL, NULL )
#define  Add(left, right) CreateDiffNode({.type = operation, .data = {.operation      = ADD      }}, left, right)
#define  Sub(left, right) CreateDiffNode({.type = operation, .data = {.operation      = SUB      }}, left, right)
#define  Mul(left, right) CreateDiffNode({.type = operation, .data = {.operation      = MUL      }}, left, right)
#define  Div(left, right) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, left, right)
#define  Deg(left, right) CreateDiffNode({.type = operation, .data = {.operation      = DEG      }}, left, right)
#define Sqrt(left       ) CreateDiffNode({.type = operation, .data = {.operation      = SQRT     }}, left, NULL )
#define  Sin(left       ) CreateDiffNode({.type = operation, .data = {.operation      = SIN      }}, left, NULL )
#define  Cos(left       ) CreateDiffNode({.type = operation, .data = {.operation      = COS      }}, left, NULL )
#define   Ln(left       ) CreateDiffNode({.type = operation, .data = {.operation      = LN       }}, left, NULL )
#define  Exp(left       ) CreateDiffNode({.type = operation, .data = {.operation      = EXP      }}, left, NULL )

#define  DiffNum(amount     ) CreateDiffNode({.type = number   , .data = {.double_value   = 0        }}, NULL, NULL                                                                   )
#define  DiffVar(var_index  ) CreateDiffNode({.type = variable , .data = {.variable_index = 1        }}, NULL, NULL                                                                   )
#define  DiffAdd(left, right) CreateDiffNode({.type = operation, .data = {.operation      = ADD      }}, D(left), D(right)                                                            )
#define  DiffSub(left, right) CreateDiffNode({.type = operation, .data = {.operation      = SUB      }}, D(left), D(right)                                                            )
#define  DiffMul(left, right) CreateDiffNode({.type = operation, .data = {.operation      = ADD      }}, Mul(D(left), CP(right)), Mul(CP(left), D(right))                             )
#define  DiffDiv(left, right) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, Sub(Mul(D(left), CP(right)), Mul(CP(left), D(right))), Deg(CP(right), Num(2)))
#define  DiffDeg(left, right) CreateDiffNode({.type = operation, .data = {.operation      = MUL      }}, CP(right), Deg(CP(left), Sub(CP(right), Num(1)))                             )
#define DiffSqrt(left       ) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, Num(1), Mul(Num(2)), CP(left)                                                )
#define  DiffSin(left       ) CreateDiffNode({.type = operation, .data = {.operation      = COS      }}, left, NULL                                                                   )
#define  DiffCos(left       ) CreateDiffNode({.type = operation, .data = {.operation      = MUL      }}, Num(-1), Sin(left)                                                           )
#define   DiffLn(left       ) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, Num(1), CP(left)                                                             )
#define  DiffExp(left       ) CreateDiffNode({.type = operation, .data = {.operation      = operation}}, left, NULL                                                                   )

#endif
