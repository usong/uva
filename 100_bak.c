#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void doit( int n ,int* cnt );
int main(){
	unsigned a , b  ,t , max =0, step ,n = 0; 
	
	while( scanf("%d %d", &a ,&b ) == 2 ){
	printf("%d %d" , a , b);
	if( a < b ) {
		  t = b ;		  b = a ;		  a = t ;  	  	
	}
	
	int i = 0 ;
	max   = 0;
	
	
	for( i = b ; i <= a ; i++ ) {		
		step = 1; n = i;
		
		doit( n , &step );
		/*
		while( n != 1 ) {			
			
			if( n % 2 ) { 
				 n = 3 * n + 1;			
				 
			} else {				 
				 n = n / 2;			
						
			}
			step++ ;
			
		} 
		*/
		if ( step > max ){
			max = step;					
		}
		
	}
	printf(" %d\n",  max );
	}
	return 0;
}

void doit( int n ,int* cnt ) {
	if( n == 1 ) return ;
	if( n % 2 ) { 
				doit( 3 * n + 1 , cnt );	(*cnt)++;
				
	} else {				 
				doit( n / 2 , cnt);				(*cnt)++;		
				
	}
}