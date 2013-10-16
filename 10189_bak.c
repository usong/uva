#include <stdio.h>
#include <string.h>
#define MAX 100
void draw_mine( unsigned char* pArray , int cx , int cy ) ;
void myprocess ( unsigned char* pArray  ,int step ) ;
unsigned int n,m;
unsigned char MineArray[MAX][MAX] ={0x31};
int main(){
	unsigned char i; 	
	unsigned char cstr[MAX] ={0} ;
	int step = 1;
	while( scanf("%d %d", &n ,&m ) == 2 ){
		
		/* get two - demension array  */
		if(  m ==0 || n == 0 ) { break ;}
		for( i = 0 ; i < n ; i++ ) {
			scanf( "%s" , MineArray[i] ); 			
		}
		myprocess( MineArray ,step );
		step++;
	}
	return 0;
}

void myprocess ( unsigned char* pArray ,int step   ) {
	int x  , y , head =0 ;
	unsigned char bit ;
	printf("Field #%d:\n", step );
	for( y =0 ; y < n ; y++ ) { 
		for ( x = 0; x < m ; x++ ){
			bit = *( pArray + ( y * sizeof(unsigned char) * MAX)   + x ) ;
			if( bit != '*' ) {
				draw_mine( pArray, x , y );
			}
			printf("%c",*( pArray + ( y * sizeof(unsigned char) * MAX)   + x )  );
			
		}	
		printf("\n");
	}

}
void draw_mine( unsigned char* pArray , int cx , int cy ) {
	int minenum = 0;
	unsigned char bit ;
	/*1*/
	if(    ( 0 <=  cx - 1  &&  cx - 1 < m  )   
	    && ( 0 <=  cy - 1  &&  cy - 1 < m  )   
	  ) {
		bit = *( pArray + ( (cy - 1 ) * sizeof(unsigned char) * MAX)   + (cx - 1) );
		if( bit == '*' ) 
			minenum++;
	}
	/*2*/
	if(   0 <=  cy - 1  &&  cy -1 < m  )   
	{
		bit = *( pArray + ( (cy - 1 ) * sizeof(unsigned char) * MAX)   + cx  );
		if( bit == '*' ) 
			minenum++;
	}
	/*3*/
	if(    ( 0 <=  cx + 1  &&  cx + 1 < m  )   
	    && ( 0 <=  cy - 1  &&  cy - 1 < m  )
	  )  
	{
		bit = *( pArray + ( (cy - 1 ) * sizeof(unsigned char) * MAX)   + ( cx + 1)  );
		if( bit == '*' ) 
			minenum++;
	}
	/*4*/
	if(    ( 0 <=  cx - 1  &&  cx - 1 < m  )   
	    && ( 0 <=  cy   &&  cy  < m  )
	  )  
	{
		bit = *( pArray + ( (cy  ) * sizeof(unsigned char) * MAX)   + ( cx - 1)  );
		if( bit == '*' ) 
			minenum++;
	}
	/*5*/
	if(    ( 0 <=  cx - 1  &&  cx - 1 < m  )   
	    && ( 0 <=  cy + 1   && cy + 1 < m  )
	  )  
	{
		bit = *( pArray + ( (cy +1 ) * sizeof(unsigned char) * MAX)   + ( cx - 1)  );
		if( bit == '*' ) 
			minenum++;
	}
	/*6*/
	if(    ( 0 <=  cx   &&  cx  < m  )   
	    && ( 0 <=  cy + 1   && cy + 1 < m  )
	  )  
	{
		bit = *( pArray + ( (cy +1 ) * sizeof(unsigned char) * MAX)   +  cx  );
		if( bit == '*' ) 
			minenum++;
	}
	/*7*/
	if(    ( 0 <=  cx + 1  &&  cx + 1 < m  )   
	    && ( 0 <=  cy + 1   && cy + 1 < m  )
	  )  
	{
		bit = *( pArray + ( (cy +1 ) * sizeof(unsigned char) * MAX)   +  (cx + 1)  );
		if( bit == '*' ) 
			minenum++;
	}
	/*8*/
	if(    ( 0 <=  cx + 1  &&  cx + 1 < m  )   
	    && ( 0 <=  cy    &&    cy  < m  )
	  )  
	{
		bit = *( pArray + ( (cy  ) * sizeof(unsigned char) * MAX)   +  (cx + 1)  );
		if( bit == '*' ) 
			minenum++;
	}
	*( pArray + ( (cy  ) * sizeof(unsigned char) * MAX)   +  (cx )  ) = minenum + '0';
}

