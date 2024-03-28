//search-tree.hpp
#pragma once

#include "./elem.hpp"
#include "./vector.hpp"
#include <vector>;

struct Box {
    Vector min, max;

    BoundingBox(Vector min, Vector max) : min(min), max(max) {};
    ~BoundingBox() = default;

    bool overlaps(Vector min, Vector max);
};

struct Node {
    BoundingBox* box;
    Node* child;
    bool leaf;
    std::vector<Elem*> elems;

    /**
     * generates a child node if we haven't max depth yet.
     * if we have, populates its list of elems with elems that overlap with its bounding box
     */
    Node(int depth, int maxDepth, BoundingBox* box, Elem* worldElems);
};

bool checkCollision(Node* node)
