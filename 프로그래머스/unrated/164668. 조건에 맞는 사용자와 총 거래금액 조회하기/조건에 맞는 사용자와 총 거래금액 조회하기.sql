-- 코드를 입력하세요



SELECT u.USER_ID as USER_ID, u.NICKNAME as NICKNAME, b.PRICE as TOTAL_SALES
FROM USED_GOODS_USER as u
JOIN (SELECT WRITER_ID, SUM(PRICE) as price FROM USED_GOODS_BOARD
    where STATUS="DONE"
    GROUP BY WRITER_ID) as b
ON u.USER_ID=b.WRITER_ID
where b.PRICE>=700000
ORDER BY b.PRICE