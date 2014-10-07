//
//  ofxSTLPolyMesh.cpp
//  EquityBot
//
//  Created by Scott Kildall on 9/23/14.
//
//

#include "ofxSTLPolyMesh.h"

ofxSTLPolyMesh::ofxSTLPolyMesh() {
    
}

void ofxSTLPolyMesh::addFace( ofVec3f &v1, ofVec3f &v2, ofVec3f &v3 ) {
    mesh->addVertex(v1);
    mesh->addVertex(v2);
    mesh->addVertex(v3);
}