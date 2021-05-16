REM @Z:\a2\retrieve



REM 11. Display firsy name, job id and salary of all the employees.
select first_name,job_id,salary 
from employees;

REM 12. Display the id, name(first & last), salary and annual salary of all the employees. Sort the
REM     employees by first name. Label the columns as shown below:
REM     (EMPLOYEE_ID, FULL NAME, MONTHLY SAL, ANNUAL SALARY)

select employee_id,concat(first_name,last_name) as "FULL NAME",salary as "MONTHLY SALARY",salary*12 as "ANNUAL SALARY" 
from employees
order by first_name;

REM 13.List the different jobs in which the employees are working for.

select distinct job_id as "JOBS" 
from employees;

REM 14. Display the id, first name, job id, salary and commission of employees who are earning commissions.
select employee_id,first_name,job_id,salary,commission_pct 
from employees
where commission_pct is NOT NULL;


REM 15. Display the details (id, first name, job id, salary and dept id) of employees who are MANAGERS.
select employee_id,first_name,job_id,salary,department_id 
from employees
where job_id like '%MGR' or job_id like '%MAN';

REM 16. Display the details of employees other than sales representatives (id, first name, hire date,job id, salary and dept id)
REM	who are hired after ‘01May1999’ or whose salary is at least 10000.
select employee_id,first_name,hire_date,job_id,salary,department_id 
from employees
where job_id != 'SA_REP' and (salary > 10000 or hire_date > '01-may-1999')
order by first_name;

REM 17.Display the employee details (first name, salary, hire date and dept id) whose salary falls in
REM    the range of 5000 to 15000 and his/her name begins with any of characters (A,J,K,S). Sort
REM    the output by first name.

select first_name,salary,hire_date,department_id 
from employees
where (salary > 5000 and salary < 15000) and substr(first_name,1,1) in ('A','J','K','S')
order by first_name;


REM 18.Display the experience of employees in no. of years and months who were hired after 1998.Label the columns as: (EMPLOYEE_ID, FIRST_NAME, HIRE_DATE, EXPYRS,EXPMONTHS)
       select employee_id,first_name,floor(months_between(sysdate,hire_date)/12) as EXPYRS,floor(mod(months_between(sysdate,hire_date),12)) as EXPMONTHS
       from employees
	where extract(year from hire_date) > 1998;

REM 19. Display the total number of departments.
	select count(distinct department_id) as total_departments
	from employees;
	


REM 20. Show the number of employees hired by yearwise.Sort the result by yearwise.
	select extract(year from hire_date) as year,count(*) no_of_emp
	from employees
	group by extract(year from hire_date)
	order by extract(year from hire_date);

REM 21.Display the minimum, maximum and average salary, number of employees for each
REM    department. Exclude the employee(s) who are not in any department. Include the
REM    department(s) with at least 2 employees and the average salary is more than 10000. Sort the
REM    result by minimum salary in descending order.
       select department_id,min(salary) as min_salary,max(salary) as max_salary,avg(salary) as avg_salary,count(*) as total
	from employees
	where department_id is not null
	group by department_id
	having count(*)>=2 and avg(salary) >10000
	order by min(salary) desc; 
