#ifndef STRUCT_H_
#define STRUCT_H_

#define SIZE 70

typedef struct t_province{
 	int id;
	char province[SIZE];
}province;

typedef struct t_autonomy{
	int id;
	char autonomy[SIZE];
}autonomy;


typedef struct t_aut_prov{
	int id_aut;
	int id_prov;

}aut_prov;


typedef struct t_census{
	int prov_id;
	int year;
	int census;
}census;

typedef struct t_party{

	int id;
	char name[SIZE];
	int economics;
	int civil;
	int authority;
	
}party;

typedef struct t_elect_result{
 int party_id;
 int year;
 int prov_id;
 int votes;
}elect_result;
#endif
