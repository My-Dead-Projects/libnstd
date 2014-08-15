
#include "Catch/single_include/catch.hpp"

#include "sorted_tree.hpp"

SCENARIO("nstd::sorted_tree", "[sorted_tree]") {
    
    using nstd::sorted_tree;
    using nstd::tree_node;
    using std::make_shared;
    
    GIVEN("a sorted_tree<int>") {
        
        sorted_tree<int> tree;
        
        REQUIRE(!tree.root_node);
        REQUIRE(tree.root_node == nullptr);
        
    }
    
}
