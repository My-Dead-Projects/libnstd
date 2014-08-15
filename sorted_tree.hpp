#ifndef libnstd_sorted_tree_hpp
#define libnstd_sorted_tree_hpp

#include "tree_node.hpp"

namespace nstd {
    
    template <class T, class C>
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
nstd::tree_node_ptr<T> & nstd::sorted_tree<T, C>::find(T const& value, nstd::tree_node_ptr<T> & node) {
    
}

#endif
