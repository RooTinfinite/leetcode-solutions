<h2><a href="https://leetcode.com/problems/minimum-index-sum-of-common-elements">Minimum Index Sum of Common Elements</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given two integer arrays <code>nums1</code> and <code>nums2</code> of equal length <code>n</code>.</p>

<p>We define a pair of indices <code>(i, j)</code> as a <strong>good pair</strong> if <code>nums1[i] == nums2[j]</code>.</p>

<p>Return the <strong>minimum index sum</strong> <code>i + j</code> among all possible good pairs. If no such pairs exist, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [3,2,1], nums2 = [1,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Common elements between <code>nums1</code> and <code>nums2</code> are 1 and 3.</li>
	<li>For 3, <code>[i, j] = [0, 1]</code>, giving an index sum of <code>i + j = 1</code>.</li>
	<li>For 1, <code>[i, j] = [2, 0]</code>, giving an index sum of <code>i + j = 2</code>.</li>
	<li>The minimum index sum is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [5,1,2], nums2 = [2,1,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Common elements between <code>nums1</code> and <code>nums2</code> are 1 and 2.</li>
	<li>For 1, <code>[i, j] = [1, 1]</code>, giving an index sum of <code>i + j = 2</code>.</li>
	<li>For 2, <code>[i, j] = [2, 0]</code>, giving an index sum of <code>i + j = 2</code>.</li>
	<li>The minimum index sum is 2.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [6,4], nums2 = [7,8]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Since no common elements between <code>nums1</code> and <code>nums2</code>, the output is -1.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length == nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums1[i], nums2[i] &lt;= 10<sup>5</sup></code></li>
</ul>
