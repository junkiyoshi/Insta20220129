#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int span = 40;
	for (int x = span * -8; x < span * 8; x += span) {

		for (int y = span * -8; y < span * 8; y += span) {

			vector<glm::vec2> vertices;

			int r = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.0035), 0, 1, 0, 4);
			auto location = glm::vec2(x, y);

			if (r == 1) {

				location += glm::vec2(span, 0);
			}
			else if (r == 2) {

				location += glm::vec2(span, span);
			}
			else if (r == 3) {

				location += glm::vec2(0, span);
			}

			int deg_start = r * 90;
			int radius = span;
			for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

				vertices.push_back(location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
			}

			r = (r + 2) % 4;

			location = glm::vec2(x, y);
			if (r == 1) {

				location += glm::vec2(span, 0);
			}
			else if (r == 2) {

				location += glm::vec2(span, span);
			}
			else if (r == 3) {

				location += glm::vec2(0, span);
			}

			deg_start = r * 90;
			for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

				vertices.push_back(location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
			}

			ofSetColor(0);
			ofFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofSetColor(255);
			ofNoFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}