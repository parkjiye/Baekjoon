-- 코드를 작성해주세요
select COUNT(*) as FISH_COUNT, MONTH(TIME) as MONTH from FISH_INFO
group by Month(TIME)
Order by MONTH