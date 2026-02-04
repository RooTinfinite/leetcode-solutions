<h2><a href="https://leetcode.com/problems/find-diameter-endpoints-of-a-tree">Find Diameter Endpoints of a Tree</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an <strong>undirected tree</strong> with <code>n</code> nodes, numbered from 0 to <code>n - 1</code>. It is represented by a 2D integer array <code>edges</code>​​​​​​​ of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>A node is called <strong>special</strong> if it is an <strong>endpoint</strong> of any<strong> diameter path</strong> of the tree.</p>

<p>Return a binary string <code>s</code> of length <code>n</code>, where <code>s[i] = &#39;1&#39;</code> if node <code>i</code> is special, and <code>s[i] = &#39;0&#39;</code> otherwise.</p>

<p>A <strong>diameter path</strong> of a tree is the <strong>longest</strong> simple path between any two nodes. A tree may have multiple diameter paths.</p>

<p>An <strong>endpoint</strong> of a path is the <strong>first</strong> or <strong>last</strong> node on that path.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2025/11/30/pic1.png" style="width: 291px; height: 51px;" /></strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,1],[1,2]]</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;101&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The diameter of this tree consists of 2 edges.</li>
	<li>The only diameter path is the path from node 0 to node 2</li>
	<li>The endpoints of this path are nodes 0 and 2, so they are special.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2025/11/30/pic2.png" /></strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[3,5],[1,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;1000111&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>The diameter of this tree consists of 4 edges. There are 4 diameter paths:</p>

<ul>
	<li>The path from node 0 to node 4</li>
	<li>The path from node 0 to node 5</li>
	<li>The path from node 6 to node 4</li>
	<li>The path from node 6 to node 5</li>
</ul>

<p>The special nodes are nodes <code>0, 4, 5, 6</code>, as they are endpoints in at least one diameter path.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2025/11/30/pic3.png" />​​​​​​​</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 2, edges = [[0,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;11&quot;</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The diameter of this tree consists of 1 edge.</li>
	<li>The only diameter path is the path from node 0 to node 1</li>
	<li>The endpoints of this path are nodes 0 and 1, so they are special.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
</ul>
