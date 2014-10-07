//
//  ofxSTLPolyMesh.h
//  EquityBot
//
//  Created by Scott Kildall on 9/23/14.
//
//

#ifndef __EquityBot__ofxSTLPolyMesh__
#define __EquityBot__ofxSTLPolyMesh__

#include <iostream>
#include "ofxSTLPrimitive.h"

class ofxSTLPolyMesh : public ofxSTLPrimitive {
public:
    ofxSTLPolyMesh();
    
    void addFace( ofVec3f &v1, ofVec3f &v2, ofVec3f &v3 );
    

};


#endif /* defined(__EquityBot__ofxSTLPolyMesh__) */
