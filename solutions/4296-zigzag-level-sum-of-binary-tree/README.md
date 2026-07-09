<h2><a href="https://leetcode.com/problems/zigzag-level-sum-of-binary-tree">Zigzag Level Sum of Binary Tree</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given the <code>root</code> of a <strong>binary tree</strong>.</p>

<p>Traverse the tree level by level using a zigzag pattern:</p>

<ul>
	<li>At <strong>odd</strong>-numbered levels (1-indexed), traverse nodes from <strong>left to right</strong>.</li>
	<li>At <strong>even</strong>-numbered levels, traverse nodes from <strong>right to left</strong>.</li>
</ul>

<p>While traversing a level in the specified direction, process nodes in order and <strong>stop</strong> immediately before the first node that violates the condition:</p>

<ul>
	<li>At <strong>odd</strong> levels: the node does not have a <strong>left</strong> child.</li>
	<li>At <strong>even</strong> levels: the node does not have a <strong>right</strong> child.</li>
</ul>

<p>Only the nodes processed before this stopping condition contribute to the level sum.</p>

<p>Return an integer array <code>ans</code> where <code>ans[i]</code> is the <strong>sum</strong> of the node values that are processed at level <code>i + 1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [5,2,8,1,null,9,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">[5,8,0]</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/04/12/screenshot-2026-04-13-at-22054am.png" style="height: 240px; width: 300px;" />​​​​​​​</p>

<ul>
	<li>At level 1, nodes are processed left to right. Node 5 is included, thus <code>ans[0] = 5</code>.</li>
	<li>At level 2, nodes are processed right to left. Node 8 is included, but node 2 lacks a right child, so processing stops, thus <code>ans[1] = 8</code>.</li>
	<li>At level 3, nodes are processed left to right. The first node 1 lacks a left child, so no nodes are included, and <code>ans[2] = 0</code>.</li>
	<li>Thus, <code>ans = [5, 8, 0]</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,4,5,null,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,5,0]</span></p>

<p><strong>Explanation:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/04/12/screenshot-2026-04-13-at-22232am.png" style="height: 254px; width: 300px;" /></p>

<ul>
	<li>At level 1, nodes are processed left to right. Node 1 is included, thus <code>ans[0] = 1</code>.</li>
	<li>At level 2, nodes are processed right to left. Nodes 3 and 2 are included since both have right children, thus <code>ans[1] = 3 + 2 = 5</code>.</li>
	<li>At level 3, nodes are processed left to right. The first node 4 lacks a left child, so no nodes are included, and <code>ans[2] = 0</code>.</li>
	<li>Thus, <code>ans = [1, 5, 0]</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>
