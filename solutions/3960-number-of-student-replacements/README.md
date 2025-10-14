<h2><a href="https://leetcode.com/problems/number-of-student-replacements">Number of Student Replacements</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>ranks</code> where <code>ranks[i]</code> represents the rank of the <code>i<sup>th</sup></code> student arriving <strong>in order</strong>. A lower number indicates a <strong>better</strong> rank.</p>

<p>Initially, the first student is <strong>selected</strong> by default.</p>

<p>A <strong>replacement</strong> occurs when a student with a <strong>strictly</strong> better rank arrives and <strong>replaces</strong> the current selection.</p>

<p>Return the total number of replacements made.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">ranks = [4,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The first student with <code>ranks[0] = 4</code> is initially selected.</li>
	<li>The second student with <code>ranks[1] = 1</code> is better than the current selection, so a replacement occurs.</li>
	<li>The third student has a worse rank, so no replacement occurs.</li>
	<li>Thus, the number of replacements is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">ranks = [2,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The first student with <code>ranks[0] = 2</code> is initially selected.</li>
	<li>Neither of <code>ranks[1] = 2</code> or <code>ranks[2] = 3</code> is better than the current selection.</li>
	<li>Thus, the number of replacements is 0.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= ranks.length &lt;= 10<sup>5</sup>​​​​​​​</code></li>
	<li><code>1 &lt;= ranks[i] &lt;= 10<sup>5</sup></code></li>
</ul>
