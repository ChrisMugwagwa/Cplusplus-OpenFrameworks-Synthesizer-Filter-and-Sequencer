#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(34);
	
	sampleRate = 44100;
	bufferSize = 512;
	frequency = 300;
	ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
	lAudio.assign(bufferSize, 0.0);
	rAudio.assign(bufferSize, 0.0);
	fftSize = 1024;
	myfft.setup(fftSize, 512, 256);
	spectbottom = 800;
	spectleft = 10;
	counter = 0;
	fttHeight = 1;
	fftWidth = 2;
}
//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
	for (int i = 0; i < bufferSize; i++) {
		currentSample = osc1.sinewave(frequency) + osc2.saw(frequency * 0.6);

		if (myfft.process(currentSample)) {
			myfft.magsToDB();
		}

		lAudio[i] = output[i * nChannels] = currentSample;
		rAudio[i] = output[i * nChannels + 1] = currentSample;

	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	///////DRAW THE CHANNELS////////////////
	ofSetColor(225);
	ofNoFill();

	// draw the left channel:
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(32, 40, 0);

	ofSetColor(225);
	ofDrawBitmapString("Left Channel", 4, 18);

	ofSetLineWidth(1);
	ofRect(0, 0, 900, 200);

	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);

	ofBeginShape();
	for (int i = 0; i < lAudio.size(); i++) {
		float x = ofMap(i, 0, lAudio.size(), 0, 900, true);
		ofVertex(x, 100 - (lAudio[i] * 40.0f));
	}
	ofEndShape(false);

	ofPopMatrix();
	ofPopStyle();

	// draw the right channel:
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(32, 250, 0);

	ofSetColor(225);
	ofDrawBitmapString("Right Channel", 4, 18);

	ofSetLineWidth(1);
	ofRect(0, 0, 900, 200);

	ofSetColor(245, 58, 135);
	ofSetLineWidth(3);

	ofBeginShape();
	for (int i = 0; i < rAudio.size(); i++) {
		float x = ofMap(i, 0, rAudio.size(), 0, 900, true);
		ofVertex(x, 100 - (rAudio[i] * 40.0f));
	}
	ofEndShape(false);

	ofPopMatrix();
	ofPopStyle();
	///////////end drawing the channels/////////////////////////////

	//////////// draw the fft////////////////////////////
	for (int i = 0; i < fftSize / 2; i++) {
		
		ofDrawLine((spectleft + i)*fftWidth, spectbottom, (spectleft + i)*fftWidth, spectbottom -(myfft.magnitudes[i] * fttHeight));
		
		// context.stroke();
		
	}
	///////////end drawing the fft//////////////////////////

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	frequency = ofMap(x, 0, ofGetWidth(), 20, 1000);
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
