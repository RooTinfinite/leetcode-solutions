<h2><a href="https://leetcode.com/problems/minimum-unlocked-indices-to-sort-nums">Minimum Unlocked Indices to Sort Nums</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an array <code>nums</code> consisting of integers between 1 and 3, and a <strong>binary</strong> array <code>locked</code> of the same size.</p>

<p>We consider <code>nums</code> <strong>sortable</strong> if it can be sorted using adjacent swaps, where a swap between two indices <code>i</code> and <code>i + 1</code> is allowed if <code>nums[i] - nums[i + 1] == 1</code> and <code>locked[i] == 0</code>.</p>

<p>In one operation, you can unlock any index <code>i</code> by setting <code>locked[i]</code> to 0.</p>

<p>Return the <strong>minimum</strong> number of operations needed to make <code>nums</code> <strong>sortable</strong>. If it is not possible to make <code>nums</code> sortable, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,2,3,2], locked = [1,0,1,1,0,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>We can sort <code>nums</code> using the following swaps:</p>

<ul>
	<li>swap indices 1 with 2</li>
	<li>swap indices 4 with 5</li>
</ul>

<p>So, there is no need to unlock any index.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,1,3,2,2], locked = [1,0,1,1,0,1,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>If we unlock indices 2 and 5, we can sort <code>nums</code> using the following swaps:</p>

<ul>
	<li>swap indices 1 with 2</li>
	<li>swap indices 2 with 3</li>
	<li>swap indices 4 with 5</li>
	<li>swap indices 5 with 6</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,2,3,2,1], locked = [0,0,0,0,0,0,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p>Even if all indices are unlocked, it can be shown that <code>nums</code> is not sortable.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 3</code></li>
	<li><code>locked.length == nums.length</code></li>
	<li><code>0 &lt;= locked[i] &lt;= 1</code></li>
</ul>
