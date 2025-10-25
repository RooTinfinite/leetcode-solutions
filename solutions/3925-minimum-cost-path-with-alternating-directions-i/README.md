<h2><a href="https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-i">Minimum Cost Path with Alternating Directions I</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given two integers <code>m</code> and <code>n</code> representing the number of rows and columns of a grid, respectively.</p>

<p>The cost to enter cell <code>(i, j)</code> is defined as <code>(i + 1) * (j + 1)</code>.</p>

<p>The path will always begin by entering cell <code>(0, 0)</code> on move 1 and paying the entrance cost.</p>

<p>At each step, you move to an <strong>adjacent</strong> cell, following an alternating pattern:</p>

<ul>
	<li>On <strong>odd-numbered</strong> moves, you must move either <strong>right</strong> or <strong>down</strong>.</li>
	<li>On <strong>even-numbered</strong> moves, you must move either<strong> left</strong> or <strong>up</strong>.</li>
</ul>

<p>Return the <strong>minimum</strong> total cost required to reach <code>(m - 1, n - 1)</code>. If it is impossible, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 1, n = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>You start at cell <code>(0, 0)</code>.</li>
	<li>The cost to enter <code>(0, 0)</code> is <code>(0 + 1) * (0 + 1) = 1</code>.</li>
	<li>Since you&#39;re at the destination, the total cost is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">m = 2, n = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>You start at cell <code>(0, 0)</code> with cost <code>(0 + 1) * (0 + 1) = 1</code>.</li>
	<li>Move 1 (odd): You can move down to <code>(1, 0)</code> with cost <code>(1 + 1) * (0 + 1) = 2</code>.</li>
	<li>Thus, the total cost is <code>1 + 2 = 3</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>6</sup></code></li>
</ul>
