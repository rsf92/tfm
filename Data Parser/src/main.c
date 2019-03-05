#include "../include/struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define AUTONOMIES 19
#define PROVINCES 52
#define MUNICIPALITIES 1//5000
#define CENSUS	100000
#define PARTIES 700

int add_autonomy(char * autonomy_name, autonomy *array);

void print_autonomies(autonomy * array);

int add_province(char * province_name, province *array);

void print_provinces(province * array);

int add_aut_province(int prov, int aut, aut_prov *array);

void print_aut_provinces(aut_prov * array);

int add_census(int prov_id, int year, int cen, census *array);

int insert_parties(char * line, party * parties);

int insert_elect_result(int votes,int mun_id, int year, int party_id, elect_result * results);

void print_results(elect_result ** results, int years);

void print_parties(party * array);

void print_census(census * array);

void clean_string(char * str);

int main(int argc, char ** argv){

	FILE * f;
	char line[1000], lineyear[1000];
	autonomy aut[AUTONOMIES]={0,""};
	province prov[PROVINCES]={0,""};
	aut_prov aut_provs[PROVINCES]={0,0};
	census	 cen[CENSUS]={0,0,0};
	party parties[PARTIES]= {0,"",0,0,0};
	party year_parties[PARTIES];
	elect_result **election;	
	char autonomy_name[SIZE];
	char province_name[SIZE];
	char municipality_name[SIZE];
	char year_str[SIZE];
	char votes[SIZE];
	int id;
	
	int i,j, num, aut_id, prov_id, year, parties_year, vote_res;
	char * p=province_name;
	if (argc <= 2){
		printf("Error! No argument used: \n");
		printf("Use mode is: ./exe file");
		return -1;
	}
	num = atoi(argv[1]);
	
	election = (elect_result **)calloc(num, sizeof(elect_result *));
	if(election == NULL)
		return -1;

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
		election[i]=(elect_result *)calloc(PARTIES*MUNICIPALITIES, sizeof(elect_result));
		if(election[i] == NULL){
			free(election);
			return -1;		
		}
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
			strtok(NULL, ",");strtok(NULL, ",");
			break;
			strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");
			add_census(prov_id, year, atoi(strtok(NULL, ",")), cen);
			strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");strtok(NULL, ",");
			for(j=0; j<parties_year; j++){
				strcpy(votes, strtok(NULL, ","));
				clean_string(votes);
				vote_res=atoi(votes);
				insert_elect_result(vote_res,prov_id, year,year_parties[j].id , election[i]);							
			}

		}
	}
	print_autonomies(aut);
	print_provinces(prov);
	print_aut_provinces(aut_provs);
	/*print_municipalities(munic);
	print_prov_mun(prov_mun);
	print_census(cen);
	print_parties(parties);
	print_results(election, num);*/
	return 0;
}


int add_autonomy(char * autonomy_name, autonomy *array){
	int i;
	if(autonomy_name == NULL || array == NULL){
		return -1;	
	}

	for(i=0; i<AUTONOMIES; i++){
		if(strcmp(autonomy_name,array[i].autonomy) == 0)
			return array[i].id;
		else if (array[i].id == 0){
			array[i].id = i+1;
			strcpy(array[i].autonomy, autonomy_name);
			return i+1;
		}

	}
	printf("Not enough autonomies %s\n", autonomy_name);
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
	printf("Not enough provinces");
	return 0;
}

int add_aut_province(int prov, int aut, aut_prov *array){
	int i;
	if( array == NULL){
		return -1;	
	}

	for(i=0; i<PROVINCES; i++){
		
		if(array[i].id_aut == aut && array[i].id_prov == prov)
			return i;
		else if (array[i].id_aut == 0 && array[i].id_prov == 0){
			array[i].id_aut = aut;
			array[i].id_prov = prov;
			return i;
		}

	}
	printf("Not enough provinces-autonomies");
	return 0;	
}

int add_census(int prov_id, int year, int cen, census *array){

	int i;
	if( array == NULL){
		return -1;	
	}

	for(i=0; i<CENSUS; i++){
		
		if(array[i].prov_id == prov_id && array[i].year == year){
			array[i].census +=cen;
			return i;
		}else if (array[i].prov_id== 0 && array[i].year == 0){
			array[i].prov_id = prov_id;
			array[i].year = year;
			array[i].census = cen;			
			return i;
		}

	}
	printf("Not enough census\n");
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

int insert_elect_result(int votes,int prov_id, int year, int party_id, elect_result * results){

	int i;
	if( results == NULL){
		return -1;	
	}

	for(i=0; i<(PARTIES*MUNICIPALITIES); i++){
		
		if(results[i].prov_id == prov_id && results[i].party_id == party_id){
			results[i].votes+=votes;
			return i;
		}else if (results[i].prov_id== 0 && results[i].party_id == 0){
			results[i].prov_id = prov_id;
			results[i].year = year;
			results[i].party_id = party_id;
			results[i].votes=votes;			
			return i;
		}

	}
	printf("Not enough results\n");
	return 0;

}

void print_results(elect_result ** results, int years){
	int i,j;

	if(results == NULL)
		return;
	for(j=0; j<years;j++)
		for(i=0; i<PARTIES*MUNICIPALITIES && results[j][i].party_id != 0; i++){
			printf("insert into electoral_result values (%d,%d,%d,%d);\n", results[j][i].party_id, results[j][i].year, results[j][i].prov_id,results[j][i].votes);
		}
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

	for(i=0; i<CENSUS && array[i].prov_id != 0 && array[i].year != 0; i++){
		printf("insert into census values (%d, %d, %d);\n", array[i].prov_id, array[i].year, array[i].census);
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
		if((str[i]== ' ' && (str[i+1] == ' ' ||str[i+1] == '\0')) || str[i]== '\t')
			str[i]='\0';
		else
		  str[i] = tolower(str[i]);	
}
