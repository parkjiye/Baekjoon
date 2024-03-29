-- 코드를 입력하세요

SELECT a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, SUM(s.SALES*b.PRICE) as TOTAL_SALES
FROM BOOK b
INNER JOIN BOOK_SALES s
ON b.BOOK_ID = s.BOOK_ID
INNER JOIN AUTHOR a
ON b.AUTHOR_ID = a.AUTHOR_ID
WHERE YEAR(s.SALES_DATE)=2022 and MONTH(s.SALES_DATE)=1
GROUP BY b.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY
ORDER BY a.AUTHOR_ID, b.CATEGORY desc;

# SELECT *, SUM(SALES), SUM(s.SALES)*b.price
# FROM BOOK_SALES s, BOOK b
# WHERE s.BOOK_ID = b.BOOK_ID
# AND YEAR(s.SALES_DATE)=2022 and MONTH(s.SALES_DATE)=1
# GROUP BY s.BOOK_ID