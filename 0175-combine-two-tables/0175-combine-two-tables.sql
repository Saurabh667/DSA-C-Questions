# Write your MySQL query statement below
select p.firstname,p.lastname,a.city,a.state FROM Person p LEFT JOIN Address a on P.personId=a.personId;