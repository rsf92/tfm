#include "../include/struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define AUTONOMIES 19
#define PROVINCES 52
#define MUNICIPALITIES 10000

int add_autonomy(char * autonomy_name, autonomy *array);

void print_autonomies(autonomy * array);

int add_province(char * province_name, province *array);

void print_provinces(province * array);

int add_aut_province(int prov, int aut, aut_prov *array);

void print_aut_provinces(aut_prov * array);

int add_municipality(char *muni, municipality *array);

void print_municipalities(municipality * array);

int add_prov_mun(int prov, int mun, prov_mun *array);

void print_prov_mun(prov_mun * array);

void clean_string(char * str);

int main(int argc, char ** argv){

	FILE * f;
	char line[1000];
	autonomy aut[AUTONOMIES]={0,""};
	province prov[PROVINCES]={0,""};
	municipality munic[MUNICIPALITIES]={0,""};	
	aut_prov aut_provs[PROVINCES]={0,0};
	prov_mun prov_mun[MUNICIPALITIES] ={0,0};

	char autonomy_name[SIZE];
	char province_name[SIZE];
	char municipality_name[SIZE];
	int i, num, aut_id, prov_id, muni_id;
	char * p=province_name;
	if (argc <= 2){
		printf("Error! No argument used: \n");
		printf("Use mode is: ./exe file");
		return -1;
	}
	num = atoi(argv[1]);
	
	for(i =0; i< num; i++){
		f = fopen(argv[2+i], "r");
		fgets (line, 1000, f);
		while (fgets (line, 1000, f)){	
			
			strcpy(autonomy_name,strtok(line,","));	
			clean_string(autonomy_name);
			aut_id=add_autonomy(autonomy_name, aut);
			strtok(NULL, ",");
			strcpy(province_name, strtok(NULL, ","));
			clean_string(province_name);
			prov_id = add_province(province_name, prov);
			strcpy(province_name, "");
			add_aut_province(prov_id , aut_id, aut_provs);
			strtok(NULL, ",");
			strcpy(municipality_name, strtok(NULL, ","));
			clean_string(municipality_name);
			muni_id=add_municipality(municipality_name, munic);
			add_prov_mun(prov_id , muni_id, prov_mun);
		}
	}
	print_autonomies(aut);
	print_provinces(prov);
	print_aut_provinces(aut_provs);
	print_municipalities(munic);
	print_prov_mun(prov_mun);
	return 0;
}


int add_autonomy(char * autonomy_name, autonomy *array){
	int i;
	if(autonomy_name == NULL || array == NULL){
		return -1;	
	}

	for(i=0; i<AUTONOMIES; i++){
		if(strcmp(autonomy_name, array[i].autonomy) == 0)
			return array[i].id;
		else if (array[i].id == 0){
			array[i].id = i+1;
			strcpy(array[i].autonomy, autonomy_name);
			return i+1;
		}

	}
	return 0;
}

int add_province(char * province_name, province *array){
	int i;
	if(province_name == NULL || array == NULL){
		return -1;	
	}
	province_name[0] = toupper(province_name[0]);
	for(i=0; i<PROVINCES; i++){
		
		if(strcmp(province_name, array[i].province) == 0)
			return array[i].id;
		else if (array[i].id == 0){
			array[i].id = i+1;
			strcpy(array[i].province, province_name);
			return i+1;
		}

	}
	
	return 0;
}

int add_aut_province(int prov, int aut, aut_prov *array){
	int i;
	if( array == NULL){
		return -1;	
	}

	for(i=0; i<PROVINCES; i++){
		
		if(array[i].id_aut == aut && array[i].id_prov == prov)
			break;
		else if (array[i].id_aut == 0 && array[i].id_prov == 0){
			array[i].id_aut = aut;
			array[i].id_prov = prov;
			break;
		}

	}
	return 0;	
}

int add_municipality(char *muni, municipality *array){
	int i;
	if( array == NULL){
		return -1;	
	}

	for(i=0; i<MUNICIPALITIES; i++){
		
		if(strcmp(muni, array[i].municipality) == 0)
			return array[i].id;
		else if (array[i].id == 0){
			array[i].id = i+1;
			strcpy(array[i].municipality, muni);
			return i+1;
		}

	}
	return 0;	
}


int add_prov_mun(int prov, int mun, prov_mun *array){

	int i;
	if( array == NULL){
		return -1;	
	}

	for(i=0; i<MUNICIPALITIES; i++){
		
		if(array[i].id_mun == mun && array[i].id_prov == prov)
			break;
		else if (array[i].id_mun == 0 && array[i].id_prov == 0){
			//printf("Province %d %d\n", mun ,prov);
			array[i].id_mun = mun;
			array[i].id_prov = prov;			
			break;
		}

	}
	return 0;

}

void print_prov_mun(prov_mun * array){
	int i;

	if(array == NULL)
		return;

	for(i=0; i<MUNICIPALITIES && array[i].id_mun != 0 && array[i].id_prov != 0; i++){
		printf("insert into province_municipality values (%d, %d);\n", array[i].id_mun, array[i].id_prov);
	}

}

void print_municipalities(municipality * array){
	int i;

	if(array == NULL)
		return;

	for(i=0; i<MUNICIPALITIES && array[i].id != 0; i++){
		printf("insert into municipality values (%d, \'%s\');\n", array[i].id, array[i].municipality);
	}

}

void print_aut_provinces(aut_prov * array){
	int i;

	if(array == NULL)
		return;

	for(i=0; i<PROVINCES; i++){
		printf("insert into autonomy_province values (%d, %d);\n", array[i].id_aut, array[i].id_prov);
	}
}

void print_autonomies(autonomy * array){
	
	int i;

	if(array == NULL)
		return;

	for(i=0; i<AUTONOMIES; i++){
		printf("insert into autonomy values (%d, \'%s\');\n", array[i].id, array[i].autonomy);
	}

}

void print_provinces(province * array){
	
	int i;

	if(array == NULL)
		return;

	for(i=0; i<PROVINCES; i++){
		printf("insert into province values (%d, \'%s\');\n", array[i].id, array[i].province);
	}

}

void clean_string(char * str){
	
	int i;

	if(str == NULL)
		return;
	for(int i =0; str[i] != '\0';i++)
		if(str[i]== ' ' && (str[i+1] == ' ' ||str[i+1] == '\0'))
			str[i]='\0';

}
