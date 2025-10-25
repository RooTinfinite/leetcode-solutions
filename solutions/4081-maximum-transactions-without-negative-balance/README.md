<h2><a href="https://leetcode.com/problems/maximum-transactions-without-negative-balance">Maximum Transactions Without Negative Balance</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>transactions</code>, where <code>transactions[i]</code> represents the amount of the <code>i<sup>th</sup></code> transaction:</p>

<ul>
	<li>A positive value means money is <strong>received</strong>.</li>
	<li>A negative value means money is <strong>sent</strong>.</li>
</ul>

<p>The account starts with a balance of 0, and the balance <strong>must never become negative</strong>. Transactions must be considered in the given order, but you are allowed to skip some transactions.</p>

<p>Return an integer denoting the <strong>maximum number of transactions</strong> that can be performed without the balance ever going negative.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">transactions = [2,-5,3,-1,-2]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>One optimal sequence is <code>[2, 3, -1, -2]</code>, balance: <code>0 &rarr; 2 &rarr; 5 &rarr; 4 &rarr; 2</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">transactions = [-1,-2,-3]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>All transactions are negative. Including any would make the balance negative.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">transactions = [3,-2,3,-2,1,-1]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>All transactions can be taken in order, balance: <code>0 &rarr; 3 &rarr; 1 &rarr; 4 &rarr; 2 &rarr; 3 &rarr; 2</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= transactions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= transactions[i] &lt;= 10<sup>9</sup></code></li>
</ul>
