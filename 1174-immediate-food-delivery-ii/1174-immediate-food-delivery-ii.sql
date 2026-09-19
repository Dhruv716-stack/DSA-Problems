WITH cust_first_order AS (
    SELECT customer_id, MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
),
complete_first_order AS (
    SELECT d.*
    FROM cust_first_order t1
    JOIN Delivery d
    ON t1.customer_id = d.customer_id
    AND t1.first_order = d.order_date
)

SELECT ROUND(
    SUM(IF(order_date = customer_pref_delivery_date, 1, 0))
    / COUNT(*) * 100,
    2
) AS immediate_percentage
FROM complete_first_order;