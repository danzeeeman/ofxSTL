/*
 * Copyright (c) 2014, Scott Kildall
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

#pragma once


#include "of3dPrimitives.h"
#include "ofxSTL.h"

class ofxSTLPrimitive : public of3dPrimitive {
    
public:
    ofxSTLPrimitive();
    ~ofxSTLPrimitive();
    
    void init(float x, float y, float z);
    void addCubeFaceVertices(ofVec3f &v1, ofVec3f &v2, ofVec3f &v3, ofVec3f &v4);
    
    void save(string filePath, bool asciiFormat = false);
    void save(ofxSTLExporter &stlExporter);
    
    
private:
    
    
};


