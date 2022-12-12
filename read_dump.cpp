#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <filesystem>

using namespace std;

uint64_t bytes = 0;
uint64_t ascii = 0;

void memRead(FILE** fp, string valueResultPath, uint32_t dataWidth) {
	char* buffer = new char[dataWidth];
    while (fread(buffer, sizeof(char), dataWidth, *fp) > 0) {
		bool isZero = false;
		for(int i = 0; i < dataWidth; i++) {
			bitset<8> tmp = buffer[i];
			if(tmp.none())
				if(i == dataWidth - 1)
					isZero = true;
		}
		
		if(isZero)
			continue;

		for(int i = 0; i < dataWidth; i++) {
			bytes++;
			
			if(buffer[i] >= 65 && buffer[i] <= 90)
				ascii++;
			else if(buffer[i] >= 97 && buffer[i] <= 122)
				ascii++;

			ofstream writeFile;
			writeFile.open(valueResultPath, ios_base::app);
			writeFile << buffer[i];
			writeFile.close();
		}
	}

	return;
}

void read(string path, string valueResultPath, uint32_t dataWidth) {
	for(const auto & entry : filesystem::directory_iterator(path)) {
		FILE* fp = fopen(entry.path().c_str(), "r");
		if(!fp) {
			cout << "file open failed." << endl;
			return;
		}

		memRead(&fp, valueResultPath, dataWidth);

		fclose(fp);
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "memory data file directory needed." << endl;
		return 0;
	}
	else if (argc < 3) {
		cout << "value result write directory needed." << endl;
	}
	else if (argc < 4) {
		cout << "data width needed." << endl;
		return 0;
	}

	string path = argv[1];
	string valueResultPath = argv[2];
	string strWidth = argv[3];
	uint32_t dataWidth = stoi(strWidth);

	read(path, valueResultPath, dataWidth);

	cout << ascii << " bytes of " << bytes << " bytes ( " << (double)ascii/(double)bytes*(double)100 << "% ) are alphabets.\n";
	return 0;	
}
