#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


#define MAX 102
void draw_mine( unsigned char* pArray , int cx , int cy ) ;
void initial( unsigned char* pArray  );
void getstring(  unsigned char* pArray , int n );
unsigned int n,m;
unsigned char MineArray[MAX][MAX] ={0x31};
unsigned int ax[] = { -1 , 0,  1, -1 , 1 , -1,0 , 1 };
unsigned int ay[] = { -1 , -1, -1, 0  , 0 ,  1,1 , 1 };
typedef struct {
	int n;
	int m;
	unsigned char pAarray[MAX][MAX];
}ITEM;

ITEM buf[MAX];


int main(){
	unsigned int i , j ; 	
	int step = 0;
        unsigned char *pAarray; 	
	while( scanf("%d %d", &n ,&m ) == 2 ){

		if(  m ==0 || n == 0 ) { break ;}
		if(  n > 100 || m > 100 ) { continue ; }
		pAarray = NULL;
		ITEM  item ;
		item.n = n ; item.m = m;
		buf[step] = item;
		initial( buf[step].pAarray );
		getstring( buf[step].pAarray , n );
		for( i = 1 ; i <= n ; i++ ) { 
			for ( j = 1; j <= m ; j++ ){
				if( buf[step].pAarray[ i * MAX ][j]  == '.' ) 
					draw_mine( buf[step].pAarray, i , j );
			}
		}			
		step++;
	}
	int idx ;
	for( idx = 0 ; idx < step ; idx++ ) {
		printf("Field #%d:\n" , idx+1 ) ; 
		for( i = 1 ; i <= buf[idx].n ; i++ ) { 
			for ( j = 1; j <= buf[idx].m ; j++ ){
				printf("%c", buf[idx].pAarray[ i * MAX ][j] );
			}
			printf("\n");
		}
		printf("\n");
			
	}
	printf("\n");

	return 0;
}
void initial( unsigned char* pArray  ) {
	int i , j ;
	for( i = 0 ; i < MAX ; i++ ) {
		for( j = 0 ; j < MAX ; j++ ) {
			*( pArray + ( i * MAX) + j ) = 0x00 ; 	
		}		
	}
}

void getstring(  unsigned char* pArray , int n ) {
	int i , j ;
	for( i = 1 ; i <= n ; i++ ) {
		scanf( "%s" , pArray + ( i * MAX ) + 1 );  
	}
}

void draw_mine( unsigned char* pArray , int cx , int cy ) {
	int minenum = 0;
	unsigned char bit ;
	int i = 0;
	
	for( i = 0 ; i < 8 ; i++ ) {
		if( *(pArray + ( cx + ax[i] )* MAX + cy + ay[i]) == '*' ) {
			minenum++;
		}
	}


	*(pArray + ( cx * MAX)  + cy ) = minenum + '0' ;
}


