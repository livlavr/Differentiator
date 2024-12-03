#ifndef DIFF_DUMP_SPECIALIZATIONS_H_
#define DIFF_DUMP_SPECIALIZATIONS_H_

#include "tree.h"
#include "tree_dump.h"
#include "diff.h"
#include "debug_macros.h"

#define _WriteOperationDescriptionToStream()                                                                                                          \
    fprintf(dot_file, "P%p [style = \"filled, rounded\", fillcolor=\"peachpuff:red\" gradientangle=270,"                                              \
          "label=\" {Node = [ %p ] | Parent = [ %p ] | Number of kids = %d |"                                                                          \
          "[ %s ] | { <l> LEFT = [ %p ] | <r> RIGHT = [ %p ]}}\" ];\n",                                                                                   \
           node, node, node->parent, node->number_of_kids, operation_symbol[(size_t)(node->value.data.operation)], node->left, node->right)    \

#define _WriteVariableDescriptionToStream()  \
    fprintf(dot_file, "P%p [style = \"filled, rounded\", fillcolor=\"violet:darkcyan\""                                              \
          "label=\" {Node = [ %p ] | Parent = [ %p ] | Number of kids = %d |"                                                                          \
          "[ %s ] | { <l> LEFT = [ %p ] | <r> RIGHT = [ %p ]}}\" ];\n",                                                                                   \
           node, node, node->parent, node->number_of_kids, variable_table[(size_t)(node->value.data.variable_index)], node->left, node->right) \

#define _WriteNumberDescriptionToStream()                                                                                                           \
    fprintf(dot_file, "P%p [style = \"filled, rounded\", fillcolor=\"yellow:magenta\" gradientangle=270,"                                              \
          "label=\" {Node = [ %p ] | Parent = [ %p ] | Number of kids = %d |"                                                                          \
          " [ %.1lf ] | { <l> LEFT = [ %p ] | <r> RIGHT = [ %p ]}}\" ];\n",                                                                                \
           node, node, node->parent, node->number_of_kids,                                                                                \
           node->value.data.double_value, node->left, node->right)                                                              \

template <>
inline TYPE_OF_ERROR ProcessNode<DifferentiatorValue>(TreeNode<DifferentiatorValue>* node, FILE* dot_file) {
    check_expression(dot_file,  POINTER_IS_NULL);
    check_expression(node,      POINTER_IS_NULL);

    switch(node->value.type) {
        case number   :
            _WriteNumberDescriptionToStream();

            break;
        case variable :
            _WriteVariableDescriptionToStream();
            break;
        case operation:
            _WriteOperationDescriptionToStream();
            break;
        default:
            color_printf(RED_COLOR, BOLD, "Error in value type choice\n");
            warning     (false, PROGRAM_ERROR);
    }

    return SUCCESS;
}

#endif
