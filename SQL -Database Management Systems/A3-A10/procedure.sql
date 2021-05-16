rem Assignment 6
rem regno:185001161
rem Name: Sreedhar V

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

set serveroutput on;
rem 1. Write a stored function to display the total number of pizza's ordered by the given order number.

create or replace function total_pizzas(order_num varchar2)
return int
is
total int;
begin
	select sum(qty) into total
	from order_list 
	where order_no = order_num;
	return total;
end;
/
declare
	order_input varchar2(5);
	total number(2);
begin
	order_input:='&order_input';
	select total_pizzas(order_input) into total 
	from orders where order_no=order_input;
	dbms_output.put_line('Total :'||total);
end;
/

rem 2. Write a PL/SQL block to calculate the total amount, discount and billable amount
rem(Amount to be paid) as given below:
rem For total amount > 2000 and total amount < 5000: Discount=5%
rem For total amount > 5000 and total amount < 10000: Discount=10%
rem For total amount > 10000: Discount=20%
rem Calculate the billable amount (after the discount) and update the same in orders table.
rem Bill Amount = Total - Discount.

alter table orders add tot_amount number(10,4);

alter table orders add discount_amt number(10,4);

alter table orders add bill_amount number(10,4);

select * from orders;
create or replace procedure update_orders is
	cursor c1 is select o.order_no,ol.qty,(ol.qty)*(pi.unit_price) as price
	from customer c,pizza pi,orders o,order_list ol
	where (c.cust_id = o.cust_id) and (pi.pizza_id = ol.pizza_id) and (o.order_no = ol.order_no);
	bill_amt number(10,4);
	discount number(10,4);
	total_amt number(10,4);
	cursor c2 is select order_no from orders;
begin
	for cur1 in c2 loop
		total_amt:=0;
		bill_amt:=0;
		discount:=0;
		for cur2 in c1 loop
			if(cur2.order_no = cur1.order_no and cur2.qty is not null) then
				total_amt := total_amt + cur2.price;
			end if;
		end loop;
		if (total_amt <= 2000) then
			discount:=0;
		elsif(total_amt >2000 and total_amt <=5000) then
			discount:=(0.05*total_amt);
		elsif(total_amt >5000 and total_amt <=10000) then
			discount:=(0.01*total_amt);
		else 
			discount:=(0.20*total_amt);
		end if;
		bill_amt:=total_amt-discount;
		update orders 
		set tot_amount=total_amt,bill_amount=bill_amt,discount_amt=discount
		where cur1.order_no=order_no;
	end loop;
end;
/

execute update_orders;

select * from orders;


Rem 3.For the given order number, write a PL/SQL block to print the order
declare
	  cursor c1 is select c.cust_name, o.order_date, c.phone, o.order_no, o.tot_amount, p.unit_price,
          o.discount_amt, o.bill_amount, p.pizza_type, ord.qty, ((ord.qty )* (p.unit_price)) as price
          from customer c, pizza p, orders o, order_list ord
          where (c.cust_id=o.cust_id) and (p.pizza_id=ord.pizza_id) and (o.order_no=ord.order_no);
          ordernum orders.order_no%type;
          bill_amt number(7);
          discount number(7);
          tot number(5);
          i number(1);
          tot_qty number(2);
          disc_percent number (2);
  begin
      ordernum:='&ordernum';
      select order_no into ordernum from orders where order_no = ordernum;
      i:=1;
      tot_qty:=total_pizzas(ordernum);
      for cur in c1 loop
          if(cur.order_no=ordernum) then
              dbms_output.put_line('**********************************************************');
              dbms_output.put_line('Order Number:'||cur.order_no||'                  Customer Name:'||cur.cust_name);
              dbms_output.put_line('Order Date:'||cur.order_date||'                Phone:'||cur.phone);
              dbms_output.put_line('**********************************************************');
              exit;
          end if;
      end loop;
      dbms_output.put_line('SNo     Pizza_type         Qty     Price     Amount');
      for cur in c1 loop
          if(cur.order_no=ordernum) then
              dbms_output.put_line(i||'.'||'      '||cur.pizza_type||'      		'||cur.qty||'      '||cur.unit_price||'       '||cur.price);

              i:=i+1;
          end if;
      end loop;
      update_orders();
      select tot_amount, discount_amt, bill_amount into tot, discount, bill_amt from orders where ordernum = order_no;
      disc_percent:=(discount/tot)*100;
      dbms_output.put_line('----------------------------------------------------------');
      dbms_output.put_line('Total=                      '||tot_qty||'               '||tot);
      dbms_output.put_line('----------------------------------------------------------');
      dbms_output.put_line('Total Amount        :'||'Rs.'||tot);
      dbms_output.put_line('Discount ('||disc_percent||'%)       :'||'Rs. '||discount);
      dbms_output.put_line('----------------------------------------------------------');
      dbms_output.put_line('Amount to be paid   :'||'Rs.'||bill_amt);
      dbms_output.put_line('----------------------------------------------------------');
      dbms_output.put_line('Great Offers! Discount upto 25% on DIWALI Festival Day...');
      dbms_output.put_line('**********************************************************');
      exception when no_data_found then dbms_output.put_line('Invalid Order number.');
   end;
  /