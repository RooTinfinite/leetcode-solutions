<h2><a href="https://leetcode.com/problems/maximum-distinct-path-sum-in-a-binary-tree">Maximum Distinct Path Sum in a Binary Tree</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given the <code>root</code> of a <strong>binary tree</strong>, where each node contains an integer value.</p>

<p>A <strong>valid path</strong> in the tree is a sequence of <strong>connected</strong> nodes such that:</p>

<ul>
	<li>The path can start and end at <strong>any node</strong> in the tree.</li>
	<li>The path does <strong>not</strong> need to pass through the root.</li>
	<li>All node values along the path are <strong>distinct</strong>.</li>
</ul>

<p>Return an integer denoting the <strong>maximum</strong> possible sum of node values among all valid paths.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><img src="https://assets.leetcode.com/uploads/2026/01/28/screenshot-2026-01-29-at-12940am.png" style="width: 200px; height: 175px;" /></p>

<p><strong>Input:</strong> <span class="example-io">root = [2,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The path <code>2 &rarr; 2</code> is invalid because the value 2 is not distinct.</li>
	<li>The maximum-sum valid path is <code>2 &rarr; 1</code>, with a sum = <code>2 + 1 = 3</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><img src="https://assets.leetcode.com/uploads/2026/01/28/screenshot-2026-01-29-at-15149am.png" style="width: 200px; height: 204px;" /></p>

<p><strong>Input:</strong> <span class="example-io">root = [1,-2,5,null,null,3,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">9</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The path <code>3 &rarr; 5 &rarr; 5</code> is invalid due to duplicate value 5.</li>
	<li>The maximum-sum valid path is <code>1 &rarr; 5 &rarr; 3</code>, with a sum = <code>1 + 5 + 3 = 9</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/01/28/screenshot-2026-01-29-at-15555am.png" style="width: 180px; height: 217px;" />​​​​​​​</p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [4,6,6,null,null,null,9]</span></p>

<p><strong>Output:</strong> <span class="example-io">19</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The path <code>6 &rarr; 4 &rarr; 6 &rarr; 9</code> is invalid because the value 6 appears more than once.</li>
	<li>The maximum-sum valid path is <code>4 &rarr; 6 &rarr; 9</code>, with a sum = <code>4 + 6 + 9 = 19</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000​​​​​​​</code></li>
</ul>
