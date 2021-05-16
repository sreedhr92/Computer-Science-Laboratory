rem @Z:\a4\air_cre
rem @Z:\a4\air_pop
rem @Z:\a4\views

@F:\air_cre.sql
@F:\air_pop.sql

set echo on;
set linesize 150;

rem dropping views

drop view schedule_15;
drop view airtype;
drop view losangeles_route;
drop view losangeles_flight;
rem ***************************Views*******************


rem 1. Create a view Schedule_15 that display the flight number, route, airport(origin, destination) 
rem departure (date, time), arrival (date, time) of a flight on 15 apr 2005. Label the view 
rem column as flight, route, from_airport, to_airport, ddate, dtime, adate, atime respectively.


rem creating the view schedule_15.......

create view schedule_15(flight,route,from_airport,to_airport,ddate,dtime,adate,atime)
as 
select 
	f.flightNo,r.routeId,r.orig_airport,r.dest_airport,
	fl.departs,fl.dtime,fl.arrives,fl.atime 
from 
	routes r,flights f,fl_schedule fl where f.rid = r.routeId 
	and f.flightNo = fl.flno and fl.departs = '15-apr-2005';

select * from schedule_15;

savepoint s1;


rem checking each attribute whether it is updatable or not

select table_name,column_name,updatable,insertable,deletable
from user_updatable_columns
where table_name='SCHEDULE_15';


rem ****  updating dtime

update schedule_15 set dtime=1111 where flight='SQ-11';

rem changes in view

select * from schedule_15 where flight='SQ-11';

rem changes in base table

select flno,dtime from fl_schedule where flno='SQ-11';

rem **** updating ddate

update schedule_15 set ddate ='16-APR-05' where flight='SQ-11';
rem changes in view

select * from schedule_15 where flight='SQ-11';

rem changes in base table

select departs,flno from fl_schedule where flno='SQ-11';


rem ***** updating atime

update schedule_15 set atime=2342 where flight='BA-178';

rem changes in view 

select * from schedule_15 where flight='BA-178';

rem changes in base table

select atime,flno from fl_schedule where flno='BA-178';


rem ***** updating adate

update schedule_15 set adate='16-APR-05' where flight='JJ-2482';


rem changes in view 

select * from schedule_15 where flight='JJ-2482';

rem changes in base table

select arrives,flno from fl_schedule where flno='JJ-2482';

rem checking each attribute whether it is deletable or not


delete from schedule_15 where flight='RP-5018';

rem changes in view table

select * from schedule_15 where flight='RP-5018';

rem changes in base table

select * from fl_schedule where flno = 'RP-5018';
select * from flights where flightNo = 'RP-5018';
select * from routes where routeId= 'MC201';


rem inserting...
insert into schedule_15 values('HA-1','LH106','Los Angeles','Honolulu','15-apr-05','1230','16-apr-05','2055');

rollback to s1;

rem 2. Define a view Airtype that display the number of aircrafts for each of its type. Label the 
rem    column as craft_type, total.

rem creating view airtype

create view airtype(craft_type,total)
as
select a.type,count(a.type) from aircraft a group by a.type;

select * from airtype;


select table_name,column_name,updatable,insertable,deletable
from user_updatable_columns
where table_name='AIRTYPE';

savepoint s2;

rem 3.Create a view Losangeles_Route that contains Los Angeles in the route. Ensure that the view 
rem always contain/allows only information about the Los Angeles route.


rem creating view losangeles_route

create view losangeles_route
as
select * from routes
where orig_airport = 'Los Angeles' or dest_airport  = 'Los Angeles';

select * from losangeles_route;

savepoint s3;


select table_name,column_name,updatable,insertable,deletable
from user_updatable_columns
where table_name='LOSANGELES_ROUTE';

rem ************* update*************
rem **** updating routeid

rem update losangeles_route set routeid='AA-999' where routeid='LB103';

rem ********updating ORIG_AIRPORT 

update losangeles_route set ORIG_AIRPORT='New Delhi' where routeid='LC101';

rem changes in view

select * from losangeles_route where routeid='LC101';

rem changes in base table

select routeid,orig_airport from routes where routeid='LC101';

rem ************updating DEST_AIRPORT

update losangeles_route set DEST_AIRPORT='New Delhi' where routeid='CL150';

rem changes in view

select * from losangeles_route where routeid='CL150';

rem changes in base table

select routeid,dest_airport from routes where routeid='CL150';

rem ************updating distance

update losangeles_route set distance=5000 where routeid='LS104';

rem changes in view

select * from losangeles_route where routeid='LS104';

rem changes in base table

select distance,routeid from routes where routeid='LS104';

rem ****************delete*************

delete from losangeles_route where routeid='LS104';

rem changes in view

select * from losangeles_route where routeid='LS104';

rem changes in base table

select * from routes where routeid='LS104';


rem ***************insert**********
insert into losangeles_route values('AA-99','New Delhi','Los Angeles',3002);

rem changes in view

select * from losangeles_route;

rollback to s3;

rem 4.Create a view named Losangeles_Flight on Schedule_15 (as defined in 1) that display flight, 
rem departure (date, time), arrival (date, time) of flight(s) from Los Angeles.

create view losangeles_flight
as
select flight,ddate,dtime,adate,atime from schedule_15
where from_airport = 'Los Angeles';

select * from losangeles_flight;

savepoint s4;
select table_name,column_name,updatable,insertable,deletable
from user_updatable_columns
where table_name='LOSANGELES_FLIGHT';

rem ************* update*************

rem ****  updating dtime

update losangeles_flight set dtime=1111 where flight='HA-1';

rem changes in view

select * from losangeles_flight where flight='HA-1';

rem changes in table

select flno,dtime from fl_schedule where flno='HA-1';


rem ****  updating atime

update losangeles_flight set atime=1111 where flight='HA-1';

rem changes in view

select * from losangeles_flight where flight='HA-1';

rem changes in table

select flno,atime from fl_schedule where flno='HA-1';

rem **** updating ddate

update schedule_15 set ddate ='16-APR-05' where flight='HA-1';
rem changes in view

select * from schedule_15 where flight='HA-1';

rem changes in base table

select flno,departs from fl_schedule where flno='HA-1';

rem **** updating adate

update schedule_15 set adate ='17-APR-05' where flight='JJ-2482';
rem changes in view

select * from schedule_15 where flight='JJ-2482';

rem changes in base table

select flno,arrives from fl_schedule where flno='JJ-2482';


rem ****************delete*************

delete from losangeles_flight where flight='JJ-2482';

rem changes in view

select * from losangeles_flight where flight='JJ-2482';

rem changes in base table;

select * from fl_schedule where flno='JJ-2482';

select * from routes where routeid='LW100';

select * from flights where flightno='JJ-2482';

rem *************insert*********

rem insert into losangeles_flight values(
rollback to s4;


