
#include "Catch/single_include/catch.hpp"

#include "sorted_tree.hpp"

SCENARIO("nstd::sorted_tree", "[sorted_tree]") {
    
    GIVEN("a nstd::sorted_tree<int>") {
        
        nstd::sorted_tree<int> tree;
        
        REQUIRE(!tree.root_node);
    }
    
}
