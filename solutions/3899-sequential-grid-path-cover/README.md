<h2><a href="https://leetcode.com/problems/sequential-grid-path-cover">Sequential Grid Path Cover</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a 2D array <code>grid</code> of size <code>m x n</code>, and an integer <code>k</code>. There are <code>k</code> cells in <code>grid</code> containing the values from 1 to <code>k</code> <strong>exactly once</strong>, and the rest of the cells have a value 0.</p>

<p>You can start at any cell, and move from a cell to its neighbors (up, down, left, or right). You must find a path in <code>grid</code> which:</p>

<ul>
	<li>Visits each cell in <code>grid</code> <strong>exactly once</strong>.</li>
	<li>Visits the cells with values from 1 to <code>k</code> <strong>in order</strong>.</li>
</ul>

<p>Return a 2D array <code>result</code> of size <code>(m * n) x 2</code>, where <code>result[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents the <code>i<sup>th</sup></code> cell visited in the path. If there are multiple such paths, you may return <strong>any</strong> one.</p>

<p>If no such path exists, return an <strong>empty</strong> array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[0,0,0],[0,1,2]], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[[0,0],[1,0],[1,1],[1,2],[0,2],[0,1]]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2025/05/16/ezgifcom-animated-gif-maker1.gif" style="width: 200px; height: 160px;" /></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">grid = [[1,0,4],[3,0,2]], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no possible path that satisfies the conditions.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m == grid.length &lt;= 5</code></li>
	<li><code>1 &lt;= n == grid[i].length &lt;= 5</code></li>
	<li><code>1 &lt;= k &lt;= m * n</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= k</code></li>
	<li><code>grid</code> contains all integers between 1 and <code>k</code> <strong>exactly</strong> once.</li>
</ul>
