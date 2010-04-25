#include <stdio.h>
#include <string>
#include <malloc.h>
#include <cv.h>
#include <highgui.h>

using namespace std;
/*
**struct name:charinfo
**description:
*/
typedef struct charinfo{
	int keynum;
	char ch;
	int length;  //lengChinfoth of character digit sequence.
	//struct charinfo* next;
}charinfo;
/*
**struct name:CharCatalog
**description:
*/
typedef struct CharCatalog{
	int startNum;
	int index[3];       //keynum = index[0]+index[1]+4*index[2]
	charinfo* Chinfo;
	int length;   //length of datas
}CharCatalog;

CharCatalog* init_char(void);
void fillData(CharCatalog* charCata,int stNum,int ind[3],charinfo* Chinf,int len);
void fillCharinfo(charinfo* chinf,int num,char ch,int len);
void recognize_char(CharCatalog* charMap,int arr[],char* characters);
charinfo binarySearch(CharCatalog* charMap,int arr[]);

void point2image(IplImage* img);
void printPixel(IplImage* img);
void accumulatePoint(IplImage* img,int arr[]);


/*
**name:init_char
**function:use struct CharNode to initialize 36 characters
**input:void
**output:CharCatalog that has been initialized
*/

/*************************************************
  Function:       	init_char
  Description:    	use struct CharNode to initialize 36 characters
  Calls:         
					malloc,
					fillData,
					fillCharinfo
  Called By:      	main
  Input:          	NULL
  Output:         	返回建立好的字符特征识别结构
  Return:         	CharCatalog* charList
  Others:         	识别关键数字 keynum = array[index0]+array[index1]+ 4 * array[index2];
					可确定在已经知道将要处理字符数字串的第一位数字的情况下保持唯一。
*************************************************/
CharCatalog* init_char(void){
	CharCatalog* charList;
	int ind[3];

	charList = (CharCatalog*) malloc(10*sizeof(CharCatalog));
	//start with 1.
	ind[0] = 2;
	ind[1] = 2;
	ind[2] = 2;
	charinfo* s_one = (charinfo*)malloc( 2 *sizeof(charinfo));
	fillCharinfo(&s_one[0],12,'Y',12);
	fillCharinfo(&s_one[1],18,'X',11);
	fillData(&charList[0],1,ind,s_one,2);
	//start with 2.
	ind[0] = 4;
	ind[1] = 7;
	ind[2] = 6;
	charinfo* s_two = (charinfo*)malloc( 7 *sizeof(charinfo));
	fillCharinfo(&s_two[0],13,'1',5);
	fillCharinfo(&s_two[1],19,'V',11);
	fillCharinfo(&s_two[2],30,'A',11);
	fillCharinfo(&s_two[3],33,'7',8);
	fillCharinfo(&s_two[4],42,'Z',10);
	fillCharinfo(&s_two[5],43,'W',17);
	fillCharinfo(&s_two[6],56,'T',10);
	fillData(&charList[1],2,ind,s_two,7);
	//start with 3.
	ind[0] = 2;
	ind[1] = 3;
	ind[2] = 4;
	charinfo* s_three =(charinfo*) malloc( 3 *sizeof(charinfo));
	fillCharinfo(&s_three[0],14,'J',7);
	fillCharinfo(&s_three[1],29,'4',9);
	fillCharinfo(&s_three[2],33,'3',8);
	fillData(&charList[2],3,ind,s_three,3);
	//start with 4.
	ind[0] = 1;
	ind[1] = 1;
	ind[2] = 1;
	charinfo* s_four = (charinfo*)malloc( 1 *sizeof(charinfo));
	fillCharinfo(s_four,24,'2',8);
	fillData(&charList[3],4,ind,s_four,1);
	//start with 5.
	ind[0] = 7;
	ind[1] = 11;
	ind[2] = 13;
	charinfo* s_five = (charinfo*)malloc( 6 *sizeof(charinfo));
	fillCharinfo(&s_five[0],6,'S',10);
	fillCharinfo(&s_five[1],7,'C',11);
	fillCharinfo(&s_five[2],11,'9',8);
	fillCharinfo(&s_five[3],13,'O',12);
	fillCharinfo(&s_five[4],14,'Q',12);
	fillCharinfo(&s_five[5],15,'G',12);
	fillData(&charList[4],5,ind,s_five,6);
	//start with 6.
	ind[0] = 1;
	ind[1] = 1;
	ind[2] = 1;
	charinfo* s_six = (charinfo*)malloc( 1 *sizeof(charinfo));
	fillCharinfo(s_six,36,'5',8);
	fillData(&charList[5],6,ind,s_six,1);
	//start with 7.
	ind[0] = 3;
	ind[1] = 3;
	ind[2] = 3;
	charinfo* s_seven = (charinfo*)malloc( 2 *sizeof(charinfo));
	fillCharinfo(&s_seven[0],36,'8',8);
	fillCharinfo(&s_seven[1],48,'6',8);
	fillData(&charList[6],7,ind,s_seven,2);
	//start with 9.
	ind[0] = 1;
	ind[1] = 1;
	ind[2] = 1;
	charinfo* s_nine = (charinfo*)malloc( 1 *sizeof(charinfo));
	fillCharinfo(s_nine,54,'0',8);
	fillData(&charList[7],9,ind,s_nine,1);
	//start with 11.
	ind[0] = 1;
	ind[1] = 1;
	ind[2] = 1;
	charinfo* s_eleven = (charinfo*)malloc( 1 *sizeof(charinfo));
	fillCharinfo(s_eleven,66,'U',11);
	fillData(&charList[8],11,ind,s_eleven,1);
	//start with 13.
	ind[0] = 7;
	ind[1] = 9;
	ind[2] = 10;
	charinfo* s_thirteen = (charinfo*)malloc( 12 *sizeof(charinfo));
	fillCharinfo(&s_thirteen[0],0,'I',2);
	fillCharinfo(&s_thirteen[1],2,'L',8);
	fillCharinfo(&s_thirteen[2],6,'F',9);
	fillCharinfo(&s_thirteen[3],24,'K',11);
	fillCharinfo(&s_thirteen[4],26,'P',10);
	fillCharinfo(&s_thirteen[5],28,'E',10);
	fillCharinfo(&s_thirteen[6],33,'M',13);
	fillCharinfo(&s_thirteen[7],45,'B',10);
	fillCharinfo(&s_thirteen[8],46,'D',11);
	fillCharinfo(&s_thirteen[9],52,'R',12);
	fillCharinfo(&s_thirteen[10],56,'H',11);
	fillCharinfo(&s_thirteen[11],58,'N',11);
	fillData(&charList[9],13,ind,s_thirteen,12);

	return  charList;
}

