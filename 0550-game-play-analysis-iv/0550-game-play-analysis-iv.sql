# Write your MySQL query statement below
with first_login_info as(
    select player_id,min(event_date) as first_login from Activity group by player_id
),
player_info as(
    select a1.player_id,a1.first_login,a2.event_date from first_login_info as a1 join Activity as a2 on a1.player_id=a2.player_id and datediff(a2.event_date,a1.first_login)=1
)

select round(count(distinct a2.player_id)/count(distinct a1.player_id),2) as fraction from Activity as a1 left join player_info as a2 on a1.player_id=a2.player_id

