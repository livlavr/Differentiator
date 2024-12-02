#ifndef DUMP_SPECIALIZATIONS_H_
#define DUMP_SPECIALIZATIONS_H_

#include "tree.h"
#include "tree_dump.h"
#include "diff_definitions.h"

template <>
inline TYPE_OF_ERROR ProcessNode<DifferentiatorValue>(TreeNode<DifferentiatorValue>* node, FILE* dot_file) {
    check_expression(dot_file,  POINTER_IS_NULL);
    check_expression(node,      POINTER_IS_NULL);

    switch(node->value.type) {
        case number   :
            break;
        case variable :
            break;
        case operation:
            break;
        default:
            color_printf(RED_COLOR, )
    }

    return SUCCESS;
}

#define _WriteOperationDescriptionToStream()\
    fprintf(dot_file, "P%p [style = \"filled, rounded\", fillcolor=\"yellow:magenta\" gradientangle=270,"\
          "label=\" {Node = [ %p ] | Parent = [ %p ] | Number of kids = %d |"\
          " %s | { <l> LEFT = [ %p ] | <r> RIGHT = [ %p ]}}\" ];\n",\
           node, node, node->parent, node->error, node->number_of_kids, operation_symbol[(size_t)(node->value.operation)], node->left, node->right);\

#define _WriteVariableDescriptionToStream ()\
    fprintf(dot_file, "P%p [style = \"filled, rounded\", fillcolor=\"yellow:magenta\" gradientangle=270,"\
          "label=\" {Node = [ %p ] | Parent = [ %p ] | Number of kids = %d |"\
          " %s | { <l> LEFT = [ %p ] | <r> RIGHT = [ %p ]}}\" ];\n",\
           node, node, node->parent, node->error, node->number_of_kids, variable_table[(size_t)(node->value.variable_index)], node->left, node->right);\

#define _WriteNumberDescriptionToStream   ()\
    fprintf(dot_file, "P%p [style = \"filled, rounded\", fillcolor=\"yellow:magenta\" gradientangle=270,"\
          "label=\" {Node = [ %p ] | Parent = [ %p ] | Number of kids = %d |"\
          " %.3lf | { <l> LEFT = [ %p ] | <r> RIGHT = [ %p ]}}\" ];\n",\
           node, node, node->parent, node->error, node->number_of_kids, operation_symbol[(size_t)(node->value.double_value)], node->left, node->right);\
#endif
