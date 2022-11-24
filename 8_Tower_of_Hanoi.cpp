#include <bits/stdc++.h>
#include<stdlib.h> 

using namespace std;
int StartArray[3][3] = {
							{1,0,0},
							{2,0,0},
							{3,0,0}	
										};
int HCost[3][8] = {
						{1,0,0,0,0,0,0,0},
						{2,2,0,1,0,0,0,1},
						{3,3,3,3,0,1,2,2}	
											};	
int H = 0;
int G = 0;
int F = 0;		
int Final = 0;	
int Min;
int Row = 4 , Collum = 4; 
int TempRow = 4; 
int PassCollum = 4, TempPassCollum = 4; 
int PassDisk = 0, TempPassDisk = 0; 

void OutArray(int Array[3][3]){										
	for ( int i = 0; i < 3; i++)
		 cout <<"     I    ";
	cout << endl; 
	for ( int x = 0 ; x < 3 ; x++ ){
		for ( int y = 0 ; y < 3 ; y++ ){
			if (Array[x][y] == 0)
				cout <<"     I    ";	 
			if (Array[x][y] == 1)
				cout <<"    ---   ";
			if (Array[x][y] == 2)
				cout <<"   -----  ";
			if (Array[x][y] == 3) 
				cout <<"  ------- ";
			}
		cout<<endl;
	}
	cout << "[=============================]";
	cout << endl; 
}

void OutArray2(int Array[3][3]){
	for ( int x = 0 ; x < 3 ; x++ ){
		for ( int y = 0 ; y < 3 ; y++ )
			cout<<"["<<Array[x][y]<<"]";	
		cout<<endl;
	}
}

void Swap( int &NumberA , int &NumberB ){
	int Temp = NumberA;
	NumberA = NumberB; 
	NumberB = Temp; 
} 

int CheckH (int Array[3][3] , int Y){
	for ( int H = 0 ; H < 8 ; H++ )
		if ( Array[0][Y] == HCost[0][H] ) 
			if ( Array[1][Y] == HCost[1][H] )
				if ( Array[2][Y] == HCost[2][H] )
					return H; 
} 

int CopyArray ( int ArrayCopy[3][3] ,int ArrayPaste[3][3]){
	for ( int x = 0 ; x < 3 ; x++ )
		for ( int y = 0 ; y < 3 ; y++ )
			ArrayPaste[x][y] = ArrayCopy[x][y];
}

int CheckDisk (int Array[3][3] , int Y ){
	for (int X = 0; X < 3; X++){
		if (Array[X][Y] == 1){
			TempRow = X; 
			cout << "[CheckDisk]  Return 1" << endl; 
			return 1;  
		}
		if (Array[X][Y] == 2){
			TempRow = X;
			cout << "[CheckDisk]  Return 2" << endl; 
			return 2;
		}
		if (Array[X][Y] == 3){
			TempRow = X; 
			cout << "[CheckDisk]  Return 3" << endl;
			return 3;
		}
	}
	return 0; 
} 

void  DownDisk  (int Array[3][3]){
	for ( int Y = 0; Y < 3 ; Y++ ) 
		for ( int X = 0; X < 2 ; X++ )
			if  (Array[X][Y] != 0 && Array[X+1][Y] == 0)
				Swap(Array[X][Y], Array[X+1][Y]); 
} 

int Caculation(int Array[3][3] , int Disk){ 
	cout << "[Caculation]Disk get: "<< Disk << endl;
	H = CheckH(Array, 2);
	F = G + H;
	cout << "[Caculation]Fcheck: "<< F << endl; 
	if ( Min >= F ){
		Min = F;
		cout << "[Caculation]Min update: "<< Min << endl; 
		CopyArray( Array , StartArray ); 
		Final = H; 
		TempPassCollum = Collum;
		cout << "[Caculation]TempPassCollum update: "<< TempPassCollum << endl;
		TempPassDisk = Disk; 
		cout << "[Caculation]TempPassDisk update: "<< TempPassDisk << endl;
	}  
} 

