<h2><a href="https://leetcode.com/problems/unique-email-groups">Unique Email Groups</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an array of strings <code>emails</code>, where each string is a valid email address.</p>

<p>Two email addresses belong to the same group if <strong>both</strong> their <strong>normalized</strong> local names and <strong>normalized</strong> domain names are <strong>identical</strong>.</p>

<p>The normalization rules are as follows:</p>

<ul>
	<li>The local name is the part <strong>before</strong> the <code>&#39;@&#39;</code> symbol.

	<ul>
		<li>Ignore all dots <code>&#39;.&#39;</code>.</li>
		<li>Ignore everything after the first <code>&#39;+&#39;</code>, if present.</li>
		<li>Convert to lowercase.</li>
	</ul>
	</li>
	<li>The domain name is the part <strong>after</strong> the <code>&#39;@&#39;</code> symbol.
	<ul>
		<li>Convert to lowercase.</li>
	</ul>
	</li>
</ul>

<p>Return an integer denoting the number of <strong>unique</strong> email groups after normalization.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">emails = [&quot;test.email+alex@leetcode.com&quot;, &quot;test.e.mail+bob.cathy@leetcode.com&quot;, &quot;testemail+david@lee.tcode.com&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>
</div>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Email</th>
			<th style="border: 1px solid black;">Local</th>
			<th style="border: 1px solid black;">Normalized Local</th>
			<th style="border: 1px solid black;">Domain</th>
			<th style="border: 1px solid black;">Normalized Domain</th>
			<th style="border: 1px solid black;">Final Email</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">test.email+alex@leetcode.com</td>
			<td style="border: 1px solid black;">test.email+alex</td>
			<td style="border: 1px solid black;">testemail</td>
			<td style="border: 1px solid black;">leetcode.com</td>
			<td style="border: 1px solid black;">leetcode.com</td>
			<td style="border: 1px solid black;">testemail@leetcode.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">test.e.mail+bob.cathy@leetcode.com</td>
			<td style="border: 1px solid black;">test.e.mail+bob.cathy</td>
			<td style="border: 1px solid black;">testemail</td>
			<td style="border: 1px solid black;">leetcode.com</td>
			<td style="border: 1px solid black;">leetcode.com</td>
			<td style="border: 1px solid black;">testemail@leetcode.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">testemail+david@lee.tcode.com</td>
			<td style="border: 1px solid black;">testemail+david</td>
			<td style="border: 1px solid black;">testemail</td>
			<td style="border: 1px solid black;">lee.tcode.com</td>
			<td style="border: 1px solid black;">lee.tcode.com</td>
			<td style="border: 1px solid black;">testemail@lee.tcode.com</td>
		</tr>
	</tbody>
</table>

<p>Unique emails are [<code>&quot;testemail@leetcode.com&quot;</code>, <code>&quot;testemail@lee.tcode.com&quot;</code>]. Thus, the answer is 2.</p>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">emails = [&quot;A@B.com&quot;, &quot;a@b.com&quot;, &quot;ab+xy@b.com&quot;, &quot;a.b@b.com&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Email</th>
			<th style="border: 1px solid black;">Local</th>
			<th style="border: 1px solid black;">Normalized Local</th>
			<th style="border: 1px solid black;">Domain</th>
			<th style="border: 1px solid black;">Normalized Domain</th>
			<th style="border: 1px solid black;">Final Email</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">A@B.com</td>
			<td style="border: 1px solid black;">A</td>
			<td style="border: 1px solid black;">a</td>
			<td style="border: 1px solid black;">B.com</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">a@b.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">a@b.com</td>
			<td style="border: 1px solid black;">a</td>
			<td style="border: 1px solid black;">a</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">a@b.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">ab+xy@b.com</td>
			<td style="border: 1px solid black;">ab+xy</td>
			<td style="border: 1px solid black;">ab</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">ab@b.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">a.b@b.com</td>
			<td style="border: 1px solid black;">a.b</td>
			<td style="border: 1px solid black;">ab</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">b.com</td>
			<td style="border: 1px solid black;">ab@b.com</td>
		</tr>
	</tbody>
</table>

<p>Unique emails are [<code>&quot;a@b.com&quot;</code>, <code>&quot;ab@b.com&quot;</code>]. Thus, the answer is 2.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">emails = [&quot;a.b+c.d+e@DoMain.com&quot;, &quot;ab+xyz@domain.com&quot;, &quot;ab@domain.com&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Email</th>
			<th style="border: 1px solid black;">Local</th>
			<th style="border: 1px solid black;">Normalized Local</th>
			<th style="border: 1px solid black;">Domain</th>
			<th style="border: 1px solid black;">Normalized Domain</th>
			<th style="border: 1px solid black;">Final Email</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">a.b+c.d+e@DoMain.com</td>
			<td style="border: 1px solid black;">a.b+c.d+e</td>
			<td style="border: 1px solid black;">ab</td>
			<td style="border: 1px solid black;">DoMain.com</td>
			<td style="border: 1px solid black;">domain.com</td>
			<td style="border: 1px solid black;">ab@domain.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">ab+xyz@domain.com</td>
			<td style="border: 1px solid black;">ab+xyz</td>
			<td style="border: 1px solid black;">ab</td>
			<td style="border: 1px solid black;">domain.com</td>
			<td style="border: 1px solid black;">domain.com</td>
			<td style="border: 1px solid black;">ab@domain.com</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">ab@domain.com</td>
			<td style="border: 1px solid black;">ab</td>
			<td style="border: 1px solid black;">ab</td>
			<td style="border: 1px solid black;">domain.com</td>
			<td style="border: 1px solid black;">domain.com</td>
			<td style="border: 1px solid black;">ab@domain.com</td>
		</tr>
	</tbody>
</table>

<p>All emails normalize to <code>&quot;ab@domain.com&quot;</code>. Thus, the answer is 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= emails.length &lt;= 1000</code></li>
	<li><code>1 &lt;= emails[i].length &lt;= 100</code></li>
	<li><code>emails[i]</code> consists of lowercase and uppercase English letters, digits, and the characters <code>&#39;.&#39;</code>, <code>&#39;+&#39;</code>, and <code>&#39;@&#39;</code>.</li>
	<li>Each <code>emails[i]</code> contains <strong>exactly</strong> one <code>&#39;@&#39;</code> character.</li>
	<li>All local and domain names are non-empty; local names do not start with <code>&#39;+&#39;</code>.</li>
	<li>Domain names end with the <code>&quot;.com&quot;</code> suffix and contain at least one character before <code>&quot;.com&quot;</code>.</li>
</ul>
