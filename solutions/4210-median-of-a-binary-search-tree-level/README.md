<h2><a href="https://leetcode.com/problems/median-of-a-binary-search-tree-level">Median of a Binary Search Tree Level</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given the <code>root</code> of a <strong>Binary Search Tree (BST)</strong> and an integer <code>level</code>.</p>

<p>The root node is at level 0. Each level represents the distance from the root.</p>

<p>Return the <strong>median value</strong> of all node values present at the given <code>level</code>. If the level does not exist or contains no nodes, return -1.</p>

<p>The <strong>median</strong> is defined as the middle element after sorting the values at that level in <strong>non-decreasing</strong> order. If the number of values at that level is even, return the <strong>upper</strong> median (the larger of the two middle elements after sorting).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/01/27/screenshot-2026-01-27-at-20801pm.png" style="width: 180px; height: 182px;" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [4,null,5,null,7], level = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<p>The nodes at <code>level = 2</code> are <code>[7]</code>. The median value is 7.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/01/27/screenshot-2026-01-27-at-20926pm.png" style="width: 200px; height: 169px;" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [6,3,8], level = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">8</span></p>

<p><strong>Explanation:</strong></p>

<p>The nodes at <code>level = 1</code> are <code>[3, 8]</code>. There are two possible median values, so the larger one 8 is the answer.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<p><strong class="example">​​​​​​​​​​​​​​</strong><img src="https://assets.leetcode.com/uploads/2026/01/27/screenshot-2026-01-27-at-21001pm.png" style="width: 150px; height: 193px;" /></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [2,1], level = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no node present at <code>level = 2</code>​​​​​​​, so the answer is -1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 2 * 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= level &lt;= 2 * 10<sup>​​​​​​​5</sup></code></li>
</ul>
