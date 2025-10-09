<h2><a href="https://leetcode.com/problems/multiply-two-polynomials">Multiply Two Polynomials</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p data-end="315" data-start="119">You are given two integer arrays <code>poly1</code> and <code>poly2</code>, where the element at index <code>i</code> in each array represents the coefficient of <code>x<sup>i</sup></code> in a polynomial.</p>

<p>Let <code>A(x)</code> and <code>B(x)</code> be the polynomials represented by <code>poly1</code> and <code>poly2</code>, respectively.</p>

<p>Return an integer array <code>result</code> of length <code>(poly1.length + poly2.length - 1)</code> representing the coefficients of the product polynomial <code>R(x) = A(x) * B(x)</code>, where <code>result[i]</code> denotes the coefficient of <code>x<sup>i</sup></code> in <code>R(x)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">poly1 = [3,2,5], poly2 = [1,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">[3,14,13,20]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><code>A(x) = 3 + 2x + 5x<sup>2</sup></code> and <code>B(x) = 1 + 4x</code></li>
	<li><code>R(x) = (3 + 2x + 5x<sup>2</sup>) * (1 + 4x)</code></li>
	<li><code>R(x) = 3 * 1 + (3 * 4 + 2 * 1)x + (2 * 4 + 5 * 1)x<sup>2</sup> + (5 * 4)x<sup>3</sup></code></li>
	<li><code>R(x) = 3 + 14x + 13x<sup>2</sup> + 20x<sup>3</sup></code></li>
	<li>Thus, result = <code>[3, 14, 13, 20]</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">poly1 = [1,0,-2], poly2 = [-1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[-1,0,2]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><code>A(x) = 1 + 0x - 2x<sup>2</sup></code> and <code>B(x) = -1</code></li>
	<li><code>R(x) = (1 + 0x - 2x<sup>2</sup>) * (-1)</code></li>
	<li><code>R(x) = -1 + 0x + 2x<sup>2</sup></code></li>
	<li>Thus, result = <code>[-1, 0, 2]</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">poly1 = [1,5,-3], poly2 = [-4,2,0]</span></p>

<p><strong>Output:</strong> <span class="example-io">[-4,-18,22,-6,0]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><code>A(x) = 1 + 5x - 3x<sup>2</sup></code> and <code>B(x) = -4 + 2x + 0x<sup>2</sup></code></li>
	<li><code>R(x) = (1 + 5x - 3x<sup>2</sup>) * (-4 + 2x + 0x<sup>2</sup>)</code></li>
	<li><code>R(x) = 1 * -4 + (1 * 2 + 5 * -4)x + (5 * 2 + -3 * -4)x<sup>2</sup> + (-3 * 2)x<sup>3</sup> + 0x<sup>4</sup></code></li>
	<li><code>R(x) = -4 -18x + 22x<sup>2</sup> -6x<sup>3</sup> + 0x<sup>4</sup></code></li>
	<li>Thus, result = <code>[-4, -18, 22, -6, 0]</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= poly1.length, poly2.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>3</sup> &lt;= poly1[i], poly2[i] &lt;= 10<sup>3</sup></code></li>
	<li><code>poly1</code> and <code>poly2</code> contain at least one non-zero coefficient.</li>
</ul>
