-- 코드를 작성해주세요
-- ECOLI_DATA 실험실에서 배양한 대장균들의 정보
-- 최초의 대장균 개체의 PARENT_ID는 NULL

SELECT
ID as ID,
-- RANK() over (ORDER by SIZE_OF_COLONY DESC),
CASE WHEN RANK() over (ORDER by SIZE_OF_COLONY DESC)<=(SELECT count(*) from ECOLI_DATA)/4 then 'CRITICAL'
WHEN RANK() over (ORDER by SIZE_OF_COLONY DESC)<=(SELECT count(*) from ECOLI_DATA)/4*2 then 'HIGH'
WHEN RANK() over (ORDER by SIZE_OF_COLONY DESC)<=(SELECT count(*) from ECOLI_DATA)/4*3 then 'MEDIUM'
ELSE 'LOW'
END AS COLONY_NAME
FROM ECOLI_DATA
ORDER BY ID