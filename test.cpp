
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
        
        WHEN("values are added via find()") {
            
            auto node16  = make_shared<tree_node<int>>(16);
            auto node32  = make_shared<tree_node<int>>(32);
            auto node48  = make_shared<tree_node<int>>(48);
            auto node64  = make_shared<tree_node<int>>(64);
            auto node80  = make_shared<tree_node<int>>(80);
            auto node96  = make_shared<tree_node<int>>(96);
            auto node112 = make_shared<tree_node<int>>(112);
            
            tree.find(64)  = node64;
            tree.find(32)  = node32;
            tree.find(16)  = node16;
            tree.find(48)  = node48;
            tree.find(96)  = node96;
            tree.find(80)  = node80;
            tree.find(112) = node112;
            
            REQUIRE(tree.root_node->lnode->lnode == node16);
            REQUIRE(tree.root_node->lnode == node32);
            REQUIRE(tree.root_node->lnode->rnode == node48);
            REQUIRE(tree.root_node == node64);
            REQUIRE(tree.root_node->rnode->lnode == node80);
            REQUIRE(tree.root_node->rnode == node96);
            REQUIRE(tree.root_node->rnode->rnode == node112);
            
        }
        
    }
    
    GIVEN("a sorted_tree<int> with some values in proper sort order") {
        
        sorted_tree<int> tree;
        
        auto node16  = make_shared<tree_node<int>>(16);
        auto node32  = make_shared<tree_node<int>>(32);
        auto node48  = make_shared<tree_node<int>>(48);
        auto node64  = make_shared<tree_node<int>>(64);
        auto node80  = make_shared<tree_node<int>>(80);
        auto node96  = make_shared<tree_node<int>>(96);
        auto node112 = make_shared<tree_node<int>>(112);
        
        tree.root_node = node64;
        tree.root_node->lnode = node32;
        tree.root_node->lnode->lnode = node16;
        tree.root_node->lnode->rnode = node48;
        tree.root_node->rnode = node96;
        tree.root_node->rnode->lnode = node80;
        tree.root_node->rnode->rnode = node112;
        
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
