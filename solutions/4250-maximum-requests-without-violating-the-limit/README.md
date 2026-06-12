<h2><a href="https://leetcode.com/problems/maximum-requests-without-violating-the-limit">Maximum Requests Without Violating the Limit</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a 2D integer array <code>requests</code>, where <code>requests[i] = [user<sub>i</sub>, time<sub>i</sub>]</code> indicates that <code>user<sub>i</sub></code> made a request at <code>time<sub>i</sub></code>.</p>

<p>You are also given two integers <code>k</code> and <code>window</code>.</p>

<p>A user violates the limit if there exists an integer <code>t</code> such that the user makes strictly more than <code>k</code> requests in the inclusive interval <code>[t, t + window]</code>.</p>

<p>You may drop any number of requests.</p>

<p>Return an integer denoting the <strong>maximum</strong>​​​​​​​ number of requests that can <strong>remain</strong> such that no user violates the limit.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">requests = [[1,1],[2,1],[1,7],[2,8]], k = 1, window = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>For user 1, the request times are <code>[1, 7]</code>. The difference between them is 6, which is greater than <code>window = 4</code>.</li>
	<li>For user 2, the request times are <code>[1, 8]</code>. The difference is 7, which is also greater than <code>window = 4</code>.</li>
	<li>No user makes more than <code>k = 1</code> request within any inclusive interval of length <code>window</code>. Therefore, all 4 requests can remain.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">requests = [[1,2],[1,5],[1,2],[1,6]], k = 2, window = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<ul>
	<li>For user 1, the request times are <code>[2, 2, 5, 6]</code>. The inclusive interval <code>[2, 7]</code> of length <code>window = 5</code> contains all 4 requests.</li>
	<li>Since 4 is strictly greater than <code>k = 2</code>, at least 2 requests must be removed.</li>
	<li>After removing any 2 requests, every inclusive interval of length <code>window</code> contains at most <code>k = 2</code> requests.</li>
	<li>Therefore, the maximum number of requests that can remain is 2.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">requests = [[1,1],[2,5],[1,2],[3,9]], k = 1, window = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For user 1, the request times are <code>[1, 2]</code>. The difference is 1, which is equal to <code>window = 1</code>.</li>
	<li>The inclusive interval <code>[1, 2]</code> contains both requests, so the count is 2, which exceeds <code>k = 1</code>. One request must be removed.</li>
	<li>Users 2 and 3 each have only one request and do not violate the limit. Therefore, the maximum number of requests that can remain is 3.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= requests.length &lt;= 10<sup>5</sup></code></li>
	<li><code>requests[i] = [user<sub>i</sub>, time<sub>i</sub>]</code></li>
	<li><code>1 &lt;= k &lt;= requests.length</code></li>
	<li><code>1 &lt;= user<sub>i</sub>, time<sub>i</sub>, window &lt;= 10<sup>5</sup></code></li>
</ul>
