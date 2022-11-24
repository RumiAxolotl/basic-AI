#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

// Kich thuoc mang [Trong bai nay khong can thiet]
int ArraySize = 3;

// Mang bat dau
int StartArray[3][3] = {
						{2,8,3},
						{1,6,4},
						{7,0,5} 
								};

// Mang dich					
int EndArray[3][3] = {
						{1,2,3},
						{8,0,4},
						{7,6,5} 	
								};

// Mang tam de luu vi tri kiem tra
int TempArray[3][3] = {
						{1,1,1},
						{1,1,1},
						{1,1,1} 	
								};
								
// Mang luu vi tri di chuyen
int Null[2][4] = { { - 1 , 0 , 1 , 0},
				   { 0 , 1 , 0 , -1 }};

// Vi tri cua o trong
int Xnull;	
int Ynull; 	

// ham in mang
void OutArray(int Array[3][3]){
	for ( int x = 0 ; x < ArraySize ; x++ ){
		for ( int y = 0 ; y < ArraySize ; y++ )
			cout<<"["<<Array[x][y]<<"]";	
		cout<<endl;
	}
}
// Ham check xem cac so da ve dung vi tri chua
int CheckFinish(int Array[3][3], int EndArray[3][3]){
	int Count = 0;			//Bien kiem tra da co bao nhieu so sai vi tri 
	for ( int x = 0 ; x < ArraySize ; x++ )
		for ( int y = 0 ; y < ArraySize ; y++ )
			if ( Array[x][y] != EndArray[x][y] )	
				Count++;	// Neu sai vi tri thi tang gia tri bien diem
	return Count;
}

// Ham copy gia tri mang 
int CopyArray ( int ArrayCopy[3][3] ,int ArrayPaste[3][3]){
	for ( int x = 0 ; x < ArraySize ; x++ )
		for ( int y = 0 ; y < ArraySize ; y++ )
			ArrayPaste[x][y] = ArrayCopy[x][y];
}

// ham tim o trong
int FindNull(int StartArray[3][3]){
	for ( int x = 0 ; x < ArraySize ; x++ )
		for ( int y = 0 ; y < ArraySize ; y++ )
			if ( StartArray[x][y] == 0){
				Xnull = x; Ynull = y;	}
}

// Ham thay doi vi tri
void Swap( int &NumberA , int &NumberB ){
	int Temp = NumberA;
	NumberA = NumberB; 
	NumberB = Temp; 
} 
	
// Ham cap nhat lai tat ca cac vi tri chua duoc di qua
void UpdateFlag( int Flag[3][3] ){
	for ( int x = 0 ; x < 3 ; x++ )
		for ( int y = 0 ; y < 3 ; y++ )
			Flag[x][y] = 0;
}
// Ham AKT thuc hien tim duong di
void AKT (){
	int G = 0; 									// So buoc di chuyen
	int H = CheckFinish(StartArray,EndArray);	// So diem sai vi tri
	int F = 0;									// F = H + G			 
	int Final = H;								// Bien luu lai so diem sai vi tri cuoi cung de xet dieu kien 
	
	// Co hieu
	int Flag[3][3] = {			
						{0,0,0},
						{0,0,0},
						{0,0,0} 
								};

	while( Final != 0 ){
		int Min = 9999999;							// Bien luu gia tri nho nhat 
		G++;										// Cap nhat so buoc di chuyen
		CopyArray( StartArray, TempArray);			// Chep du lieu sang mang tam
		FindNull(StartArray);						// Tim vi tri cua o trong
			for (int i = 0; i < 4 ; i++ ){ 	
				
				// Bien luu vi tri dang xet
				int PushX = Xnull + Null[0][i];
				int PushY = Ynull + Null[1][i];
			
				// Kiem tra xem o do co phai o ke ben o rong ko va no da duoc di qua truoc do hay chua 	
				if (Flag[PushX][PushY] != 1 && PushX < 3 && PushY < 3  && PushX > -1 && PushY > -1 ){			
					// Hoan doi vi tri dang xet voi vi tri null trong mang tam  
					Swap( TempArray[PushX][PushY] , TempArray[Xnull][Ynull]); 
					
					H = CheckFinish( TempArray , EndArray); 
					F = G + H; 
					if ( Min > F ) {	// Neu F nho hon Min thi cap nhat lai F va luu lai vi tri do  
						Min = F; 
						CopyArray( TempArray , StartArray);  
						Final = H; 		
					}
					
					// Hoan doi lai nhu cu de tiep tuc kiem tra cac vi tri khac
					Swap( TempArray[PushX][PushY] , TempArray[Xnull][Ynull] );
				}				 
			}
		
		// Cap nhat lai co hieu
		UpdateFlag(Flag);
		Flag[Xnull][Ynull] = 1;
		
		cout << endl << "Number of wrong numbers left: "<<Final<<endl;
		OutArray(StartArray); 
		getch(); 
		}
	cout <<endl << "Number of steps moved: "<< G; 
}

int main (){
	cout << "Start: " << endl;
	OutArray( StartArray);
	cout << endl << "End: " << endl;
	OutArray( EndArray);
	getch(); 
	AKT(); 
} 
