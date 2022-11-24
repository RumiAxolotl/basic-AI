#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#define MAX 100 
using namespace std;

struct Point {
	int Number; 	// So thu tu
	int Gx ; 		// Khoang cach tinh tu dinh bat dau den dinh
	int Fx ;		// F = H(x) + G(x)
	int Hx ;		// Duong di co khoang cach ngan nhat
	int Flag;		// Danh dau dinh da di qua
	int First;		// Dinh da di truoc do
};
 

Point Open[MAX];	// Hang cho diem chua duoc di qua 
Point Close[MAX];	// Danh dau cac diem da duoc di qua; 
Point P[MAX]; 		// Diem dau hang cho 

// Xuat chi phi uoc tinh 
void OutEArray (int Array[MAX], int ArraySize){
	for ( int i = 0 ; i < ArraySize ; i++ )
			cout<<"["<<Array[i]<<"]";	
		cout<<endl;
} 

// Xuat chi phi thuc te 
void OutTArray (int Array[][MAX], int ArraySize){
	for ( int x = 0 ; x < ArraySize ; x++ ){
		for ( int y = 0 ; y < ArraySize ; y++ )
			cout<<"["<<Array[x][y]<<"]";	
		cout<<endl;
	}
}

void Init(int ArraySize, int ArrayECost[MAX]) {
	for (int i = 0; i < ArraySize; i++){
		P[i].Number = i;
		P[i].Flag = 0;
		P[i].Gx = ArrayECost[i];
		P[i].Fx = P[i].Gx;
		P[i].Hx = 0;
		P[i].First = 0;
	}
}

// Ham kiem tra xem trong hang doi con phan tu nao khong
int Count(int ArraySize, Point *Open){
	int count = 0;
	for ( int i = 0 ; i < ArraySize ; i++ ){
		if (Open[i].Flag == 1)
			count++;
	}
	return count;
}

// Ham tim thu tu cua diem
int FindNumber(int n, Point *Open){
	for (int i = 0; i < n ; i++)
		if (Open[i].Flag == 1)
			return i; 
	return -1;
}

// Ham tim diem nho hat trong hang doi
int FindMinPoint(int ArraySize, Point *Open){
	int MinNumber = FindNumber(ArraySize, Open);	// Bien luu so thu tu diem 
	int Min = Open[MinNumber].Fx;					// Bien luu gia tri F nho nhat
	for (int i = 0; i < ArraySize; i++){
		if (Open[i].Fx < Min && Open[i].Flag == 1){
			MinNumber = i;
			Min = Open[i].Fx;
		}
	}
	return MinNumber;
}

int FindPoint( int ArraySize, Point *P, int Point){
	for (int i = 0 ; i < ArraySize ; i++ )
		if ( P[i].Number == Point )
			return i;
	return -1;
}

