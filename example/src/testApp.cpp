#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofBackgroundHex(0x222222);
	ofSetVerticalSync(true);
    
    
	ofSetLogLevel(OF_LOG_VERBOSE);
	bSaveModel = false;
    
	stlImporter.loadSTL(ofToDataPath("OF_logo.stl"));
    stlImporter.normalizeModel();
    stlImporter.scaleModel(600);
    mesh = stlImporter.getMesh();
    
    drawMode = facets;
    
    butterfly.topology_start(mesh);

    subdivided = butterfly.topology_end();
}

//--------------------------------------------------------------
void testApp::update(){
	if(bSaveModel){
		bSaveModel = false;
		vector<ofxSTLFacet>& facets = stlImporter.getFacets();
		int numFacets = facets.size();
		stlExporter.beginModel("some model");
		for(int i=0; i<numFacets; i++){
			stlExporter.addTriangle(facets[i].vert1, facets[i].vert2, facets[i].vert3, facets[i].normal);
		}
		stlExporter.useASCIIFormat(true); //export as ASCII (default is binary)
		stlExporter.saveModel(ofToDataPath("testASCII.stl"));
		stlExporter.useASCIIFormat(false); //export as binary
		stlExporter.saveModel(ofToDataPath("testBin.stl"));
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    camera.begin();
    
    // Enlarge our model

    
    ofRotateY(-35); // beauty angle
    
    if(drawMode == wire) {
        subdivided.drawWireframe();
    }
    else if(drawMode == facets) {
         subdivided.drawFaces();
    }
    
    camera.end();
    
    //
    
    ofSetHexColor(0xe0d6ff);
    
    stringstream showKey;
    
    showKey << "Draw Options \n\n"
    << "1: Draw Normals \n"
    << "2: Draw WireFrame \n"
    << "3: Draw Facets";
    
    ofDrawBitmapString(showKey.str(), 20,20);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    // Reset the mseh to the original subdivision.
    if(key == 'r')
    {
        subdivided = mesh;
        
    }
    
    // Butterfly subdivide the internal and boundary vertices.
    if(key == 'b')
    {
        subdivided = butterfly.subdivideButterfly(subdivided);
        
    }
    
    // Linearly subdividethe mesh.
    if(key == 'l')
    {
        subdivided = butterfly.subdivideLinear(subdivided);
        
    }
    
    // Subdivide the boundaries of the mesh.
    if(key == 'f')
    {
        
        //mesh.getVertices()[0] = ofVec3f(0, 0, 0);
        
        int start, end;
        start = ofGetElapsedTimeMicros();
        butterfly.fixMesh(mesh, subdivided);
        end = ofGetElapsedTimeMicros();
        
        cout << "Fast Edge Fixing Time : " << end - start << std::endl;
        
        
        //subdivided = butterfly.subdivideBoundary(subdivided, 2, 1);
    }
    
    if(key == 'e')
    {
        subdivided = butterfly.subdivideBoundary(subdivided, -1, 1);
        
    }
    
    // Subdivide the mesh using a whimpsical pascal's triangle scheme.
    if(key == 'p')
    {
        subdivided = butterfly.subdividePascal(subdivided);
        
    }

    
    switch (key) {
            
        case '1':
            drawMode = normals;
            break;
            
        case '2':
            drawMode = wire;
            break;
            
        case '3':
            drawMode = facets;
            break;
            
        default:
            break;
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

