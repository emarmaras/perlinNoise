#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int numCols;
		int numRows;

		float camX;
		float camY;
		float r;
		float theta;
		float x;
		float y;
		float n1;
		float n2;
		float n1frequency;
		float n2frequency;
		float n1amp;
		float n2amp;

		float getZNoiseValue(float x, float y, float t);
		float gridScale;

		ofBoxPrimitive box;
		ofEasyCam cam;
		ofLight light;
		ofMesh mesh;
		ofTexture tex;

		void drawMesh(int numCols, int numRows);
		void spheres(float x, float y, int width, int height);

		ofSpherePrimitive ball1;
		ofSpherePrimitive ball3;
		ofSpherePrimitive ball6;

		ofPoint ball1pos;
		ofPoint ball3pos;
		ofPoint ball6pos;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

};
