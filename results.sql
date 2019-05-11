/*select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1977 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1979 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1982 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1986 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1989 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1993 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 1996 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 2000 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 2004 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 2008 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 2011 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 2015 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
select province.name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes from party, electoral_result, province where prov = province.id and party.id = electoral_result.party and electoral_result.year = 2016 and votes > 0 group by (party.name, party.civil, party.economics, party.authority, province.name) order by province.name, votes desc limit 5;
update party set economics=2, civil=2, authority=2 where name = 'CDS';
update party set economics=3, civil=3, authority=2 where name = 'PP';
update party set economics=2, civil=1, authority=1 where name like 'PSOE%';
update party set economics=1, civil=1, authority=2 where name like 'IU%';
update party set economics=3, civil=2, authority=2 where name = 'CIU';
update party set economics=3, civil=2, authority=2 where name = 'EAJ-PNV';
update party set economics=1, civil=1, authority=1 where name = 'PSP-US';
update party set economics=1, civil=1, authority=1 where name = 'PCE';
update party set economics=3, civil=3, authority=3 where name = 'AP';
update party set economics=2, civil=2, authority=2 where name = 'UCD';
update party set economics=3, civil=2, authority=2 where name = 'CD';
update party set economics=3, civil=2, authority=2 where name like 'AP-PDP%';
update party set economics=2, civil=1, authority=2 where name = 'ERC';
update party set economics=3, civil=2, authority=2 where name = 'CiU';
update party set economics=2, civil=2, authority=2 where name = 'UPyD';
update party set economics=3, civil=3, authority=2 where name = 'P.P.';
update party set economics=1, civil=1, authority=2 where name = 'I.U.';
update party set economics=2, civil=1, authority=1 where name like 'P.S.O.E.';
update party set economics=1, civil=1, authority=2 where name like 'PODEMOS%';
update party set economics=3, civil=2, authority=2 where name like 'Cs';
update party set economics=1, civil=1, authority=2 where name like 'ECP';
update party set economics=1, civil=1, authority=2 where name like 'EN COMU';
update party set economics=3, civil=2, authority=2 where name = 'PNV';
update party set economics=2, civil=1, authority=1 where name like 'PSA-PA%';
update party set economics=1, civil=1, authority=2 where name like 'EE';
update party set economics=1, civil=1, authority=2 where name like 'HB';
update party set economics=1, civil=1, authority=2 where name like 'EH Bildu';
update party set economics=3, civil=2, authority=2 where name = 'PDPC';
update party set economics=2, civil=2, authority=2 where name = 'PAR';
update party set economics=1, civil=1, authority=3 where name = 'C-UPC';
update party set economics=2, civil=3, authority=3 where name = 'AIC';
update party set economics=2, civil=2, authority=2 where name = 'CG';
update party set economics=2, civil=1, authority=2 where name = 'CC';
update party set economics=2, civil=1, authority=2 where name = 'EA';
update party set economics=3, civil=2, authority=2 where name = 'CDC';
update party set economics=2, civil=2, authority=2 where name = 'ERC-CATSI';
update party set economics=2, civil=2, authority=2 where name = 'P.R.C.';
update party set economics=1, civil=2, authority=2 where name = 'BNG';
update party set economics=1, civil=2, authority=2 where name = 'B.N.G.';
update party set economics=1, civil=1, authority=2 where name like 'AMAIUR';
update party set economics=2, civil=1, authority=2 where name = 'CC-NC-PNC';
update party set economics=2, civil=2, authority=2 where name = 'ESQUERRA';
update party set economics=3, civil=3, authority=2 where name = 'UPN';
update party set economics=3, civil=2, authority=2 where name = 'DL';
update party set economics=3, civil=3, authority=2 where name = 'FAC';
update party set economics=1, civil=1, authority=3 where name = 'CUP';
update party set economics=2, civil=3, authority=2 where name = 'CAIC';
update party set economics=1, civil=1, authority=3 where name = 'FL';
update party set economics=3, civil=3, authority=3 where name = 'GIL';
update party set economics=2, civil=1, authority=2 where name = 'PA';
update party set economics=1, civil=1, authority=2 where name = 'CHA';
update party set economics=2, civil=1, authority=2 where name = 'CC-PNC';
update party set economics=2, civil=1, authority=2 where name = 'NC-CCN';
update party set economics=2, civil=2, authority=2 where name = 'UC';
update party set economics=3, civil=2, authority=2 where name = 'UV';*/
select province_year.year, province_year.name, election_result.name, civil, economics, authority, votes
	from (select year, id, name
		from electoral_result, province where prov= province.id 
		group by year, id order by year, id) as province_year LEFT JOIN LATERAL 
			(select year, province.name as province_name ,party.name, party.civil, party.economics, party.authority,  sum(votes) as votes 
				from party, electoral_result, province where prov = province_year.id and party.id = electoral_result.party and votes > 0  and year = province_year.year
				group by (party.name, party.civil, party.economics, party.authority, province.name, year) order by year,province.name, votes desc limit 4) as election_result  ON true where civil=0

