///////////////////////////////////////////////////////////////
// Yishi Guo
// 20090910
///////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <stdio.h>

int main() {
	const char* libraries;
	const char* modules;
	cvGetModuleInfo( 0, &libraries, &modules );
	printf("Libraries: %s\nModules: %s\n", libraries, modules );

	return 0;
}