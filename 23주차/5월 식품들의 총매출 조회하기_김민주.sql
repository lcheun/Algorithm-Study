select p.product_id, product_name, sum(amount)*price as total_sales
from food_product p inner join food_order o
on p.product_id = o.product_id
where date_format(produce_date, "%Y-%m") = '2022-05'
group by p.product_id
order by total_sales desc, product_id;
