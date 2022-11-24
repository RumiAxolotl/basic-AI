#include <bits/stdc++.h>
using namespace std;

int MoneyExchange (int Exchange[18], int Money){
	int MoneyNote, 									// Bien luu so to tien da doi 
		Note;										// Bien luu so to tien tam thoi 
		 
	for ( int i = 0 ; i < 18 ; i++ ){
		Note = Money / Exchange[i]; 				// Ghi lai so to tien da doi 
		
		if (Note > 0) 
			cout << Exchange[i] << " VND note: " << Note << endl;

		MoneyNote = MoneyNote + Note; 				// Cap nhat lai so tien da doi 
		Money = Money % Exchange[i];				// Cap nhat so tien con lai 
	} 
	return MoneyNote; 
}
  
int main (){
	// Mang luu menh gia tien co the doi 
	int Exchange[18] = { 500000 , 200000 , 100000 ,
						 50000	, 20000	 , 10000  ,
						 5000	, 2000	 , 1000	  ,
						 500	, 200	 , 100	  ,
						 50		, 20	 , 10	  ,
						 5		, 2		 , 1    	}; 
						 
	int Money; 					// So tien can doi
	int MoneyNote;				// Bien luu so to tien da doi duoc  
	
	cout << "Exchangeable denominations (VND): "<< endl << 
		"	[500000][200000][100000]" << endl <<
		"	[50000 ][20000 ][10000 ]" << endl <<
		"	[5000  ][2000  ][1000  ]" << endl <<
		"	[500   ][200   ][100   ]" << endl <<
		"	[50    ][20    ][10    ]" << endl <<
		"	[5     ][2     ][1     ]" << endl;
		
	cout << "Enter the amount to exchange (VND): ";
	cin >>  Money;
	 
	MoneyNote = MoneyExchange( Exchange , Money );
	
	cout << "The total number of money exchanged is: "<< MoneyNote;
	 
} 
