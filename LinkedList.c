#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct dugum{
	
	int veri;
	
	struct dugum * gosterici;
	
};

struct dugum * bas = NULL;
struct dugum * gecici = NULL;


void sonaEkle(int sayi){
	
	struct dugum * eklenecek = (struct dugum* )malloc(sizeof(struct dugum));
	eklenecek->veri = sayi;
	eklenecek -> gosterici = NULL;
	
	
	if(bas == NULL){
		bas = eklenecek;
	}
	else{
		gecici = bas;
		while(gecici->gosterici != NULL){
			gecici = gecici -> gosterici;
			
		}
		gecici ->gosterici = eklenecek;
	}	
}

void basaEkle(int sayi){
	
	struct dugum * eklenecek = (struct dugum* )malloc(sizeof(struct dugum));
	eklenecek->veri = sayi;
	eklenecek->gosterici = bas;
	bas = eklenecek;
}

void arayaEkle(int n, int sayi){
	struct dugum * eklenecek = (struct dugum*)malloc(sizeof(struct dugum));
	eklenecek->veri= sayi;
	
	
	gecici = bas;
	while(gecici->gosterici->veri != n ){
		gecici = gecici->gosterici;
	}
	eklenecek->gosterici = gecici->gosterici;
	gecici->gosterici = eklenecek; 
}

void bastanSil(){
	if(bas == NULL){
		printf("Your list already is clean.");
	}
	else{
		gecici = bas->gosterici;
		free(bas);
		bas = gecici;
	}

}


void sondanSil(){

	gecici = bas;
	if(gecici->gosterici!=NULL){
		
		while(gecici->gosterici->gosterici != NULL){
			gecici = gecici->gosterici;
		}
		free(gecici->gosterici);
		gecici->gosterici =NULL;
	
	}
	else{
		bastanSil();
	}
}

void araSil(int a){
	gecici = bas;
	while(gecici->gosterici->veri != a){
		gecici = gecici->gosterici;
		
	}
	struct dugum * gecici2 = (struct dugum*)malloc(sizeof(struct dugum));
	gecici2->veri = gecici->gosterici->veri;
	gecici2->gosterici = gecici->gosterici->gosterici;
	gecici->gosterici = gecici2->gosterici;
	free(gecici2);
	
}



void print(){
	
	gecici = bas;
	
	if(bas == NULL){
		printf("Your struct is empty.");
	}
	else{
		while(gecici->gosterici != NULL){
			printf("%d - ",gecici->veri );
			gecici= gecici->gosterici;
		}
		printf("%d - ",gecici->veri );
	}
	
	
	
}






int main(){
	
	
	
	
	basaEkle(01);
	sonaEkle(11);
	sonaEkle(22);
	sonaEkle(44);
	arayaEkle(44,33);
	sonaEkle(55);
	sonaEkle(66);
	bastanSil();
	sondanSil();
	araSil(22);
	
	
	
	print();
	
	
	
	
	
	
	return 1;
}
