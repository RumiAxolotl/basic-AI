#include<stdio.h>
#include<iostream>
#define MAX 100 

using namespace std;

void InArray ( int GraphArray[][MAX] , int ArraySize ){
	for ( int x = 0 ; x < ArraySize ; x++ ){
		for ( int y = 0 ; y < ArraySize ; y++ ){
			cout<<" Enter the value of element [ "<< x + 1 <<" : "<< y + 1 <<" ] : "; 
			cin>> GraphArray[x][y];	
		}
		cout<<endl;
	}
}

void OutArray ( int GraphArray[][MAX] , int ArraySize ){
	for ( int x = 0 ; x < ArraySize ; x++ ){
		for ( int y = 0 ; y < ArraySize ; y++ )
			cout<<"["<< GraphArray[x][y]<<"]";	
		cout<<endl;
	}
}

void PrintColorUsed(int CheckFlag[MAX] ,int ArraySize ,int ColorNumber){
	cout << "The number of colors used is: "<< ColorNumber << endl;  
	cout << "The colors used for the points are: "<<endl;
	int Size = 0;
	int color = 1;
	while ( Size < ArraySize ){
		cout << "Color " << color << " : ";
		for (int i = 0; i < ArraySize ;i++){	
		 	if ( CheckFlag[i] == color ){
		 		cout<< "["<<i + 1<<"] ";  
				Size++;	 
			}
		} color++; cout << endl; 
	}
}

// Ham tim mot bat cua dinh 
int OneHierarchy ( int GraphArray[][MAX] , int ArraySize, int Row){
	int Hierarchy = 0; //Bien luu bat cua dinh duoc xet
	for ( int i = 0 ; i < ArraySize; i++ )
		Hierarchy = Hierarchy + GraphArray[Row][i];
	return Hierarchy; 
} 

//Ham tim bat cua tat ca cac dinh 
int  AllHierarchy ( int GraphArray[][MAX] , int ArraySize, int Hierarchy[MAX]){
	for ( int i = 0 ; i < ArraySize ; i++ ){
		Hierarchy[i] = OneHierarchy( GraphArray , ArraySize , i );
	} 
	cout<<endl; 	 
}

// Ham sap xep lai theo bat 
void SortHierarchy( int GraphArray[][MAX], int ArraySize ,int Hierarchy[MAX] ) {
	int temp;
	for ( int i = 0 ; i < ArraySize ; i++ )
		for (int j = i + 1; j < ArraySize ; j++ ){
			if ( Hierarchy[i] < Hierarchy[j]){
				 temp = Hierarchy[i];
				 Hierarchy[i] = Hierarchy[j];
				 Hierarchy[j] = temp; 
				 
				 for (int k = 0; k<ArraySize ; k++){
				 	temp = GraphArray[i][k];
					GraphArray[i][k] = GraphArray[j][k];
					GraphArray[j][k] = temp; 
				 }
			} 
		} 	
}


// Ham to mot mau cho tat ca cac dinh co the to 
int DrawOneColor ( int GraphArray[][MAX] , int ArraySize ,int CheckFlag[] , int Color, int RowCount ){
	int  CountPoint = 0;		// Diem so dinh da duoc to
	// Lan luoc duyet tat ca cac dinh 
	for ( int i = 0 ; i < ArraySize ; i++ ) 
		if  ( CheckFlag[i] == 0 && GraphArray[RowCount][i] == 1 ){
			CheckFlag[i] = Color;
			CountPoint++;
		}
	return CountPoint; 
} 

// Ham to mau tat ca cac dinh tren do thi  
int DrawAllColor ( int GraphArray[][MAX] , int ArraySize , int CheckFlag[] ){
	// Danh dau tat cac cac dinh chua di qua 
	for ( int i = 0 ; i < ArraySize ; i++ )
		CheckFlag[i] = 0;
		
	int ColorNumber = 0; 		// Bien luu so mau 
	int PointCount = 0;			// Bien diem so dinh da duoc to 
	int RowCount = 0;
	 
	// To mau cho den khi nao so diem to duoc bang so dinh  
	while ( PointCount < ArraySize && RowCount < ArraySize){															// Tang so mau 
		ColorNumber++;
		PointCount = PointCount + DrawOneColor( GraphArray , ArraySize , CheckFlag , ColorNumber, RowCount); 	// So dinh to duoc 	
		RowCount++ ;
	}
	return ColorNumber; 
} 

int main (){
	int GraphArray[MAX][MAX] = { 
									{ 0 , 1 , 1 , 0 , 1 , 0 },
									{ 1 , 0 , 0 , 0 , 1 , 0 },
									{ 1 , 0 , 0 , 1 , 0 , 1 },
									{ 0 , 0 , 1 , 0 , 0 , 1 },
									{ 1 , 1 , 0 , 0 , 0 , 0 },
									{ 0 , 0 , 1 , 1 , 0 , 0 }
																};
	int ArraySize = 6;
	int ColorNumber = 0;
	int CheckFlag[MAX];
	int Hierarchy[MAX];
	
//	cout<<"Your array size: ";
//	cin >> ArraySize; 
//		while ( ArraySize <= 0 ){
//			cout << " The number of elements must be more than 0. Please re-enter the number of elements of the array: "; 
//			cin >> ArraySize; 
//		} 
//		 
//	cout<<"----Import your array--- "<<endl;
//	InArray(GraphArray, ArraySize); 
//	 

	cout << "Your array size: " << ArraySize << endl;
	cout << "Your Array: " <<endl; 
	OutArray( GraphArray , ArraySize ); 
	
// Tinh bat cua tat ca cac dinh 
	AllHierarchy( GraphArray , ArraySize , Hierarchy);
// Sap xep lai cac bat 
	SortHierarchy( GraphArray, ArraySize, Hierarchy) ;
	
	cout <<  "Array after sorted: "<<endl; 
	OutArray( GraphArray , ArraySize ); 
	
// To mau 
	ColorNumber = DrawAllColor( GraphArray , ArraySize , CheckFlag );

//In So mau 
	PrintColorUsed( CheckFlag , ArraySize , ColorNumber);	
} 
