<h2><a href="https://leetcode.com/problems/maximum-subarray-sum-of-fixed-length-after-at-most-k-swaps">Maximum Subarray Sum of Fixed Length After at Most K Swaps</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>nums</code> and two integers <code>length</code> and <code>k</code>.</p>

<p>You may perform <strong>at most</strong> <code>k</code> swap operations on <code>nums</code>.</p>

<p>In one swap operation, you may choose two <strong>distinct</strong> indices <code>i</code> and <code>j</code> and swap <code>nums[i]</code> and <code>nums[j]</code>.</p>

<p>Return the <strong>maximum possible sum</strong> of a <span data-keyword="subarray-nonempty">subarray</span> of length <strong>exactly</strong> <code>length</code> after performing the swaps.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,-1,0,2], length = 2, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Swap the elements at indices 1 and 3, resulting in <code>[1, 2, 0, -1]</code>.</li>
	<li>The subarray <code>[1, 2]</code> has length 2 and sum 3.</li>
	<li>No subarray of length 2 can have a larger sum, since 1 and 2 are the two largest elements.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,3,2,4], length = 3, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">11</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Swap the elements at indices 2 and 3, resulting in <code>[4, 3, 4, 2]</code>.</li>
	<li>The subarray <code>[4, 3, 4]</code> has length 3 and sum 11.</li>
	<li>This is the sum of the three largest elements, so no larger answer is possible. Only one swap is needed.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [-1,-2], length = 2, k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">-3</span></p>

<p><strong>Explanation:</strong></p>

<p>No swaps are allowed. The only subarray of length 2 is <code>[-1, -2]</code>, whose sum is -3.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= length &lt;= nums.length</code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
</ul>
