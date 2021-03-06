﻿drop table if exists electoral_result;
drop table if exists census;
drop table if exists party;
drop table if exists autonomy_province;
drop table if exists autonomy;
drop table if exists province;

create table if not exists autonomy(
id serial primary key,
name text
);

create table if not exists province(
id serial primary key,
name text
);


create table if not exists autonomy_province(
autonomy int references autonomy(id),
province int references province(id),
primary key(autonomy, province)
);



create table if not exists census(
  prov_id int references province(id),
  year int,
  census int,
  primary key (prov_id, year)
);

create table if not exists party(
id serial primary key,
name text,
economics int,
civil int,
authority int
);

create table if not exists electoral_result(
party int references party(id),
year int,
prov int references province(id),
votes int,
primary key (party,year,prov)
);

create table if not exists election(
year int primary key,
unemp real,
pib real
);
