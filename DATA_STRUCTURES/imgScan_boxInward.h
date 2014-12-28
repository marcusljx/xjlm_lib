#ifndef IMGSCAN_BOXINWARD_H
#define IMGSCAN_BOXINWARD_H

#include <cstdlib>
#include <vector>

using namespace std;

struct RGBA_value {
	int red;
	int green;
	int blue;
	int alpha;
};

class imgScanBoxInward{
	private:
	
	public:
		imgScanBoxInward;
		~imgScanBoxInward;
	
		vector<int> scan();
		
};

#endif