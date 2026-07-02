<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-all-grid-elements-equal">Minimum Operations to Make All Grid Elements Equal</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given a 2D integer array <code>grid</code> of size <code>m &times; n</code>, and an integer <code>k</code>.</p>

<p>In one operation, you can:</p>

<ul>
	<li>Select any <code>k x k</code> <strong>submatrix</strong> of <code>grid</code>, and</li>
	<li>Increment <strong>all elements</strong> inside that <strong>submatrix</strong> by 1.</li>
</ul>

<p>Return the <strong>minimum</strong> number of operations required to make all elements in the grid <strong>equal</strong>. If it is not possible, return -1.</p>
A submatrix <code>(x1, y1, x2, y2)</code> is a matrix that forms by choosing all cells <code>matrix[x][y]</code> where <code>x1 &lt;= x &lt;= x2</code> and <code>y1 &lt;= y &lt;= y2</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[3,3,5],[3,3,5]], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p data-end="266" data-start="150">Choose the left <code>2 x 2</code> submatrix (covering the first two columns) and apply the operation twice.</p>

<ul>
	<li>After 1 operation: <code>[[4, 4, 5], [4, 4, 5]]</code></li>
	<li>After 2 operations: <code>[[5, 5, 5], [5, 5, 5]]</code></li>
</ul>

<p>All elements become equal to 5. Thus, the minimum number of operations is 2.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,2],[2,3]], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>Since <code>k = 1</code>, each operation increments a single cell <code>grid[i][j]</code> by 1. To make all elements equal, the final value must be 3.</p>

<ul>
	<li>Increase <code>grid[0][0] = 1</code> to 3, requiring 2 operations.</li>
	<li>Increase <code>grid[0][1] = 2</code> to 3, requiring 1 operation.</li>
	<li>Increase <code>grid[1][0] = 2</code> to 3, requiring 1 operation.</li>
</ul>

<p>Thus, the minimum number of operations is <code>2 + 1 + 1 + 0 = 4</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m == grid.length &lt;= 1000</code></li>
	<li><code>1 &lt;= n == grid[i].length &lt;= 1000</code></li>
	<li><code>-10<sup>5</sup> &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(m, n)</code></li>
</ul>
