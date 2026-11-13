<h2><a href="https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-iii">Find the Maximum Length of Valid Subsequence III</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>nums</code> and a <strong>positive</strong> integer <code>k</code>.</p>

<p>A <strong><span data-keyword="subsequence-array">subsequence</span></strong> of <code>nums</code> is <strong>valid</strong> if the sum of every pair of adjacent elements in the subsequence is divisible by <code>k</code>.</p>

<p>A subsequence of length 1 is always valid.</p>

<p>Return the length of the <strong>longest valid subsequence</strong> of <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,5], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Pick the subsequence <code>[1, 2, 4, 5]</code>.</li>
	<li>The adjacent sums are <code>1 + 2 = 3</code>, <code>2 + 4 = 6</code>, and <code>4 + 5 = 9</code>, all divisible by 3.</li>
	<li>No valid subsequence longer than 4 exists.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,10,15], k = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Pick the whole array <code>[5, 10, 15]</code>.</li>
	<li>The adjacent sums are <code>5 + 10 = 15</code> and <code>10 + 15 = 25</code>, both divisible by 5.</li>
	<li>Every element is a multiple of 5, so any two elements can be adjacent in a valid subsequence, and the answer is 3.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,3,5,7,9], k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Pick the whole array <code>[1, 3, 5, 7, 9]</code>.</li>
	<li>The adjacent sums are <code>1 + 3 = 4</code>, <code>3 + 5 = 8</code>, <code>5 + 7 = 12</code>, and <code>7 + 9 = 16</code>, all divisible by 4.</li>
	<li>The remainders alternate between 1 and 3, which add to 4, so the answer is 5.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>
