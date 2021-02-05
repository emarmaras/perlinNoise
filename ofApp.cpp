#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(107, 107, 107);
	ofEnableDepthTest();

	box.set(10, 10, 10);
	box.setPosition(0, 0, 0);
	cam.setPosition(0, -57, 23);
	cam.lookAt(ofVec3f(0, 0, 0));

	numCols = 100;
	numRows = 100;

	n1frequency = 0.04;
	n1amp = 5;
	n2frequency = 0.03;
	n2amp = 7.5;

	drawMesh(50, 50);

	ball1.setRadius(5);
	ball3.setRadius(3);
	ball6.setRadius(5);

	ball1.setPosition(ofRandom(-25, 25), ofRandom(-25, 25), 0);
	ball1pos = ball1.getPosition();

	ball3.setPosition(ofRandom(-25, 25), ofRandom(-25, 25), 0);
	ball3pos = ball3.getPosition();

	ball6.setPosition(ofRandom(-25, 25), ofRandom(-25, 25), 0);
	ball6pos = ball6.getPosition();
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < mesh.getNumVertices(); i++) {
		ofVec3f position = mesh.getVertex(i);
		position.z = getZNoiseValue(position.x, position.y, ofGetFrameNum());
		mesh.setVertex(i, position);
	}

		ball1.setPosition(ball1pos.x, ball1pos.y, getZNoiseValue(ball1pos.x, ball1pos.y, ofGetFrameNum()) + 5);
		ball3.setPosition(ball3pos.x, ball3pos.y, getZNoiseValue(ball3pos.x, ball3pos.y, ofGetFrameNum()) + 3);
		ball6.setPosition(ball6pos.x, ball6pos.y, getZNoiseValue(ball6pos.x, ball6pos.y, ofGetFrameNum()) + 5);
	
}


//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	ofSetColor(255);
	mesh.drawWireframe();
	ball1.draw();
	ball3.draw();
	ball6.draw();
	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	if (key == 32) {

		cam.setPosition(0, -57, 23);
		cam.lookAt(ofVec3f(0, 0, 0));
	}
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------

void ofApp::drawMesh(int numCols, int numRows) {

	for (int i = 0; i < numCols; i++) {
		for (int j = 0; j < numRows; j++) {
			mesh.addVertex(ofPoint((-numCols / 2 + i), (-numRows / 2 + j)));
		}
	}

	for (int x = 0; x < numCols - 1; x++) {
		for (int y = 0; y < numRows - 1; y++) {
			int topLeft = x + numCols * y;
			int bottomLeft = x + 1 + numCols * y;
			int topRight = x + numCols * (y + 1);
			int bottomRight = x + 1 + numCols * (y + 1);

			mesh.addTriangle(topLeft, bottomLeft, topRight);
			mesh.addTriangle(bottomLeft, topRight, bottomRight);

		}
	}
}

float ofApp::getZNoiseValue(float x, float y, float t) {
	n1 = ofNoise(x * n1frequency, y * n1frequency, t / 120) * n1amp;
	n2 = ofNoise(x * n2frequency, y * n2frequency, t / 120) * n2amp;
	return n1 + n2;
}
void ofApp::spheres(float x, float y, int width, int height) {

}