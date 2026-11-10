<h2><a href="https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-iii">Find All Numbers Disappeared in an Array III</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>nums</code> and two integers <code>lower</code> and <code>upper</code>.</p>

<p>An integer is <strong>missing</strong> if it lies in the inclusive range <code>[lower, upper]</code> and does not appear in <code>nums</code>.</p>

<p>Return a 2D integer array representing all missing integers grouped into <strong>contiguous ranges</strong>. Represent each range as <code>[start, end]</code>, including both endpoints, and return the ranges in increasing order of <code>start</code>.</p>

<p>Consecutive missing integers must belong to the same range. If there are no missing integers, return an empty array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,9,7], lower = 1, upper = 12</span></p>

<p><strong>Output:</strong> <span class="example-io">[[1,2],[4,6],[8,8],[10,12]]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The missing integers are <code>[1, 2, 4, 5, 6, 8, 10, 11, 12]</code>.</li>
	<li>Grouping the missing integers into the minimum number of contiguous ranges, we get <code>[1, 2]</code>, <code>[4, 6]</code>, <code>[8, 8]</code>, and <code>[10, 12]</code>.</li>
	<li>Therefore, the answer is <code>[[1, 2], [4, 6], [8, 8], [10, 12]]</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1000000000], lower = 5, upper = 1000000000</span></p>

<p><strong>Output:</strong> <span class="example-io">[[5,999999999]]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The value 1 lies outside <code>[lower, upper]</code>, so it does not cover any integer in the range.</li>
	<li>The only integer of the range that appears in <code>nums</code> is 1000000000.</li>
	<li>Every integer from 5 to 999999999 is missing, and they are consecutive, so they form the single range <code>[5, 999999999]</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,3,5], lower = 2, upper = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Both 2 and 3 appear in <code>nums</code>, so there are no missing integers.</li>
	<li>Therefore, the answer is <code>[]</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= lower &lt;= upper &lt;= 10<sup>9</sup></code></li>
</ul>