void AStar(int ArrayTCost[][MAX], int ArrayECost[MAX], int ArraySize, int Start, int End){
	int OLength = 0;				// So phan tu trong hang doi 
	Open[OLength] = P[Start];		// Lay diem dau tien vao hang doi 
	Open[OLength].Flag = 1; 		// Danh dau diem bat dau da duoc di qua
	Open[OLength].Fx = Open[OLength].Hx + Open[OLength].Gx;
	OLength++;
	int Clength = 0;					// So phan tu da duoc di qua

	while ( Count( OLength , Open ) != 0 ){ 		// Kiem tra trong hang doi con phan tu nao ko
		int Min = FindMinPoint( ArraySize , Open ); // Tim diem nho nhat trong hang doi
		Open[Min].Flag = 2;							// Tien hanh cho diem tim duoc vao trong Close
		Close[Clength] = Open[Min];
		Close[Clength].Flag = 2; 
		Clength++; 
		
		P[FindPoint( ArraySize, P , Open[Min].Number)].Flag = 2;
		if (FindPoint(ArraySize, P , Open[Min].Number) == End ){
			// In duong di; 
			cout << "Route: "<< endl;
			cout << End << " >> ";
			int This = FindPoint( Clength , Close , End );
			int Front = Close[This].First;
			cout << Front << " >> ";
			while (Front != Start){
				This = FindPoint( Clength , Close , Front );
				Front = Close[This].First;
				if (Front == Start) 
					cout << Front; 
				else
					cout << Front << " >> ";
			} 
			break;
		}
		else
			for ( int i = 0; i < ArraySize; i++ ){
				// Truong hop chua diem co trong Open va Close 
				if ( ArrayTCost[FindPoint( ArraySize, P , Open[Min].Number)][i] != 0 && P[i].Flag == 0){
					Open[OLength] = P[i]; 
					Open[OLength].Flag = 1; 
					// Tinh khoan cach tu diem dau den diem dich 
					Open[OLength].Hx = ArrayTCost[FindPoint(ArraySize, P , Open[Min].Number)][i] + Open[Min].Hx; 
					Open[OLength].Fx = Open[OLength].Gx + Open[OLength].Hx;
					Open[OLength].First = FindPoint( ArraySize , P , Open[Min].Number);
					P[i].Flag = 1;
					OLength++;
				}
				// Truong hop diem do da co trong Open 
				if ( ArrayTCost[FindPoint( ArraySize, P , Open[Min].Number )][MAX] != 0 && P[i].Flag == 1){
					int point = FindPoint( OLength , Close , P[i].Number );
					Point TempPoint = P[i];
					TempPoint.Flag = 1; 
					TempPoint.Hx = ArrayTCost[FindPoint( ArraySize , P , Open[Min].Number )][i] + Open[Min].Hx;
					TempPoint.First = Min;
					TempPoint.Fx = TempPoint.Hx + TempPoint.Gx;
					// Neu Fx hien tai nho hon gia tri truoc do thi qua ve diem phi truoc
					if (TempPoint.Fx < Open[point].Fx)
						Open[point] = TempPoint; 
				}
				// Truong hop diem co trong Close 
				if ( ArrayTCost[FindPoint( ArraySize, P , Open[Min].Number )][i] != 0 && P[i].Flag == 2){
					int point = FindPoint( OLength , Close , P[i].Number );
					Point TempPoint = P[i];
					TempPoint.Flag = 1; 
					TempPoint.Hx = ArrayTCost[FindPoint( ArraySize , P , Open[Min].Number )][i] + Open[Min].Hx;
					TempPoint.First = Min;
					TempPoint.Fx = TempPoint.Hx + TempPoint.Gx;
					if (TempPoint.Fx < Close[point].Fx){
						Open[OLength] = TempPoint;			// them diem vao Open 
						Close[point].Flag = 1;				// danh dau diem do thuoc Open  
						OLength++; 		 					// Cap nhat lai so luong phan tu trong Open  
					}
				} 
			} 
		}
	}


int main (){
	int ArrayTCost[MAX][MAX] = {
								{ 0 , 2 , 0 , 5 , 0 , 0 , 0 , 0 , 0 },
								{ 2 , 0 , 2 , 0 , 0 , 0 , 0 , 0 , 0 },
								{ 0 , 2 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },
								{ 5 , 0 , 0 , 0 , 3 , 0 , 1 , 0 , 0 },
								{ 0 , 0 , 0 , 3 , 0 , 1 , 0 , 3 , 0 },
								{ 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 , 0 },
								{ 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 },
								{ 0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 , 1 },
								{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 },
																		};
	int ArrayECost[MAX] = { 4 , 3 , 2 , 3 , 2 , 1 , 2 , 1 , 0 };
	int ArraySize = 9; 
	int Start = 0; 
	int End = 8; 
	cout << "Nhap diem bat dau: 0" << endl;
	cout << "Nhap diem ket thuc: 8" << endl; 
	 
	cout << "Estimated Cost: " << endl;
	OutEArray ( ArrayECost, ArraySize);
	cout << "True Cost: " << endl;
	OutTArray ( ArrayTCost, ArraySize);
	Init( ArraySize , ArrayECost );
	AStar( ArrayTCost , ArrayECost , ArraySize , Start , End );
} 
