<h2><a href="https://leetcode.com/problems/count-evenly-good-integers">Count Evenly Good Integers</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given two integers <code>l</code> and <code>r</code>.</p>

<p>An integer is called <strong>evenly good</strong> if it contains an even number of even digits.</p>

<p>Return the number of evenly good integers in the inclusive range <code>[l, r]</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">l = 18, r = 22</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The evenly good integers in the range <code>[18, 22]</code> are:</p>

<ul>
	<li>19, because it contains 0 even digits.</li>
	<li>20, because it contains 2 even digits.</li>
	<li>22, because it contains 2 even digits.</li>
</ul>

<p>Thus, the answer is 3.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">l = 98, r = 101</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The evenly good integers in the range <code>[98, 101]</code> are:</p>

<ul>
	<li>99, because it contains 0 even digits.</li>
	<li>100, because it contains 2 even digits.</li>
</ul>

<p>Thus, the answer is 2.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">l = 1, r = 10</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>The evenly good integers in the range <code>[1, 10]</code> are 1, 3, 5, 7, and 9, because each of them contains 0 even digits. Thus, the answer is 5.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= l &lt;= r &lt;= 10<sup>15</sup></code></li>
</ul>