/*************************************************
  Function:       	fillData
  Description:   	配置传入的charCata识别特征
  Calls:          	NULL
  Called By:      	init_char
  Input:          	charCata，用来表示数字串以某个数字开头字符集合的结构体
					stNum,此字符的特征数字串的第一个数字标示
					ind[3],用来计算keynum的3个数字串位置索引
					Chinf,所属charCata类别中的第一个字符机构
					len,此类别中的字符个数
  Output:         	NULL
  Return:         	void
  Others:         	NULL
*************************************************/
void fillData(CharCatalog* charCata,int stNum,int ind[3],charinfo* Chinf,int len)
{
	charCata->startNum = stNum;
	charCata->index[0] = ind[0];
	charCata->index[1] = ind[1];
	charCata->index[2] = ind[2];
	charCata->Chinfo = Chinf;
	charCata->length = len;
}


/*************************************************
  Function:       	fillCharinfo
  Description:   	配置传入的chinf识别特征
  Calls:          	NULL
  Called By:      	init_char
  Input:         
					chinf, charinfo类型的字符结构
					num,	keynum
					ch,		具体字符	如：‘A’,'3'
					len,	此字符特征数字串的长度
  Output:         	NULL
  Return:         	void
  Others:         	NULL
*************************************************/
void fillCharinfo(charinfo* chinf,int num,char ch,int len)
{
	chinf->keynum = num;
	chinf->ch = ch;
	chinf->length = len;
}


