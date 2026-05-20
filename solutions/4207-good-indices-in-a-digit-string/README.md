<h2><a href="https://leetcode.com/problems/good-indices-in-a-digit-string">Good Indices in a Digit String</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a string <code>s</code> consisting of digits.</p>

<p>An index <code>i</code> is called <strong>good</strong> if there exists a <span data-keyword="substring-nonempty">substring</span> of <code>s</code> that ends at index <code>i</code> and is equal to the decimal representation of <code>i</code>.</p>

<p>Return an integer array of all good indices in <strong>increasing order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;0234567890112&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,11,12]</span></p>

<p><strong>Explanation:​​​​​​​</strong></p>

<ul>
	<li>
	<p>At index 0, the decimal representation of the index is <code>&quot;0&quot;</code>. The substring <code>s[0]</code> is <code>&quot;0&quot;</code>, which matches, so index <code>0</code> is good.</p>
	</li>
	<li>
	<p>At index 11, the decimal representation is <code>&quot;11&quot;</code>. The substring <code>s[10..11]</code> is <code>&quot;11&quot;</code>, which matches, so index <code>11</code> is good.</p>
	</li>
	<li>
	<p>At index 12, the decimal representation is <code>&quot;12&quot;</code>. The substring <code>s[11..12]</code> is <code>&quot;12&quot;</code>, which matches, so index <code>12</code> is good.</p>
	</li>
</ul>

<p>No other index has a substring ending at it that equals its decimal representation. Therefore, the answer is <code>[0, 11, 12]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;01234&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,1,2,3,4]</span></p>

<p><strong>Explanation:</strong></p>

<p>For every index <code>i</code> from 0 to 4, the decimal representation of <code>i</code> is a single digit, and the substring <code>s[i]</code> matches that digit.</p>

<p>Therefore, a valid substring ending at each index exists, making all indices good.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;12345&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>

<p><strong>Explanation:</strong></p>

<p>No index has a substring ending at it that matches its decimal representation.</p>

<p>Therefore, there are no good indices and the result is an empty array.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> only consists of digits from <code>&#39;0&#39;</code> to <code>&#39;9&#39;</code>.</li>
</ul>
