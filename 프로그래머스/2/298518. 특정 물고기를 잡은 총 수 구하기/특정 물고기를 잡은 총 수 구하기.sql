-- 코드를 작성해주세요
Select SUM(F.cnt) as FISH_COUNT
FROM(Select COUNT(*) as cnt
        From FISH_INFO fi
        INNER JOIN FISH_NAME_INFO fni
        ON fi.fish_type = fni.fish_type
        WHERE fni.fish_name in('BASS', 'SNAPPER')
        GROUP BY fi.fish_type) as F