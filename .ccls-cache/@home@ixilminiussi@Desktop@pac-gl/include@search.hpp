// search.hpp
#pragma once

#include "./box.hpp"
#include <vector>

struct Node {
    Box* box;
    Node* child;
    bool leaf;
    std::vector<Box*> box;

    /**
     * generates a child node if we haven't max depth yet.
     * if we have, populates its list of elems with elems that overlap with its bounding box
     */
    Node(int depth, int maxDepth, BoundingBox* box, Elem* worldElems);
};

bool checkCollision(Node* node)
