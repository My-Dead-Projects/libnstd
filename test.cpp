
#include "Catch/single_include/catch.hpp"

#include "sorted_tree.hpp"

SCENARIO("nstd::sorted_tree", "[sorted_tree]") {
    
    using nstd::sorted_tree;
    using nstd::tree_node;
    using std::make_shared;
    
    GIVEN("a sorted_tree<int>") {
        
        sorted_tree<int> tree;
        
        REQUIRE(not tree.find(0));
        
        WHEN("values are added via find()") {
            
            
            
        }
        
    }
    
}

SCENARIO("nstd::tree_node", "[tree_node]") {
    
    using nstd::tree_node;
    
    GIVEN("a nstd::tree_node<int>") {
        
        tree_node<int> node;
        
        REQUIRE(!node.lnode);
        REQUIRE(!node.rnode);
        
    }
    
}