/*************************************************
  Function:       	recognize_char
  Description:      识别验证码中计算得到的4个字符相连的数字串。
  Calls:          	binarySearch
  Called By:      	main
  Input:         
					charmap, 	预设好的字符特征数据结构
					arr[],		包含4个字符的数字串的int数组
					characters,	保存4个将被识别的字符char数组
  Output:         	NULL
  Return:         	void
  Others:         	arr[0] 是数字串的长度
*************************************************/
void recognize_char(CharCatalog* charMap,int arr[],char* characters){
	int y,firstDigit;
	int intarr[14];   //判断字符最多需要13位,使用intarr[1]~intarr[13]
	int currpos,pos2arr = 1;  //pos2arr是判断上一个字符时的位置
	int charIndex = 0;  //characters[charIndex]
	int numIndex[] = {10,1,2,3,4,5,6,7,9,11,13};
	charinfo chinfo;

	while(charIndex < 4 && pos2arr <= arr[0]){
		currpos = pos2arr;
		for(currpos;arr[currpos] == 0 && currpos <= arr[0];currpos++){	//arr[0] is the length of  Digit Sequence
			// if arr[pos2arr] == 0
			pos2arr++;
		}

		for(y = 0;y < 14 ;y++){       //clear
			intarr[y] = 0;
		}
		for(y = 1; y < 14 && currpos <= arr[0] ;y++){		//copy digital sequence to intarr[] first
			intarr[y] = arr[currpos];
			currpos++;
			if(arr[currpos] == 0)
				break;
		}

		firstDigit = intarr[1];
		for(y = 1;numIndex[y] != firstDigit && y < numIndex[0];y++){
		}
		y -= 1; //subfix :0....x

		chinfo = binarySearch(&charMap[y],intarr);
		characters[charIndex] = chinfo.ch;
		charIndex ++;
		pos2arr += chinfo.length;
	}
}


/*************************************************
  Function:       	binarySearch
  Description:      根据keynum用二分搜索法来搜索预设好的字符特征结构，获得当前字符表示
  Calls:          	NULL
  Called By:      	recognize_char
  Input:         
					charmap, 	预设好的字符特征数据结构
					arr[],		包含4个字符的数字串的int数组
  Output:         	charinfo chinfo ,chinfo获得搜索得到的字符
  Return:         	chinfo
  Others:         	NULL
*************************************************/
charinfo binarySearch(CharCatalog* charMap,int arr[])
{
	//arr 传递特征数字串
	int min,max,keynum;
	int index0,index1,index2;
	charinfo chinfo,tmp;
	chinfo.keynum = -1;
	chinfo.ch = ' ';
	chinfo.length = -1;
	max = charMap->length;
	//calculate keynum according to charMap's rule.
	index0 = charMap->index[0];
	index1 = charMap->index[1];
	index2 = charMap->index[2];
	keynum = arr[index0]+arr[index1]+ 4 * arr[index2]; //获取识别关键数字
	for(min = 1  ;min<= max ;){
		int mid = (min+max)/2;
		tmp = charMap->Chinfo[mid-1]; //Chinfo[O]....X
		if( keynum == tmp.keynum ){
			chinfo = charMap->Chinfo[mid-1];
			break;
		}
		if( keynum > tmp.keynum ){
			min = mid+1;
		}
		if( keynum < tmp.keynum ){
			max = mid-1;
		}
	}
	return chinfo;
}


/*************************************************
  Function:       	main
  Description:    	main
  Calls:         
					cvLoadImage,
					cvCreateImage,
					cvNamedWindow,
					cvShowImage,
					cvCvtColor,
					cvWaitKey,
					cvReleaseImage,
					cvDestroyWindow,
					point2image,
					init_char,
					accumulatePoint,
					recognize_char
  Called By:      	NULL
  Input:          argv[1]:the location of  image that will be processed
  Output:         NULL;
  Return:         0
  Others:        NULL
*************************************************/


