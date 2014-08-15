#ifndef libnstd_tree_node_hpp
#define libnstd_tree_node_hpp

#include <memory>

namespace nstd {

    template <class T>
    class tree_node {
    public:
        T value;
        std::shared_ptr<tree_node<T>> lnode;
        std::shared_ptr<tree_node<T>> rnode;
        tree_node(const T&);
    };

    template <class T>
    using tree_node_ptr = std::shared_ptr<tree_node<T>>;
    
}



template <class T>
nstd::tree_node<T>::tree_node(const T& v) : value(v) {
    
}

#endif
