<h2><a href="https://leetcode.com/problems/create-grid-with-exactly-k-paths-ii">Create Grid With Exactly K Paths II</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given an integer <code>k</code>.</p>

<p>Construct <strong>any</strong> grid consisting only of the characters <code>&#39;.&#39;</code> and <code>&#39;#&#39;</code>, where:</p>

<ul>
	<li><code>&#39;.&#39;</code> represents a free cell.</li>
	<li><code>&#39;#&#39;</code> represents an obstacle cell.</li>
</ul>

<p>The grid must contain <strong>at most</strong> 25 rows and <strong>at most</strong> 25 columns.</p>

<p>A <strong>valid path</strong> is a sequence of free cells that:</p>

<ul>
	<li>Starts at the top-left cell <code>(0, 0)</code>.</li>
	<li>Ends at the bottom-right cell <code>(m - 1, n - 1)</code>, where <code>m</code> and <code>n</code> are the dimensions of your constructed grid.</li>
	<li>Moves only:
	<ul>
		<li>Right, from <code>(i, j)</code> to <code>(i, j + 1)</code>, or</li>
		<li>Down, from <code>(i, j)</code> to <code>(i + 1, j)</code>.</li>
	</ul>
	</li>
</ul>

<p>Return any grid such that there are <strong>exactly <code>k</code> valid paths</strong> from the top-left cell to the bottom-right cell. If no such grid exists, return an empty array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[&quot;..#&quot;,&quot;#..&quot;,&quot;#..&quot;]</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/05/31/screenshot-2026-05-31-at-82224pm.png" style="width: 200px; height: 135px;" /></p>

<p>The grid contains exactly 2 valid paths from <code>(0, 0)</code> to <code>(2, 2)</code>:</p>

<ul>
	<li><code>(0, 0) &rarr; (0, 1) &rarr; (1, 1) &rarr; (1, 2) &rarr; (2, 2)</code></li>
	<li><code>(0, 0) &rarr; (0, 1) &rarr; (1, 1) &rarr; (2, 1) &rarr; (2, 2)</code></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">[&quot;...&quot;,&quot;#..&quot;,&quot;#..&quot;]</span></p>

<p><strong>Explanation:</strong></p>

<p><strong>​​​​​​​</strong><img src="https://assets.leetcode.com/uploads/2026/05/31/screenshot-2026-05-31-at-82251pm.png" style="width: 200px; height: 128px;" /></p>

<p>The grid contains exactly 3 valid paths from <code>(0, 0)</code> to <code>(2, 2)</code>:</p>

<ul>
	<li><code>(0, 0) &rarr; (0, 1) &rarr; (0, 2) &rarr; (1, 2) &rarr; (2, 2)</code></li>
	<li><code>(0, 0) &rarr; (0, 1) &rarr; (1, 1) &rarr; (1, 2) &rarr; (2, 2)</code></li>
	<li><code>(0, 0) &rarr; (0, 1) &rarr; (1, 1) &rarr; (2, 1) &rarr; (2, 2)</code></li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong>​​​​​​​</p>

<ul>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
</ul>
