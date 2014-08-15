
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
    
    GIVEN("a sorted_tree<int> with some values in proper sort order") {
        
        sorted_tree<int> tree;
        
        tree.root_node = make_shared<tree_node<int>>(64);
        tree.root_node->lnode = make_shared<tree_node<int>>(32);
        tree.root_node->lnode->lnode = make_shared<tree_node<int>>(16);
        tree.root_node->lnode->rnode = make_shared<tree_node<int>>(48);
        tree.root_node->rnode = make_shared<tree_node<int>>(96);
        tree.root_node->rnode->lnode = make_shared<tree_node<int>>(80);
        tree.root_node->rnode->rnode = make_shared<tree_node<int>>(112);
        
        WHEN("find is called on those values") {
            
            REQUIRE(tree.find(16)  == tree.root_node->lnode->lnode);
            REQUIRE(tree.find(32)  == tree.root_node->lnode);
            REQUIRE(tree.find(48)  == tree.root_node->lnode->rnode);
            REQUIRE(tree.find(64)  == tree.root_node);
            REQUIRE(tree.find(80)  == tree.root_node->rnode->lnode);
            REQUIRE(tree.find(96)  == tree.root_node->rnode);
            REQUIRE(tree.find(112) == tree.root_node->rnode->rnode);
            
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