/*************************************************
  Function:       	point2image
  Description:    	对传入的图像img进行二值化
  Calls:          	NULL
  Called By:      	main
  Input:          	img,从main中传入的待处理的验证码图像
  Output:         	NULL
  Return:         	void
  Others:         	NULL
*************************************************/
void point2image(IplImage* img){
	for(int y = 0; y < img->height; y++){
		uchar* ptr = (uchar*)(img->imageData+y*img->widthStep);
		for(int x = 0 ; x < img->width;x++){
			if(ptr[x]> 100)
				ptr[x] = 255;
			else
				ptr[x] = 0;
		}
	}
}


/*************************************************
  Function:       	printPixel
  Description:    	把验证码图像的二值结果，图像的height,width输出
  Calls:          	NULL
  Called By:      	main 
  Input:          img,从main中传入的待处理的验证码图
  Output:         	NULL
  Return:         	void
  Others:         	NULL
*************************************************/
void printPixel(IplImage* img){
	for(int y = 0; y < img->height; y++){
		uchar* ptr = (uchar*)(img->imageData+y*img->widthStep);
		printf("\n");
		for(int x = 0 ; x < img->width;x++){
			if(ptr[x]== 255)
				printf("+");
			else
				printf("X");
		}
	}
	printf("\nimage height: %d\n",img->height);
	printf("image width: %d\n",img->width);
}


/*************************************************
  Function:       	accumulatePoint
  Description:    	根据img的二值情况对arr[] 进行从上向下投影，并累加值。
  Calls:          	NULL
  Called By:      	main 
  Input:          	img,已经二值化的图像，

  Output:			arr[],等待获取图像特征数字串的int数组
  Return:         	void
  Others:         	NULL
*************************************************/
void accumulatePoint(IplImage* img,int arr[])
{
	int x,y,z ;
	int acc_arr[100]={0};//don't forget to initialize.
	for(x = 0;x < img->width;x++){ //arr[0] is the length of Digit Sequence
		for(y = 0 ;y < img->height;y++){
			uchar* ptr = (uchar*)(img->imageData+y*img->widthStep);
			if(ptr[x] == 0){
				acc_arr[x] ++;
			}
		}
	}

	//get the length of Digit Sequence
	for( x =0 ; acc_arr[x] == 0 ; x++ ){
	}
	for( y = 99 ; acc_arr[y] == 0 ; y-- ){
	}
	arr[0] = y-(x-1);
	//fill arr[] from acc_arr[x] to acc_arr[y]
	for(x,z=1;x<=y;x++,z++){
		arr[z]=acc_arr[x];
	}
}



const char* configuration( const char* cv_file_name ) {
	int arr[101]={0}; //arr[0] is length (=100) ,from arr[1]~arr[100]
	CharCatalog* test;
	char characters[4] = {'?','?','?','?'};
	int x;
	test = init_char(); 
	IplImage* in;
	
	try {
	    in = cvLoadImage( cv_file_name );
	} catch (...) {
	    cerr << "Couldn't load image!" << endl;
	}
	IplImage* out = cvCreateImage(
						cvGetSize(in),
						IPL_DEPTH_8U,
						1);

	// cvNamedWindow("CST_CAPUTER",CV_WINDOW_AUTOSIZE);

	cvCvtColor(in,out,CV_RGB2GRAY); 

	point2image(out);

	// cvShowImage("CST_CAPUTER",out);

	// printPixel(out);

	accumulatePoint(out,arr);


	//data_process
	recognize_char(test,arr,characters);
	// printf("length:%d\n",arr[0]);
	// for(x = 1; x <= arr[0];x++){
	//     printf("arr[%d]:%d ",x,arr[x]);
	// }
	// printf("\n");
	// printf( "%s\t: %c%c%c%c\n", cv_file_name, characters[0],characters[1],characters[2],characters[3]);

	// cvWaitKey(0); //wait
	//clear
	cvReleaseImage(&in);
	cvReleaseImage(&out);
	// cvDestroyWindow("CST_CAPUTER");
	
	string value(characters);
	value = value.substr( 0, 4 );
	
	// DEBUG
	// cout << "==== VALUE ====" << endl;
	// cout << value << endl;
	// cout << "size: " << value.size() << endl;
	
	return value.c_str();
}

