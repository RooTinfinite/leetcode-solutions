<h2><a href="https://leetcode.com/problems/delayed-count-of-equal-elements">Delayed Count of Equal Elements</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>nums</code> of length <code>n</code> and an integer <code>k</code>.</p>

<p>For each index <code>i</code>, define the <strong>delayed count</strong> as the number of indices <code>j</code> such that:</p>

<ul>
	<li><code>i + k &lt; j &lt;= n - 1</code>, and</li>
	<li><code>nums[j] == nums[i]</code></li>
</ul>

<p>Return an array <code>ans</code> where <code>ans[i]</code> is the <strong>delayed count</strong> of index <code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,1], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,0,0,0]</span></p>

<p><strong>Explanation:</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;"><code>i</code></th>
			<th style="border: 1px solid black;"><code>nums[i]</code></th>
			<th style="border: 1px solid black;">possible <code>j</code></th>
			<th style="border: 1px solid black;"><code>nums[j]</code></th>
			<th style="border: 1px solid black;">satisfying<br />
			<code>nums[j] == nums[i]</code></th>
			<th style="border: 1px solid black;"><code>ans[i]</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">[2, 3]</td>
			<td style="border: 1px solid black;">[1, 1]</td>
			<td style="border: 1px solid black;">[2, 3]</td>
			<td style="border: 1px solid black;">2</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">[3]</td>
			<td style="border: 1px solid black;">[1]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
	</tbody>
</table>

<p>Thus, <code>ans = [2, 0, 0, 0]</code>​​​​​​​.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,1,3,1], k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,1,0,0]</span></p>

<p><strong>Explanation:</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;"><code>i</code></th>
			<th style="border: 1px solid black;"><code>nums[i]</code></th>
			<th style="border: 1px solid black;">possible <code>j</code></th>
			<th style="border: 1px solid black;"><code>nums[j]</code></th>
			<th style="border: 1px solid black;">satisfying<br />
			<code>nums[j] == nums[i]</code></th>
			<th style="border: 1px solid black;"><code>ans[i]</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">[1, 2, 3]</td>
			<td style="border: 1px solid black;">[1, 3, 1]</td>
			<td style="border: 1px solid black;">[2]</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">[2, 3]</td>
			<td style="border: 1px solid black;">[3, 1]</td>
			<td style="border: 1px solid black;">[3]</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">[3]</td>
			<td style="border: 1px solid black;">[1]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">[]</td>
			<td style="border: 1px solid black;">0</td>
		</tr>
	</tbody>
</table>

<p>Thus, <code>ans = [1, 1, 0, 0]</code>​​​​​​​.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
</ul>
