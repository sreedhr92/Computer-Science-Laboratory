set echo on;
set linesize 150;
set serveroutput on;

@F:\air_cre.sql
@F:\air_pop.sql

rem 1. The date of arrival should be always later than or on the same date of departure.

create or replace trigger check_date 
before insert or update on fl_schedule
for each row
when (new.arrives < new.departs or old.arrives < new.departs or new.arrives < old.departs)
begin
	raise_application_error(-20132,'Error: The date of arrival should be always later than or on the same date of departure');
end check_date;
/

savepoint s1;
rem Inserting values to check the triggers works or not.

rem Invalid values

INSERT INTO fl_schedule values('AF-23','22-apr-05',1245,'21-apr-05',1850,450.25);

UPDATE fl_schedule set arrives = '17-apr-05' where flno ='WS-5060';

rem Valid values

rem for insertion
select * from fl_schedule where flno='AF-23';

INSERT INTO fl_schedule values('AF-23','22-apr-05',1245,'23-apr-05',1850,450.25);

select * from fl_schedule where flno='AF-23';

rem for updation
select * from fl_schedule where flno='WS-5060' and price =227.6;

UPDATE fl_schedule set arrives = '21-apr-05' where flno ='WS-5060' and price =227.6;

select * from fl_schedule where flno='WS-5060' and price =227.6;

rollback to s1;

rem 2.Flight number CX-7520 is scheduled only on Tuesday,Friday and Sunday

create or replace trigger check_CX750_day
before insert or update on fl_schedule
for each row
when (new.flno ='CX-7520')
declare 
	day1 integer;
begin
	day1:=to_char(:new.departs,'d');
	if (day1 not in (2,5,7)) then
		raise_application_error(-20133,'Error :The Flight number CX-7520 is scheduled only on Tuesday,Friday and Sunday');
	end if;
end check_CX750_day;
/
savepoint s2;
rem Inserting invalid values to check the triggers works or not.

INSERT INTO fl_schedule values('CX-7520','24-apr-05',1245,'25-apr-05',1850,540.23);

UPDATE fl_schedule set departs ='20-apr-05' where flno ='CX-7520' and arrives ='22-apr-05';

rem Inserting valid values

rem for insertion

select * from fl_schedule where flno='CX-7520';

INSERT INTO fl_schedule values('CX-7520','25-apr-05',1245,'27-apr-05',1850,540.23);

select * from fl_schedule where flno='CX-7520';

rem for updation 

select * from fl_schedule where flno ='CX-7520' and arrives ='22-apr-05';

UPDATE fl_schedule set departs ='21-apr-05' where flno ='CX-7520' and arrives ='22-apr-05';

select * from fl_schedule where flno ='CX-7520' and arrives ='22-apr-05';

rollback to s2;
rem 3.	An aircraft is assigned to a flight only if its cruising range is more than the distance of the flights' route.

create or replace trigger check_range_flight
before insert or update on flights
for each row
declare
	range number(6);
	dist number(6);
begin
	select cruisingrange into range from aircraft a where a.aid =:new.aid;
	select distance into dist from routes r where r.routeID =:new.rid;
	if(range < dist) then
		raise_application_error(-20122,'Error :An aircraft is assigned to a flight only if its cruising range is more than the distance of the flights route');
	end if;
end check_range_flight;
/
savepoint s3;
rem Invalid Inserting values to check the triggers works or not.

INSERT INTO flights values ('AK-47','NYP401',7);

update flights set aid=7 where rID='LW100';

rem Valid inserting values

rem for insertion

select * from flights where flightNo='AK-47';

INSERT INTO flights values ('AK-47','LD102',3);

select * from flights where flightNo='AK-47';


rollback to s3;
