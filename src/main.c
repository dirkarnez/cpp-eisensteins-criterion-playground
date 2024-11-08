//Eisentein's criterion
#include<stdio.h>
#include<gmp.h>



void printarr(mpz_t *arr, int degree) {
    printf("\n");
    int k = degree;
    for (int i = 0; i <= degree; i++) {
        gmp_printf("%Zdx^%d  ", arr[i], k--);
    }
    printf("\n");
}


int main(){
    mpz_t p,h_coef;
    int h; //degree

    mpz_inits(p, h_coef, NULL); 
    mpz_set_ui(p,2);


    printf("Enter highest degree of polynomial:\n");
    scanf("%d", &h); 

   
    mpz_t poly[h+1];
    for (int i = 0; i <= h; i++) {
        mpz_init(poly[i]);
    }
    
    int k = h;
    //taking input
    for (int i = 0; i <= h; i++) {
        printf("Enter coefficients for degree %d of the : ", k--);
        gmp_scanf("%Zd", poly[i]);
        if(mpz_cmp(h_coef, poly[i]) < 0){
        	mpz_set(h_coef, poly[i]);
        }
    }
    
    printarr(poly, h);
    
    //gmp_printf("%Zd \n", h_coef);
    
    for(  ; mpz_cmp(p, h_coef) <= 0; mpz_nextprime(p, p)){
    	//gmp_printf("%Zd \n", p);
    	if(mpz_divisible_p(poly[h], p) == 0){
    		//printf("1...");
    		continue;
    	}
    	for(int i=h-1 ; i<=0; i++){
    		if(mpz_divisible_p(poly[i], p) != 0){
    			//printf("2...");
    			break;
    		}
    	}
    	
    	mpz_t psqr;
    	mpz_init(psqr);
    	mpz_mul(psqr, p, p);
    	//gmp_printf("%Zd", psqr);
    	if(mpz_divisible_p(poly[0], psqr) == 0){
    		//printf("3...");
    		continue;
    	}
    	
    	gmp_printf("%Zd \n", p);
    	return 0;
    	
    }
    
    
    printf("Not irreducible... check the given ploynomial.\n");
    
    return 0;
	
}


