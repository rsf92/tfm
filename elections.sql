drop table if exists autonomy;
drop table if exists province;
drop table if exists municipality;
drop table if exists autonomy_province;
drop table if exists province_municipality;
create table if not exists autonomy(
id serial primary key,
name text
);

create table if not exists province(
id serial primary key,
name text
);

create table if not exists municipality(
id serial primary key,
name text
);

create table if not exists autonomy_province(
autonomy int references autonomy(id),
province int references province(id),
primary key(autonomy, province)
);

create table if not exists province_municipality(
municipality int references municipality(id),
province int references province(id),
primary key(municipality, province)
);

create table if not exists census(
 town_id int references municipality(id),
  year int,
  census int,
  primary key (town_id, year)
);

create table if not exists party(
id serial primary key,
name text,
economics int,
civil int,
power int
);

create table if not exists electoral_result(
party int references party(id),
year int,
town int references municipality(id),
votes int,
primary key (party,year,town)
);