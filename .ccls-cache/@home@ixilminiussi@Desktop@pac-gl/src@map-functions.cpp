// map-functions.cpp
#pragma once

#include "./cube.cpp"
#include <vector>
#include <iostream>

/**
 * recursive function which explores the partition tree and looks for any and all intersecting cubes.
 */
void getIntersections(Cube* observer, Node* node, std::vector<Cube*> &intersections) {
    if (node->leaf) {
        for (Cube* cube : node->localCubes) {
            if (observer->overlaps(cube)) {
                intersections.push_back(cube);
            }
        }
    } else {
        for (Node* child : node->children) {
            if (observer->overlaps(child)) {
                getIntersections(observer, child, intersections);
            }
        }
    }
}
