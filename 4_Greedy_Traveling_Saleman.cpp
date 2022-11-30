#include <bits/stdc++.h>
using namespace std;
#define MAX 100 

// void InArray (int Array[][MAX], int ArraySize){
// 	for ( int x = 0 ; x < ArraySize ; x++ ){
// 		for ( int y = 0 ; y < ArraySize ; y++ ){
// 			cout<<" Enter the value of element [ "<< x + 1 <<" : "<< y + 1 <<" ] : "; 
// 			cin>>Array[x][y];	
// 		}
// 		cout<<endl;
// 	}
// }

void OutArray (int Array[][MAX], int ArraySize){
	for ( int x = 0 ; x < ArraySize ; x++ ){
		for ( int y = 0 ; y < ArraySize ; y++ )
			cout<<"["<<Array[x][y]<<"]";	
		cout<<endl;
	}
}

int GTS1 ( int Array[][MAX], int ArraySize, int Start, int Route[], int &RoutePoint ){		
	int Flag[MAX]; 						// Mang co hieu danh dau cac phan tu da duoc di qua 
	int Current = Start; 				// Tao bien luu vi tri hien tai va gan vi tri hien tai la vi tri bat dau  
	int Next; 							// Bien kiem tra xem duong di con co the di tiep khong 
	int TotalCost = 0;					// Tong chi phi di duoc 
	RoutePoint = 0; 					// Bat dau lo trinh voi khong co diem nao duoc di qua 
	Route[RoutePoint++] = Start; 		// Them diem bat dau vao lo trinh di duoc 
	
	// Danh dau tat ca cac diem chua duoc di qua 
	for ( int Assign = 0 ;  Assign < ArraySize ; Assign++ ){
		Flag[Assign] = 0;  
	}	
	
	Flag[Start] = 1;					// Danh dau vi tri bat dau da di qua 
	
	do {
		int Point = 0;					
		
		//  Tim diem dau tien di qua bat dau tu diem hien tai 
		while ( Point < ArraySize && ( Array[Current][Point] == 0 || Flag[Point] == 1 )) 
			Point++; 
		
		if ( Point >= ArraySize )
			Next = -1;					// Duong di khong con co the di tiep duoc nua 
		
		else {
			Next = Point;
			
			// Tim lo trinh co chi phi thap nhat 
			for ( ; Point < ArraySize ; Point++ )
				if ( Flag[Point] == 0 && Array[Current][Point] < Array[Current][Next] ) 
					Next = Point; 
			
			Route[RoutePoint++] = Next; 		// Them diem vao danh sach cac diem da di qua 
			Flag[Next] = 1;						// Danh dau diem da duoc di qua 
			TotalCost += Array[Current][Next];	// Cap nhat chi phi 
			Current = Next; 					// Gan vi tri tiep theo chinh la vi tri hien tai 
		}	
	} while (Next != -1);
	
	if (RoutePoint < ArraySize)
		return 0;								// Chua di qua tat ca cac diem 
	else {
		if ( Array[Current][Start] ) {			// Co duong di ve diem dau 
			TotalCost += Array[Current][Start];
			return TotalCost;
		} 
		else return 0; 							//Khong co duong di ve diem dau 
	} 	
}			

void GTS2 (int Array[][MAX],int ArraySize,int TotalRoute, int Start[MAX]) {
	int BestCost = 0;							// Bien luu chi phi nho nhat
	int BestRoute[MAX];							// Mang luu lo trinh co chi phi nho nhat
	int TotalCost = 0;							// Tong chi phi
	int RoutePoint; 							// So diem di qua 
	int Route[MAX]; 							// Manf luu lo trinh
	
	// Thuc hien tim duong di theo cac diem bat dau aa nhap
	for (int checkStart = 0 ; checkStart < TotalRoute ; checkStart++ ) {
		// Goi ham tim duong di ngan nhat
		TotalCost = GTS1 ( Array , ArraySize , Start[checkStart] , Route, RoutePoint);
		// neu chi phi tot nhat hien tai bang 0 thi gan chi phi cua lo trinh moi va luu lai lo trinh do 
		if (BestCost == 0){
			BestCost = TotalCost; 
			for ( int i = 0 ; i < RoutePoint ; i++ )
				BestRoute[i] = Route[i]; 
		} else 
			// luu chi phi ngan nhat 
			if ( BestCost > TotalCost ){
				BestCost = TotalCost;
				for ( int j = 0 ; j < RoutePoint ; j++ )
					BestRoute[j] = Route[j]; 
			}	
	}
	
	cout << endl << "The best Route is: " << endl; 
	for( int k = 0 ; k < RoutePoint ; k++ )
				cout << Route[k] + 1 <<" --> ";
				cout << Route[1] - 1 << endl; 
			cout << "Cost : "<< TotalCost << endl;
	
}

int main(){
	int ArraySize = 6;
	int Array[MAX][MAX] = { 
							{  0 , 20 , 42 , 31 ,  6 , 24 },
							{ 10 ,  0 , 17 ,  6 , 35 , 18 },
							{ 25 ,  5 ,  0 , 27 , 14 ,  9 },
							{ 12 ,  9 , 24 ,  0 , 30 , 12 },
							{ 14 ,  7 , 21 , 15 ,  0 , 38 },
							{ 40 , 15 , 16 ,  5 , 20 ,  0 }
															};
	
	int Start[MAX];
	int Route[MAX];
	int TotalCost , RoutePoint , TotalRoute;
	cout<< "Your array size: " << ArraySize << endl;
	cout<< "Your Array: " <<endl;
	OutArray( Array , ArraySize );
	
	cout << endl << "Total number of routes you choose: ";
	cin >> TotalRoute; 
	
	for ( int Choose = 0 ; Choose < TotalRoute ; Choose++ ){
		cout << endl << "Choose starting point number " << Choose + 1 << " : ";
		cin >> Start[Choose];
		Start[Choose] = Start[Choose] - 1;
		}
		
		GTS2( Array , ArraySize , TotalRoute , Start ); 
}


