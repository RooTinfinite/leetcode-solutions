<h2><a href="https://leetcode.com/problems/total-distance-to-type-a-string-using-one-finger">Total Distance to Type a String Using One Finger</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr>There is a special keyboard where keys are arranged in a rectangular grid as follows.
<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<td style="border: 1px solid black;">q</td>
			<td style="border: 1px solid black;">w</td>
			<td style="border: 1px solid black;">e</td>
			<td style="border: 1px solid black;">r</td>
			<td style="border: 1px solid black;">t</td>
			<td style="border: 1px solid black;">y</td>
			<td style="border: 1px solid black;">u</td>
			<td style="border: 1px solid black;">i</td>
			<td style="border: 1px solid black;">o</td>
			<td style="border: 1px solid black;">p</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">a</td>
			<td style="border: 1px solid black;">s</td>
			<td style="border: 1px solid black;">d</td>
			<td style="border: 1px solid black;">f</td>
			<td style="border: 1px solid black;">g</td>
			<td style="border: 1px solid black;">h</td>
			<td style="border: 1px solid black;">j</td>
			<td style="border: 1px solid black;">k</td>
			<td style="border: 1px solid black;">l</td>
			<td style="border: 1px solid black;">&nbsp;</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">z</td>
			<td style="border: 1px solid black;">x</td>
			<td style="border: 1px solid black;">c</td>
			<td style="border: 1px solid black;">v</td>
			<td style="border: 1px solid black;">b</td>
			<td style="border: 1px solid black;">n</td>
			<td style="border: 1px solid black;">m</td>
			<td style="border: 1px solid black;">&nbsp;</td>
			<td style="border: 1px solid black;">&nbsp;</td>
			<td style="border: 1px solid black;">&nbsp;</td>
		</tr>
	</tbody>
</table>

<p>You are given a string <code>s</code> that consists of lowercase English letters only. Return an integer denoting the total <strong>distance</strong> to type <code>s</code> using only one finger. Your finger starts on the key <code>&#39;a&#39;</code>.</p>

<p>The <strong>distance</strong> between two keys at <code>(r1, c1)</code> and <code>(r2, c2)</code> is <code>|r1 - r2| + |c1 - c2|</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;hello&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">17</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Your finger starts at <code>&#39;a&#39;</code>, which is at <code>(1, 0)</code>.</li>
	<li>Move to <code>&#39;h&#39;</code>, which is at <code>(1, 5)</code>. The distance is <code>|1 - 1| + |0 - 5| = 5</code>.</li>
	<li>Move to <code>&#39;e&#39;</code>, which is at <code>(0, 2)</code>. The distance is <code>|1 - 0| + |5 - 2| = 4</code>.</li>
	<li>Move to <code>&#39;l&#39;</code>, which is at <code>(1, 8)</code>. The distance is <code>|0 - 1| + |2 - 8| = 7</code>.</li>
	<li>Move to <code>&#39;l&#39;</code>, which is at <code>(1, 8)</code>. The distance is <code>|1 - 1| + |8 - 8| = 0</code>.</li>
	<li>Move to <code>&#39;o&#39;</code>, which is at <code>(0, 8)</code>. The distance is <code>|1 - 0| + |8 - 8| = 1</code>.</li>
	<li>Total distance is <code>5 + 4 + 7 + 0 + 1 = 17</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;a&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Your finger starts at <code>&#39;a&#39;</code>, which is at <code>(1, 0)</code>.</li>
	<li>Move to <code>&#39;a&#39;</code>, which is at <code>(1, 0)</code>. The distance is <code>|1 - 1| + |0 - 0| = 0</code>.</li>
	<li>Total distance is 0.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters only.</li>
</ul>
