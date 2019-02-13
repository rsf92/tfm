#include "../include/struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define AUTONOMIES 19
#define PROVINCES 52
#define MUNICIPALITIES 10000
#define PARTIES 300

int add_autonomy(char * autonomy_name, autonomy *array);

void print_autonomies(autonomy * array);

int add_province(char * province_name, province *array);

void print_provinces(province * array);

int add_aut_province(int prov, int aut, aut_prov *array);

void print_aut_provinces(aut_prov * array);

int add_municipality(char *muni, municipality *array);

int add_census(int mun_id, int year, int cen, census *array);

int insert_parties(char * line, party * parties);

void print_parties(party * array);

void print_census(census * array);

void print_municipalities(municipality * array);

int add_prov_mun(int prov, int mun, prov_mun *array);

void print_prov_mun(prov_mun * array);

void clean_string(char * str);

int main(int argc, char ** argv){

	FILE * f;
	char line[1000], lineyear[1000];
	autonomy aut[AUTONOMIES]={0,""};
	province prov[PROVINCES]={0,""};
	municipality munic[MUNICIPALITIES]={0,""};	
	aut_prov aut_provs[PROVINCES]={0,0};
	prov_mun prov_mun[MUNICIPALITIES] ={0,0};
	census	 cen[MUNICIPALITIES]={0,0,0};
	party parties[PARTIES]= {0,"",0,0,0};
	party year_parties[PARTIES];
	char autonomy_name[SIZE];
	char province_name[SIZE];
	char municipality_name[SIZE];
	char year_str[SIZE];
	int i,j, num, aut_id, prov_id, muni_id, year, parties_year;
	char * p=province_name;
	if (argc <= 2){
		printf("Error! No argument used: \n");
		printf("Use mode is: ./exe file");
		return -1;
	}
	num = atoi(argv[1]);
	
	for(i =0; i< num; i++){
		f = fopen(argv[2+i], "r");
		strcpy(year_str,strstr(argv[2+i],"_")+1);
		year_str[4]='\0';
		year=atoi(year_str);
		for(j=0; j< PARTIES;j++){
			year_parties[j].id= 0;
		}
		fgets (line, 1000, f);
		strcpy(lineyear, line);
		parties_year=insert_parties(lineyear, year_parties);
		insert_parties(line, parties);
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
			strtok(NULL, ",");strtok(NULL, ",");
			add_census(muni_id, year, atoi(strtok(NULL, ",")), cen);
			strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");
			for(j=0; j<parties_year; j++){
					
			}

		}
	}
	print_autonomies(aut);
	print_provinces(prov);
	print_aut_provinces(aut_provs);
	print_municipalities(munic);
	print_prov_mun(prov_mun);
	print_census(cen);
	print_parties(parties);
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
			
			array[i].id_mun = mun;
			array[i].id_prov = prov;			
			break;
		}

	}
	return 0;

}

int add_census(int mun_id, int year, int cen, census *array){

	int i;
	if( array == NULL){
		return -1;	
	}

	for(i=0; i<MUNICIPALITIES; i++){
		
		if(array[i].mun_id == mun_id && array[i].year == year)
			break;
		else if (array[i].mun_id== 0 && array[i].year == 0){
			array[i].mun_id = mun_id;
			array[i].year = year;
			array[i].census = cen;			
			break;
		}

	}
	return 0;

}


int insert_parties(char * line, party * parties){

	int i;
	char name[SIZE];
	char line_copy[1000];
	char *p=line;
	strcpy(line_copy,line);
	strtok(line_copy, ",");
	strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");
	strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	p=strstr(p, ",")+1;
	while( (p=strstr(p, ","))!= NULL){
		p++;
		strcpy(name, strtok(NULL, ","));	
		for(i=0; i<PARTIES; i++){
			
			if(!strcmp(parties[i].name,name))
				break;
			else if (parties[i].id== 0){
				parties[i].id = i+1;
				strcpy(parties[i].name,name);			
				break;
			}

		}
	}

	strcpy(name, strtok(NULL, ",\n"));	
	for(i=0; i<PARTIES; i++){
		if(!strcmp(parties[i].name,name))
			break;
		else if (parties[i].id== 0){
			parties[i].id = i+1;
			strcpy(parties[i].name,name);			
			break;
		}

	}
	return i;
}

void print_parties(party * array){
	int i;

	if(array == NULL)
		return;

	for(i=0; i<PARTIES && array[i].id != 0; i++){
		printf("insert into party values (%d, %s,%d,%d, %d);\n", array[i].id, array[i].name, array[i].economics,array[i].civil, array[i].authority);
	}
}

void print_census(census * array){

	int i;

	if(array == NULL)
		return;

	for(i=0; i<MUNICIPALITIES && array[i].mun_id != 0 && array[i].year != 0; i++){
		printf("insert into census values (%d, %d, %d);\n", array[i].mun_id, array[i].year, array[i].census);
	}
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
