set echo on;
set linesize 150;
drop table employee_payroll;

create table Emp_Payroll
(
	eid varchar2(4) constraint emp_pk primary key,
	ename varchar2(10),
	dob date,
	sex varchar2(7),
	designation varchar2(30),
	basic number(10,2),
	da number(10,2),
	hra number(10,2),
	pf number(10,2),
	mc number(10,2),
	gross number(10,2),
	tot_deduc number(10,2),
	net_pay number(10,2)
);

create or replace procedure net_pay(E_id Emp_Payroll.eid%type,E_basic Emp_Payroll.basic%type)
is
begin
update Emp_Payroll
set da = 0.6*E_basic,hra = 0.11*E_basic,pf=0.04*E_basic,mc=0.03*E_basic,gross=E_basic+hra+da,
tot_deduc =pf+mc,net_pay=gross-total_deduc
where eid = E_eid;
end;
/