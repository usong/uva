#include <stdio.h>
/*
s + 2
2s + 3
*/
#define N 6
#define M 49 
/*
char S1[N][M]= { 
	"0000 000",
	"00-0 000",
	"0|0| 00|",
	"0000 000",
	"0|0| 00|",
	"00-0 000",
};
*/
char S1[6][49]= { 
	"0000 000 000 000 000 000 000 000 000 000",
	"00-0 000 0-0 0-0 000 0-0 0-0 0-0 0-0 0-0",
	"0|0| 00| 00| 00| |0| |00 |00 00| |0| |0|",
	"0000 000 0-0 0-0 0_0 0-0 0-0 000 0-0 0-0",
	"0|0| 00| |00 00| 00| 00| |0| 00| |0| 00|",
	"00-0 000 0-0 0-0 000 0-0 0-0 000 0-0 0-0",
};
int main(){
	int n  = N, m = M , s , num ,start ,runtimes ;
	int i , j , k , idx;
	char nums[11]  = {0x00};
	while( scanf("%d %s", &s ,nums ) == 2 ) {
		int step ;
		for( i = 1 ; i <= n ; i++ ) {
			if( i % 2 ) {
				for( idx = 0 ; idx < strlen( nums ) ; idx++ ) {
					int num = nums[idx] - '0';
					start = ( num * 4 ) % M + 1 ; //first  position
					for( j = start ; j < start + 4; j++ ) {
						if( j % 2 ) {	
							if( S1[i][j] == '0' ) {
								printf("%c",' ');
							}
							else {
								printf("%c",S1[i][j]);
							}
						} else {
							
							for( step = 0 ; step < s ; step++ ) {
								if( S1[i][j] == '0' ) {
									printf("%c",' ');
								}
								else {
									printf("%c",S1[i][j]);
								}
							}
						}
					}
				
				}
			} else {
				
				for( k = 0 ; k < s ; k++ ) {
					for( idx = 0 ; idx < strlen( nums ) ; idx++ ) {
						int num = nums[idx] - '0' ;
						start = ( num * 4 ) % M + 1 ; //first  position
						for( j = start ; j < start +  4 ; j++ ) {
							if( j % 2 ) {
								if( S1[i][j] == '0' ) {
									printf("%c",' ');
								}
								else{ 
									printf("%c",S1[i][j]);
								}
							} else {
								for( step = 0 ; step < s ; step++ ) {
									if( S1[i][j] == '0' ) {
										printf("%c",' ');
									}
									else {
										printf("%c",S1[i][j]);
									}
								}
							}
						}						
						
					}
					if( k+1 < s )
							printf("\n");
				}


			}
			printf("\n");	
		}
	
	
	}


	return 0;
}

