#ifndef libnstd_sorted_tree_hpp
#define libnstd_sorted_tree_hpp

#include "tree_node.hpp"
#include <functional>

namespace nstd {
    
    template <class T, class C = std::less<T>>
    class sorted_tree_iterator {
        
        tree_node_ptr<T> node;
        
    public:
        
        sorted_tree_iterator(tree_node_ptr<T>);
        explicit operator bool()const;
        
    };
    
    template <class T, class C = std::less<T>>
    class sorted_tree {
        
        tree_node_ptr<T> root_node;
        tree_node_ptr<T> & find(T const&, tree_node_ptr<T> &);
        
    public:
        
        sorted_tree_iterator<T> find(T const&);
        
    };
    
}



template <class T, class C>
nstd::sorted_tree_iterator<T> nstd::sorted_tree<T, C>::find(T const& value) {
    return nstd::sorted_tree_iterator<T>(find(value, root_node));
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

template <class T, class C>
nstd::sorted_tree_iterator<T, C>::
sorted_tree_iterator(nstd::tree_node_ptr<T> n) : node(n) {
    
}

template <class T, class C>
nstd::sorted_tree_iterator<T, C>::operator bool()const {
    return bool(node);
}

#endif
