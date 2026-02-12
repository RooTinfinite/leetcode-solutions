<h2><a href="https://leetcode.com/problems/sum-of-increasing-product-blocks">Sum of Increasing Product Blocks</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer <code>n</code>.</p>

<p>A sequence is formed as follows:</p>

<ul>
	<li>The <code>1<sup>st</sup></code> block contains <code>1</code>.</li>
	<li>The <code>2<sup>nd</sup></code> block contains <code>2 * 3</code>.</li>
	<li>The <code>i<sup>th</sup></code> block is the product of the next <code>i</code> consecutive integers.</li>
</ul>

<p>Let <code>F(n)</code> be the sum of the first <code>n</code> blocks.</p>

<p>Return an integer denoting <code>F(n)</code> <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">127</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>Block 1: <code>1</code></li>
	<li>Block 2: <code>2 * 3 = 6</code></li>
	<li>Block 3: <code>4 * 5 * 6 = 120</code></li>
</ul>

<p><code>F(3) = 1 + 6 + 120 = 127</code></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 7</span></p>

<p><strong>Output:</strong> <span class="example-io">6997165</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Block 1: <code>1</code></li>
	<li>Block 2: <code>2 * 3 = 6</code></li>
	<li>Block 3: <code>4 * 5 * 6 = 120</code></li>
	<li>Block 4: <code>7 * 8 * 9 * 10 = 5040</code></li>
	<li>Block 5: <code>11 * 12 * 13 * 14 * 15 = 360360</code></li>
	<li>Block 6: <code>16 * 17 * 18 * 19 * 20 * 21 = 39070080</code></li>
	<li>Block 7: <code>22 * 23 * 24 * 25 * 26 * 27 * 28 = 5967561600</code></li>
</ul>

<p><code>F(7) = 6006997207 % (10<sup>9</sup> + 7) = 6997165</code></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>
