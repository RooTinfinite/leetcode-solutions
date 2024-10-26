<h2><a href="https://leetcode.com/problems/recyclable-and-low-fat-products">Recyclable and Low Fat Products</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Table: <code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| low_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
product_id is the primary key (column with unique values) for this table.
low_fats is an ENUM (category) of type (&#39;Y&#39;, &#39;N&#39;) where &#39;Y&#39; means this product is low fat and &#39;N&#39; means it is not.
recyclable is an ENUM (category) of types (&#39;Y&#39;, &#39;N&#39;) where &#39;Y&#39; means this product is recyclable and &#39;N&#39; means it is not.</pre>

<p>&nbsp;</p>

<p>Write a solution to find the ids of products that are both low fat and recyclable.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Products table:
+-------------+----------+------------+
| product_id  | low_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
<strong>Output:</strong> 
+-------------+
| product_id  |
+-------------+
| 1           |
| 3           |
+-------------+
<strong>Explanation:</strong> Only products 1 and 3 are both low fat and recyclable.
</pre>


```mysql [MySQL]
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'
;
```
```mssql [MS SQL Server]
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'
;
```
```oraclesql [Oracle]
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'
;
```
```postgresql [PostgreSQL]
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'
;
```
```pythondata [Pandas]
import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    return products.loc[(products.low_fats=='Y') & (products.recyclable=='Y')][['product_id']]
```
No differences between SQL systems in this solution.


# Order of Execution 

**FROM** Products > **WHERE** low_fats = 'Y' AND recyclable = 'Y' > **SELECT** product_id

![image.png](https://assets.leetcode.com/users/images/8e79f743-e4a2-446a-811c-f4941d9a0d63_1727286203.1927686.png)*(Image from kdnuggets Josep Ferrer)*

# EXPLAINED
- **SELECT product_id:**
This command tells the database to retrieve the product_id column. The SELECT statement is used to specify which columns you want to fetch from the database.
- **FROM Products:**
This specifies the table from which to retrieve the data. In this case, the table is named Products. The FROM clause indicates the source table for the data.
- **WHERE low_fats = ‘Y’ AND recyclable = ‘Y’:**
The WHERE clause is used to filter records based on specified conditions. Here, it filters the rows to include only those where the low_fats column has a value of 'Y' (indicating the product is low in fats) and the recyclable column also has a value of 'Y' (indicating the product is recyclable).
The AND operator ensures that both conditions must be true for a row to be included in the result set.

![image.png](https://assets.leetcode.com/users/images/cdbcac52-b5c7-45e2-823e-87b59d33a741_1727295353.7574322.png)



