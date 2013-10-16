#include <stdio.h>

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
		
		
		while( n != 1 ) {			
			
			if( n % 2 ) { 
				 n = 3 * n + 1;			
				 
			} else {				 
				 n = n / 2;			
						
			}
			step++ ;
			
		} 
		
		if ( step > max ){
			max = step;					
		}
		
	}
	printf(" %d\n",  max );
	}
	return 0;
}