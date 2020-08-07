/**
 *  ofxCsv
 *  Inspired and based on Ben Fry's [table class](http://benfry.com/writing/map/Table.pde)
 *
 *  The MIT License
 *
 *  Copyright (c) 2011-2019 Paul Vollmer, https://paulvollmer.net
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  @modified           2019.05.15
 *  @version            0.2.1
 */

#include "ofApp.h"

void ofApp::setup()
{
    ofSetFrameRate(30);
    ofSetLogLevel("ofxCsv", OF_LOG_VERBOSE); // See what's going on inside.

    // Load a CSV File.
    if (csv.load("/etc/etitc/assets/database/mad-obj-unix.csv"))
    {
        // csv.trim(); // Trim leading/trailing whitespace from non-quoted fields.

        // Like with C++ vectors, the index operator is a quick way to grab row
        // & col data, however this will cause a crash if the row or col doesn't
        // exist, ie. the file didn't load.
        ofLog() << "Print out a specific CSV value";
        ofLog() << csv[0][1];
        // also you can write...
        ofLog() << csv[0].at(1);
        // or you can get the row itself...
        ofxCsvRow row = csv[0];
        ofLog() << row.getString(1);
    }

    // A safer method is to use the getters which will do a check on the
    // given row & col indices but will be slightly slower.
    ofLog() << "Print out the first value";
    ofLog() << csv.getRow(0).getString(0);
}

void ofApp::update()  {}

void ofApp::draw()
{
    ofSetColor(255);
    ofFill();
    ofDrawBitmapString("CSV FILE", 200, 50);

    // Check how many rows exist.
    // ofDrawBitmapString("csv rows: " + ofToString(csv.getNumRows()), 200, 70);
    // Check how many columns exist.
    // ofDrawBitmapString("csv cols: " + ofToString(csv.getNumCols()), 200, 90);

    // Print out all rows and cols.
    for (unsigned int i = 0; i < csv.getNumRows() / 100; i++)
        for (unsigned int j = 0; j < csv.getNumCols(i); j++)
            ofDrawBitmapString(to_string(j) + csv[i][j], 5 + j * 200, 20 + i * 20);
}

void ofApp::keyPressed(int key)  {}
void ofApp::keyReleased(int key)  {}
void ofApp::mouseMoved(int x, int y )  {}
void ofApp::mouseDragged(int x, int y, int button)  {}
void ofApp::mousePressed(int x, int y, int button)  {}
void ofApp::mouseReleased(int x, int y, int button)  {}
void ofApp::windowResized(int w, int h)  {}
void ofApp::gotMessage(ofMessage msg)  {}
void ofApp::dragEvent(ofDragInfo dragInfo)  {}
