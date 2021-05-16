drop table classes;
rem *************************************
rem Creating table :Classes
rem *************************************
create table classes
(
	class varchar2(20) constraint class_pr primary key,
	type varchar2(2) constraint type_check check(type in ('bb','bc')),
	country varchar2(20),
	num_gun number(2),
	bore number(2),
	displacement number(6)
);

rem *************************************
rem 1. Add first two tuples from the above sample data. List the columns explicitly in the INSERT 
rem clause. (No ordering of columns)
rem *************************************

Insert into classes(class,type,country,num_gun,bore,displacement) values
('Bismark','bb','Germany',8,14,32000);

Insert into classes(class,type,country,num_gun,bore,displacement) values
('Lowa','bb','USA',9,16,46000);


rem *************************************
rem 2. Populate the relation with the remaining set of tuples. This time, do not list the columns in 
rem the INSERT clause.
rem *************************************

Insert into classes values('Kongo','bc','Japan',8,15,42000);
Insert into classes values('North Carolina','bb','USA',9,16,37000);
Insert into classes values('Revenge','bb','Gt.Britain',8,15,29000);
Insert into classes values('Renown','bc','Gt.Britain',6,15,32000);


rem *************************************
rem 3. Display the populated relation
rem *************************************

select * from classes;


rem *************************************
rem 4. Mark an intermediate point here in this transaction.

rem *************************************

savepoint s1;

rem *************************************
rem 5. Change the displacement of Bismark to 34000.
rem *************************************

update classes
set displacement = 34000
where class = 'Bismark';

rem *************************************
rem 6. For the battleships having at least 9 number of guns or the ships with at least 15 inch bore, 
rem increase the displacement by 10%. Verify your changes to the table.

update classes
set displacement=(displacement+(displacement*0.1))
where num_gun > 8 or bore > 14;

rem *************************************
rem 7. Delete Kongo class of ship from Classes table.

rem *************************************

delete from classes
where class='Kongo';


rem *************************************
rem 8. Display your changes to the table.
rem *************************************

select * from classes;

rem *************************************
rem 9. Discard the recent updates to the relation without discarding the earlier INSERT operation(s).
rem *************************************

rollback to s1;
select * from classes;

rem *************************************
rem 10. Commit the changes.
rem *************************************
commit;



