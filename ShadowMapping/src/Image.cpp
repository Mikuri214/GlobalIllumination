#include "Image.h"

Image::Image(int width, int height, int channels) {

	data = (unsigned char*)malloc(width * height * channels * sizeof(unsigned char));
	this->width = width;
	this->height = height;

}

Image::~Image() {

	delete [] data;

}

void Image::computeBoundingBoxFromOpenGLImage() {

	int pixel;
	bool doBreak = false;
	for(int y = 0; !doBreak && y < height; y++) {
		for(int x = 0; x < width; x++) {
			pixel = (height - y) * width + (x);
			if((int)data[pixel * 3 + 0] == 255 && (int)data[pixel * 3 + 1] == 0 && (int)data[pixel * 3 + 2] == 0) {
				ymin = y;
				doBreak = true;
				break;
			}
		}
	}

	doBreak = false;
	for(int y = height - 1; !doBreak && y > 0; y--) {
		for(int x = 0; x < width; x++) {
			pixel = (height - y) * width + (x);
			if((int)data[pixel * 3 + 0] == 255 && (int)data[pixel * 3 + 1] == 0 && (int)data[pixel * 3 + 2] == 0) {
				ymax = y;
				doBreak = true;
				break;
			}
		}
	}

	doBreak = false;
	for(int x = 0; !doBreak && x < width; x++) {
		for(int y = 0; y < height; y++) {
			pixel = (height - y) * width + (x);
			if((int)data[pixel * 3 + 0] == 255 && (int)data[pixel * 3 + 1] == 0 && (int)data[pixel * 3 + 2] == 0) {
				xmin = x;
				doBreak = true;
				break;
			}
		}
	}

	doBreak = false;
	for(int x = width - 1; !doBreak && x > 0; x--) {
		for(int y = 0; y < height; y++) {
			pixel = (height - y) * width + (x);
			if((int)data[pixel * 3 + 0] == 255 && (int)data[pixel * 3 + 1] == 0 && (int)data[pixel * 3 + 2] == 0) {
				xmax = x;
				doBreak = true;
				break;
			}
		}
	}

}