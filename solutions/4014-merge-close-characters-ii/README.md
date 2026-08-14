<h2><a href="https://leetcode.com/problems/merge-close-characters-ii">Merge Close Characters II</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a string <code>s</code> consisting of lowercase English letters and an integer <code>k</code>.</p>

<p>Two equal characters <code>s[i]</code> and <code>s[j]</code>, where <code>0 &lt;= i &lt; j &lt; s.length</code>, are considered <strong>close</strong> if <code>j - i &lt;= k</code>. All indices refer to the <strong>current</strong> string.</p>

<p>Repeatedly perform the following operation until no close pair remains:</p>

<ul>
	<li>Among all close pairs <code>(i, j)</code>, choose the pair with the smallest <code>i</code>. If multiple pairs have the same <code>i</code>, choose the one with the smallest <code>j</code>.</li>
	<li>Merge the right character into the left character by removing <code>s[j]</code> from <code>s</code>. The character <code>s[i]</code> remains unchanged, and the remaining characters are reindexed.</li>
</ul>

<p>Return the resulting string after performing all possible merges.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abca&quot;, k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;abc&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The characters <code>&#39;a&#39;</code> at indices 0 and 3 are close because <code>3 - 0 = 3 &lt;= k</code>.</li>
	<li>Remove the right <code>&#39;a&#39;</code>, resulting in <code>s = &quot;abc&quot;</code>.</li>
	<li>No close pair remains, so no further merges are performed.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aabca&quot;, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;abca&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The characters <code>&#39;a&#39;</code> at indices 0 and 1 are close because <code>1 - 0 = 1 &lt;= k</code>.</li>
	<li>Remove the right <code>&#39;a&#39;</code>, resulting in <code>s = &quot;abca&quot;</code>.</li>
	<li>The remaining <code>&#39;a&#39;</code> characters are at indices 0 and 3. Since <code>3 - 0 = 3 &gt; k</code>, no further merges are performed.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;yybyzybz&quot;, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;ybzybz&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The characters <code>&#39;y&#39;</code> at indices 0 and 1 are close because <code>1 - 0 = 1 &lt;= k</code>. This pair has the smallest left index among all close pairs.</li>
	<li>Remove the right <code>&#39;y&#39;</code>, resulting in <code>s = &quot;ybyzybz&quot;</code>.</li>
	<li>The characters <code>&#39;y&#39;</code> at indices 0 and 2 are now close because <code>2 - 0 = 2 &lt;= k</code>.</li>
	<li>Remove the right <code>&#39;y&#39;</code>, resulting in <code>s = &quot;ybzybz&quot;</code>.</li>
	<li>No close pair remains, so no further merges are performed.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>
