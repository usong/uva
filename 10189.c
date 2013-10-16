#include <stdio.h>
#include <string.h>
#define MAX 102
void draw_mine( unsigned char* pArray , int cx , int cy ) ;
void myprocess ( unsigned char* pArray  ,int step ) ;
unsigned int n,m;
unsigned char MineArray[MAX][MAX] ={0x31};
unsigned int ax[] = { -1 , 0,  1, -1 , 1 , -1,0 , 1 };
unsigned int ay[] = { -1 , -1, -1, 0  , 0 ,  1,1 , 1 };
int main(){
	unsigned int i , j ; 	
	int step = 1;
	while( scanf("%d %d", &n ,&m ) == 2 ){

		if(  m ==0 || n == 0 ) { break ;}
		for( i = 0 ; i < MAX ; i++ ) {
			for( j = 0 ; j < MAX ; j++ ) {
				MineArray[i][j] = 0x00 ; 	
			}		
		}
		for( i = 1 ; i <= n  ; i++ ) {
			scanf( "%s" , MineArray[i] + 1 ); 
			
		}
		
	
		for( i = 1 ; i <= n ; i++ ) { 
			for ( j = 1; j <= m ; j++ ){
				if( MineArray[i][j] == '.' ) 
					draw_mine( MineArray, i , j );
			}
		}	
		printf("Field #%d:\n" , step ) ; 
		for( i = 1 ; i <= n ; i++ ) {
			for( j = 1 ; j <= m ; j++ ) {
				printf("%c" , MineArray[i][j] ) ; 	
			}		
			printf("\n");
		}
		printf("\n");
	
		step++;
	}
		

	return 0;
}


void draw_mine( unsigned char* pArray , int cx , int cy ) {
	int minenum = 0;
	unsigned char bit ;
	int i = 0;
	//printf("1:x=%d y=%d\n" , cx  , cy ) ;
	
	for( i = 0 ; i < 8 ; i++ ) {
		//printf("2:  x=%d y=%d" , cx + ax[i] , cy + ay[i] ) ;
		if( MineArray[ cx + ax[i] ][ cy + ay[i] ] =='*' ) {
			minenum++;
		}
	}


	MineArray[cx][cy] = minenum + '0' ;
}


