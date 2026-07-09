<h2><a href="https://leetcode.com/problems/count-smaller-elements-with-opposite-parity">Count Smaller Elements With Opposite Parity</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>nums</code> of length <code>n</code>.</p>

<p>The <strong>score</strong> of an index <code>i</code> is defined as the number of indices <code>j</code> such that:</p>

<ul>
	<li><code>i &lt; j &lt; n</code></li>
	<li><code>nums[j] &lt; nums[i]</code></li>
	<li><code>nums[i]</code> and <code>nums[j]</code> have different parity (one is even and the other is odd).</li>
</ul>

<p>Return an integer array <code>answer</code> of length <code>n</code>, where <code>answer[i]</code> is the score of index <code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,2,4,1,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,1,2,0,0]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For <code>i = 0</code>, the elements <code>nums[1] = 2</code> and <code>nums[2] = 4</code> are smaller and have different parity.</li>
	<li>For <code>i = 1</code>, the element <code>nums[3] = 1</code> is smaller and has different parity.</li>
	<li>For <code>i = 2</code>, the elements <code>nums[3] = 1</code> and <code>nums[4] = 3</code> are smaller and have different parity.</li>
	<li>No valid elements exist for the remaining indices.</li>
</ul>

<p>Thus, the <code>answer = [2, 1, 2, 0, 0]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,4,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,1,0]</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<p>For <code>i = 0</code> and <code>i = 1</code>, the element <code>nums[2] = 1</code> is smaller and has different parity. Thus, the <code>answer = [1, 1, 0]</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [7]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0]</span></p>

<p><strong>Explanation:</strong></p>

<p>No elements exist to the right of index 0, so its score is 0. Thus, the <code>answer = [0]</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code>​​​​​​​</li>
</ul>
