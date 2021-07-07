#include "ofApp.h"

static const float h_kernel[] = { 1, 1, 1, 1, 0, 1, 1, 1, 1 };
static const int reset = 500;

//--------------------------------------------------------------
void ofApp::setup(){
	af::info();
	af::setDevice(0);

	std::cout << "This example demonstrates the Conway's Game of Life "
		"using ArrayFire"
		<< '\n'
		<< "There are 4 simple rules of Conways's Game of Life" << '\n'
		<< "1. Any live cell with fewer than two live neighbours "
		"dies, as if caused by under-population."
		<< '\n'
		<< "2. Any live cell with two or three live neighbours lives "
		"on to the next generation."
		<< '\n'
		<< "3. Any live cell with more than three live neighbours "
		"dies, as if by overcrowding."
		<< '\n'
		<< "4. Any dead cell with exactly three live neighbours "
		"becomes a live cell, as if by reproduction."
		<< '\n'
		<< "Each white block in the visualization represents 1 alive "
		"cell, black space represents dead cells"
		<< '\n';

	gameWidth = ofGetWidth();
	gameHeight = ofGetHeight();

	try {
		state = (af::randu(gameWidth, gameHeight, f32) > 0.5).as(f32);
	}
	catch (af::exception& e) {
		std::cerr << e.what() << '\n';
		throw;
	}

	hostState = new float[state.elements()];

	pix.allocate(gameWidth, gameHeight, OF_PIXELS_RGBA);
	tex.allocate(pix);
}

//--------------------------------------------------------------
void ofApp::update(){
	stringstream titleStream;
	titleStream << "example_gameOfLifeCuda - FPS: "
		<< static_cast<int>(ofGetFrameRate());
	ofSetWindowTitle(titleStream.str());

	try {
		// How to check dimension of state completely unnecessary check
		const af::dim4 dims = state.dims();
		assert(gameWidth == dims[0] && gameHeight == dims[1]);

		// Generate a random starting state
		if (ofGetFrameNum() % reset == 0)
			state = (af::randu(gameWidth, gameHeight, f32) > 0.5).as(f32);

		// Convolve gets neighbors
		const af::array kernel(3, 3, h_kernel, afHost);
		af::array nHood = af::convolve(state, kernel);

		// Generate conditions for life
		// state == 1 && nHood < 2 ->> state = 0
		// state == 1 && nHood > 3 ->> state = 0
		// else if state == 1 ->> state = 1
		// state == 0 && nHood == 3 ->> state = 1
		af::array C0 = (nHood == 2);
		af::array C1 = (nHood == 3);

		// Update state
		state = state * C0 + C1;

		// Copy state to host to display it
		state.host(hostState);

	}
	catch (af::exception& e) {
		std::cerr << e.what() << '\n';
		throw;
	}

	// update pixels and texture to display
	for (int i = 0; i < gameWidth; ++i) {
		for (int j = 0; j < gameHeight; ++j) {
			pix.setColor(i, j, ofColor(hostState[i + j * gameWidth] * 255));
		}
	}
	tex.loadData(pix);
}

//--------------------------------------------------------------
void ofApp::draw(){
	tex.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