int CheckPass (int Array[3][3] , int Y){
	if (PassCollum == Y )
		if (PassDisk == Array[Row][Collum])
			return 1;
	return 0; 
} 

int  MoveDisk (int TempArray[3][3] ){
	// Mang thuc hien tinh toan 
	int TestArray[3][3] = {	{0,0,0},
							{0,0,0},
							{0,0,0}};
	// Xet tung cot 
	for (int MoveY = 0; MoveY < 3; MoveY++){
		cout <<endl<<"[MoveDisk]Check MoveY: "<< MoveY << endl;
		// Kiem tra xem co di chuyen dia sang cot nao ko
		cout<< endl << "[Row and Collum] "<< Row << " " << Collum<< endl; 
		
		if  ( MoveY != Collum ) {
			CopyArray( TempArray , TestArray ); 
			int Move = CheckDisk( TestArray, MoveY);
			cout << "[MoveDisk] Mive " << Move << endl; 
			if ( TestArray[Row][Collum] == 1 && CheckPass(TestArray, MoveY) == 0){
				Swap( TestArray[Row][Collum], TestArray[0][MoveY] );
				cout << "[MoveDisk] Result MoveY 1" << endl; 
				DownDisk(TestArray);
				OutArray2(TestArray);
				if (CheckH(TestArray , 0 ) != 0 ) 
					Caculation(TestArray,TempArray[Row][Collum]);
				}
			if ( TestArray[Row][Collum] == 2 && Move != 1 && CheckPass(TestArray, MoveY) == 0 ){
				Swap( TestArray[Row][Collum], TestArray[0][MoveY] );
				cout << "[MoveDisk] Result MoveY 2" << endl;
				DownDisk(TestArray);
				OutArray2(TestArray);
				if (CheckH(TestArray , 0 ) != 0 ) 
					Caculation(TestArray,TempArray[Row][Collum]); 
				} 
			if ( TestArray[Row][Collum] == 3 && Move == 0 && CheckPass(TestArray, MoveY) == 0 ){
				Swap( TestArray[Row][Collum], TestArray[0][MoveY] );
				cout << "[MoveDisk] Result MoveY 3" << endl; 
				DownDisk(TestArray);
				OutArray2(TestArray);
				if (CheckH(TestArray , 0 ) != 0 ) 
					Caculation(TestArray,TempArray[Row][Collum]);
				}				
		}
	}	 
}

int AKT(){
// 	Bien luu mang start; x 
	int TempArray[3][3] = {{0,0,0},
						   {0,0,0},
						   {0,0,0}};
	
	H = CheckH(StartArray, 2); 
	Final = H; 
	while ( Final != 0) {
		cout <<endl<<"[AKT] While: "<< G << endl;
		G++;				// Cap nhat gia tri G
		Min = 999999; 
// 	Chep mang vao mang tam de thuc hien tinh toan 
		CopyArray( StartArray , TempArray );
		// Kiem tra theo cot
		for (int X = 0 ; X < 3 ; X++){
			cout <<"[AKT] Check of Collum: "<< X << endl;
			// Kiem tra xem cot do co dia ko 
			if ( CheckDisk( TempArray, X ) != 0 ){
				Collum = X; 
				Row = TempRow; 
				MoveDisk(TempArray); 
				cout << endl << "[AKT] Loop of Collum: "<< X  << endl; OutArray2(StartArray); cout << endl;
			}
		}
		cout<< "[AKT] End "<< endl; 
		PassCollum = TempPassCollum;
		cout << "[AKT] PassCollum update: "<< PassCollum << endl;
		PassDisk = TempPassDisk; 
		cout << "[AKT] PassDisk update: "<< PassDisk << endl;
		cout << endl;
		OutArray(StartArray);
		cout << endl;
	}
	cout << "Number of disk moves: "<< G;	
}

int main (){
	cout << "Start status: " << endl; 
	OutArray(StartArray);
	AKT();
} 
