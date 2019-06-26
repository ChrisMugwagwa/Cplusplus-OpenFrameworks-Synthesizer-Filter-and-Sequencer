#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
//#include "maximilian.h"
#include "fft.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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

		void audioOut(float * buffer, int bufferSize, int nChannels);

		maxiOsc osc1, osc2;

		double frequency, currentSample;
		unsigned int bufferSize, sampleRate;

		vector <float> lAudio;
		vector <float> rAudio;

		maxiFFT myfft;
		int spectleft;
		int spectbottom;
		int fftSize;
		int counter;
		int fttHeight;
		int fftWidth;

		int step = 0;
		
		maxiSample kick;
		maxiSample snare; 
		maxiSample hihat;
		maxiSample shaker;

		
};
