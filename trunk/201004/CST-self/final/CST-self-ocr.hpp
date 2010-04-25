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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	init_char
�0�2 Description:�0�2�0�2�0�2 	use struct CharNode to initialize 36 characters
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
					malloc,
					fillData,
					fillCharinfo
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	main
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	���ؽ����õ��ַ�����ʶ��ṹ
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	CharCatalog* charList
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	ʶ��ؼ����� keynum = array[index0]+array[index1]+ 4 * array[index2];
					��ȷ�����Ѿ�֪����Ҫ�����ַ����ִ��ĵ�һλ���ֵ�����±���Ψһ��
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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	fillData
�0�2 Description:�0�2�0�2�0�2	���ô����charCataʶ������
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	init_char
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	charCata��������ʾ���ִ���ĳ�����ֿ�ͷ�ַ����ϵĽṹ��
					stNum,���ַ����������ִ��ĵ�һ�����ֱ�ʾ
					ind[3],��������keynum��3�����ִ�λ������
					Chinf,����charCata����еĵ�һ���ַ�����
					len,������е��ַ�����
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	void
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	fillCharinfo
�0�2 Description:�0�2�0�2�0�2	���ô����chinfʶ������
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	init_char
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
					chinf, charinfo���͵��ַ��ṹ
					num,	keynum
					ch,		�����ַ�	�磺��A��,'3'
					len,	���ַ��������ִ��ĳ���
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	void
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
*************************************************/
void fillCharinfo(charinfo* chinf,int num,char ch,int len)
{
	chinf->keynum = num;
	chinf->ch = ch;
	chinf->length = len;
}


/*************************************************
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	recognize_char
�0�2 Description:�0�2�0�2�0�2   ʶ����֤���м���õ���4���ַ����������ִ���
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	binarySearch
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	main
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
					charmap, 	Ԥ��õ��ַ��������ݽṹ
					arr[],		����4���ַ������ִ���int����
					characters,	����4������ʶ����ַ�char����
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	void
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	arr[0] �����ִ��ĳ���
*************************************************/
void recognize_char(CharCatalog* charMap,int arr[],char* characters){
	int y,firstDigit;
	int intarr[14];   //�ж��ַ������Ҫ13λ,ʹ��intarr[1]~intarr[13]
	int currpos,pos2arr = 1;  //pos2arr���ж���һ���ַ�ʱ��λ��
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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	binarySearch
�0�2 Description:�0�2�0�2�0�2   ����keynum�ö���������������Ԥ��õ��ַ������ṹ����õ�ǰ�ַ���ʾ
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	recognize_char
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
					charmap, 	Ԥ��õ��ַ��������ݽṹ
					arr[],		����4���ַ������ִ���int����
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	charinfo chinfo ,chinfo��������õ����ַ�
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	chinfo
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
*************************************************/
charinfo binarySearch(CharCatalog* charMap,int arr[])
{
	//arr �����������ִ�
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
	keynum = arr[index0]+arr[index1]+ 4 * arr[index2]; //��ȡʶ��ؼ�����
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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	main
�0�2 Description:�0�2�0�2�0�2 	main
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2
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
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 argv[1]:the location of  image that will be processed
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 NULL;
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 0
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2NULL
*************************************************/


/*************************************************
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	point2image
�0�2 Description:�0�2�0�2�0�2 	�Դ����ͼ��img���ж�ֵ��
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	main
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	img,��main�д���Ĵ��������֤��ͼ��
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	void
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	printPixel
�0�2 Description:�0�2�0�2�0�2 	����֤��ͼ��Ķ�ֵ�����ͼ���height,width���
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	main�0�2
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 img,��main�д���Ĵ��������֤��ͼ
�0�2 Output:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	void
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
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
�0�2 Function:�0�2�0�2�0�2�0�2�0�2�0�2 	accumulatePoint
�0�2 Description:�0�2�0�2�0�2 	����img�Ķ�ֵ�����arr[] ���д�������ͶӰ�����ۼ�ֵ��
�0�2 Calls:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
�0�2 Called By:�0�2�0�2�0�2�0�2�0�2 	main�0�2
�0�2 Input:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	img,�Ѿ���ֵ����ͼ��

�0�2 Output:			arr[],�ȴ���ȡͼ���������ִ���int����
�0�2 Return:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	void
�0�2 Others:�0�2�0�2�0�2�0�2�0�2�0�2�0�2�0�2 	NULL
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

