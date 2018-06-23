/*******************************************************************
 * Ravenclaw's steg program.
 * 
 * This program uses simple steganography techniques to embed
 * messages into a text file.
 * 
 * Usage: ./steg -(bB) -(sr) -o<val> [-i<val>] -w<val> [-h<val>]
 *   -b       :use the bit method
 *   -B       :use the byte method
 *   -s       :store (and hide) data
 *   -r       :retrieve hidden data
 *   -o<val>  :set offset to <val>
 *   -i<val>  :set interval to <val>
 *   -w<val>  :set wrapper file to <val>
 *   -h<val>  :set hidden file to <val>
 *******************************************************************/

#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>

using namespace std;

typedef unsigned char BYTE;

int main (int argc, char **argv) {
	//printf("Number of arguments: %d\n", argc);
	int i, offset, interval, wrapperSize, hiddenSize;
	char method, storeRead;
	BYTE *hiddenBuf;
	BYTE *wrapperBuf;
	string wrapperName;
	string hiddenName;
	FILE * wrapper;
	FILE * hidden;

	offset = 0;
	interval = 0;

	// Interpret arguments
	for(i = 1; i < argc; i++) {
		string temp = argv[i];
		string temp2 = temp.substr(0,2);
		if(temp2 == "-b") {
			method = 'b';
			interval = 1;
		} else if(temp2 == "-B") {
			method = 'B';
		} else if(temp2 == "-s") {
			storeRead = 's';
		} else if(temp2 == "-r") {
			storeRead = 'r';
		} else if(temp2 == "-o") {
			string temp3 = temp.substr(2);
			// Check for number correctness
			int number;
			istringstream (temp3) >> number;
			offset = number;
		} else if(temp2 == "-i") {
			string temp3 = temp.substr(2);
			int number;
			istringstream (temp3) >> number;
			if(method == 'B'){
				interval = number;
			}
		} else if(temp2 == "-w") {
			wrapperName = temp.substr(2);
			wrapper = fopen(wrapperName.c_str(), "rb");
			if(wrapper == NULL) {
				cerr << "Error opening wrapper file.";
			}
			fseek (wrapper, 0, SEEK_END);
			wrapperSize = ftell (wrapper);
			fseek(wrapper, 0, SEEK_SET);
		} else if(temp2 == "-h") {
			hiddenName = temp.substr(2);
			hidden = fopen(hiddenName.c_str(), "rb");
			if(hidden == NULL) {
				cerr << "Error opening hidden file.";
			}
			fseek (hidden, 0, SEEK_END);
			hiddenSize = ftell (hidden);
			fseek(hidden, 0, SEEK_SET);
		}
	}

	if(storeRead == 's') {
		// Store mode
			hiddenBuf = new BYTE[hiddenSize+(6*(sizeof(BYTE)))];
			wrapperBuf = new BYTE[wrapperSize];
			// Copy over hidden file and wrapper file to buffers
			fread(hiddenBuf, 1, hiddenSize, hidden);
			fread(wrapperBuf, 1, wrapperSize, wrapper);
			// Setting sentinel value
			hiddenBuf[hiddenSize+(6*(sizeof(BYTE)))-1] = 0;
			hiddenBuf[hiddenSize+(6*(sizeof(BYTE)))-2] = 255;
			hiddenBuf[hiddenSize+(6*(sizeof(BYTE)))-3] = 0;
			hiddenBuf[hiddenSize+(6*(sizeof(BYTE)))-4] = 0;
			hiddenBuf[hiddenSize+(6*(sizeof(BYTE)))-5] = 255;
			hiddenBuf[hiddenSize+(6*(sizeof(BYTE)))-6] = 0;
		if(method == 'b') {
			// bit mode
			int i = offset;
			int j = 0;
			int size = hiddenSize+(6*(sizeof(BYTE)));
			while(j < size){
				int k;
				for(k = 7; k >= 0; k--) {
					BYTE temp = hiddenBuf[j];
					temp = temp >> k;
					temp &= 1;
					wrapperBuf[i] &= 254;
					wrapperBuf[i] |= temp;
					i++;
				}
				j++;
			}
		} else if(method == 'B') {
			// BYTE mode
			int i;
			i = 0;
			int size = hiddenSize+(6*(sizeof(BYTE)));
			while( i < size) {
				wrapperBuf[offset] = hiddenBuf[i];
				offset += interval;
				i++;
			}
		}

		// Output stegged file
		int l;
		for(l = 0; l < wrapperSize; l++) {
			cout << wrapperBuf[l];
		}

		// Cleanup
		delete[]wrapperBuf;
		delete[]hiddenBuf;
		fclose(wrapper);
		fclose(hidden);

	} else if(storeRead == 'r') {
		// Retrieve mode
		wrapperBuf = new BYTE[wrapperSize];
		fread(wrapperBuf, wrapperSize, 1, wrapper);
		if(method == 'b') {
			// bit mode
			int i = offset;
			int j = 0;
			int sentinel = 0;
			int flag = 0;
			BYTE temp;
			while(flag == 0 && i < wrapperSize){
				int k;
				temp = 0;
				for(k = 0; k < 8; k++) {
					temp = temp << 1;
					wrapperBuf[i] &= 1;
					temp |= wrapperBuf[i];
					i++;
				}
				if(temp==0 && sentinel==0){
					sentinel++;
				} else if(temp==255 && sentinel==1) {
					sentinel++;
				} else if(temp==0 && sentinel==2) {
					sentinel++;
				} else if(temp==0 && sentinel==3) {
					sentinel++;
				} else if(temp==255 && sentinel==4) {
					sentinel++;
				} else if(temp==0 && sentinel==5) {
					flag = 1;
				} else {
					sentinel = 0;
				}
				cout << temp;
			}
		} else if(method == 'B') {
			// BYTE mode
			int i;
			i = 0;
			int sentinel;
			int flag = 0;
			while(flag == 0) {
				if(wrapperBuf[offset]==0 && sentinel==0){
					sentinel++;
				} else if(wrapperBuf[offset]==255 && sentinel==1) {
					sentinel++;
				} else if(wrapperBuf[offset]==0 && sentinel==2) {
					sentinel++;
				} else if(wrapperBuf[offset]==0 && sentinel==3) {
					sentinel++;
				} else if(wrapperBuf[offset]==255 && sentinel==4) {
					sentinel++;
				} else if(wrapperBuf[offset]==0 && sentinel==5) {
					flag = 1;
				} else {
					sentinel = 0;
				}
				cout << wrapperBuf[offset];
				offset += interval;
				i++;
				
			}
		}
		delete[]wrapperBuf;
		fclose(wrapper);
	}
	return 1;
}
