set echo on;
set linesize 150;

rem dropping the tables...
drop table order_list;
drop table orders;
drop table pizza;
drop table customer;

rem creating the table

create table customer
(
	cust_id varchar2(10) constraint cust_pr primary key,
	cust_name varchar2(20),
	address varchar2(40),
	phone number(10)
);

create table pizza
(
	pizza_id varchar2(10) constraint pizza_pr primary key,
	pizza_type varchar2(20),
	unit_price number(10)
);

create table orders
(
	order_no varchar2(10) constraint order_pr primary key,
	cust_id varchar2(10) constraint cust_fk references customer(cust_id),
	order_date date,
	delv_date date
);

create table order_list
(
	order_no varchar2(10) constraint order_fk references orders(order_no),
	pizza_id varchar2(10) constraint pizza_fk references pizza(pizza_id),
	qty number(10),
	constraint order_list_pk primary key(order_no,pizza_id)
);
rem populating table;
@F:\pizza_db.sql

rem 1.Check whether the given pizza type is available. If not display appropriate message.

