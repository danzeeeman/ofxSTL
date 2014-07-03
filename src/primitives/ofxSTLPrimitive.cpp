/*
 * Copyright (c) Scott Kildall
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * http://creativecommons.org/licenses/LGPL/2.1/
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "ofxSTLPrimitive.h"





ofxSTLBoxPrimitive::ofxSTLBoxPrimitive() {
    width = 4;
    height = 4;
    depth = 4;
    setVertices();
}

void ofxSTLBoxPrimitive::set( float width, float height, float depth ) {
    
}

void ofxSTLBoxPrimitive::set( float size ) {
    width = size;
    height = size;
    depth = size;
    setVertices();
    
}

void ofxSTLBoxPrimitive::setWidth( float a_width ) {
    
}

void ofxSTLBoxPrimitive::setHeight( float a_height ) {
    
}

void ofxSTLBoxPrimitive::setDepth( float a_depth ) {
    
}


void ofxSTLPrimitive::save(string filePath, bool asciiFormat) {
    ofxSTLExporter stlExporter;
    
    stlExporter.beginModel("stlOutput");
    
    save(stlExporter);
    
    stlExporter.useASCIIFormat(asciiFormat);
    stlExporter.saveModel(filePath);
}

void ofxSTLPrimitive::save(ofxSTLExporter &stlExporter) {
    vector<ofVec3f>& verts = mesh->getVertices();
	if( verts.size() %3 != 0 ) {
        cout << "ofxSTLPrimitive() error: vertices must be divisible by 3" << "\n";
        return;
    }
    
    ofVec3f emptyNormal(0,0,0);
    
    for(unsigned int i = 0; i < verts.size(); i+=3){
        stlExporter.addTriangle(verts[i], verts[i+1], verts[i+2], emptyNormal);
    }
}

//-----------------------------
void ofxSTLBoxPrimitive::init(float _x, float _y, float _z) {
    float s = 4;
    float x = _x;
    float y = _y;
    float z = _z;
}

// from stored width, height, depth, will set the vertices
void ofxSTLBoxPrimitive::setVertices() {
    ofVec3f p = getPosition();
    
    ofVec3f v1(p.x-width/2, p.y-height/2, p.z-depth/2);
    ofVec3f v2(p.x+width/2, p.y-height/2, p.z-depth/2);
    ofVec3f v3(p.x+width/2, p.y-height/2, p.z+depth/2);
    ofVec3f v4(p.x-width/2, p.y-height/2, p.z+depth/2);
    
    ofVec3f v5(p.x-width/2, p.y+height/2, p.z+depth/2);
    ofVec3f v6(p.x-width/2, p.y+height/2, p.z-depth/2);
    ofVec3f v7(p.x+width/2, p.y+height/2, p.z-depth/2);
    ofVec3f v8(p.x+width/2, p.y+height/2, p.z+depth/2);
    
    mesh->clearVertices();
    
    // each vertex shows up 3 times
    addCubeFaceVertices(v1,v2,v3,v4);     // next vertex = v3
    addCubeFaceVertices(v2,v7,v8,v3);     // next vertex = v8
    addCubeFaceVertices(v8,v7,v6,v5);     // next vertex = v8
    addCubeFaceVertices(v8,v5,v4,v3);     // next vertex = v4
    addCubeFaceVertices(v5,v6,v1,v4);     // next vertex = v1
    addCubeFaceVertices(v6,v7,v2,v1);     // next vertex = v1
}

//-- last vertex will always be at v3
void ofxSTLBoxPrimitive::addCubeFaceVertices(ofVec3f &v1, ofVec3f &v2, ofVec3f &v3, ofVec3f &v4) {
    mesh->addVertex(v1);
    mesh->addVertex(v2);
    mesh->addVertex(v3);
    
    mesh->addVertex(v4);
    mesh->addVertex(v1);
    mesh->addVertex(v3);
}


