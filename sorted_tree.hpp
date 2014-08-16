#ifndef libnstd_sorted_tree_hpp
#define libnstd_sorted_tree_hpp

#include "tree_node.hpp"
#include <functional>

namespace nstd {
    
    template <class T, class C = std::less<T>>
    class sorted_tree {
    public:
        tree_node_ptr<T> root_node;
        
        tree_node_ptr<T> & find(T const&);
        tree_node_ptr<T> & find(T const&, tree_node_ptr<T> &);
    };
    
}



template <class T, class C>
nstd::tree_node_ptr<T> & nstd::sorted_tree<T, C>::find(T const& value) {
    return find(value, root_node);
}

template <class T, class C>
nstd::tree_node_ptr<T> &
nstd::sorted_tree<T, C>::find(T const& value,
                              nstd::tree_node_ptr<T> & node) {
    if (node) {
        C compare;
        if (compare(value, node->value)) {
            return find(value, node->lnode);
        } else if (compare(node->value, value)) {
            return find(value, node->rnode);
        }
    }
    return node;
}

#endif
