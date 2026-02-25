<h2><a href="https://leetcode.com/problems/minimum-cost-to-repair-edges-to-traverse-a-graph">Minimum Cost to Repair Edges to Traverse a Graph</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an <strong>undirected graph</strong> with <code>n</code> nodes labeled from 0 to <code>n - 1</code>. The graph consists of <code>m</code> edges represented by a 2D integer array <code>edges</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code> indicates that there is an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with a repair cost of <code>w<sub>i</sub></code>.</p>

<p>You are also given an integer <code>k</code>. Initially, <strong>all</strong> edges are damaged.</p>

<p>You may choose a non-negative integer <code>money</code> and repair <strong>all</strong> edges whose repair cost is <strong>less than or equal</strong> to <code>money</code>. All other edges remain damaged and cannot be used.</p>

<p>You want to travel from node 0 to node <code>n - 1</code> using at most <code>k</code> edges.</p>

<p>Return an integer denoting the <strong>minimum</strong> amount of money required to make this possible, or return -1 if it is impossible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2026/01/04/ex1drawio.png" style="width: 211px; height: 171px;" /></strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,1,10],[1,2,10],[0,2,100]], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">100</span></p>

<p><strong>Explanation:</strong></p>

<p>The only valid path using at most <code>k = 1</code> edge is <code>0 -&gt; 2</code>, which requires repairing the edge with cost 100. Therefore, the minimum required amount of money is 100.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2026/01/04/ex2drawio.png" style="width: 361px; height: 251px;" /></strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 6, edges = [[0,2,5],[2,3,6],[3,4,7],[4,5,5],[0,1,10],[1,5,12],[0,3,9],[1,2,8],[2,4,11]], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">12</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>With <code>money = 12</code>, all edges with repair cost at most 12 become usable.</li>
	<li>This allows the path <code>0 -&gt; 1 -&gt; 5</code>, which uses exactly 2 edges and reaches node 5.</li>
	<li>If <code>money &lt; 12</code>, there is no available path of length at most <code>k = 2</code> from node 0 to node 5.</li>
	<li>Therefore, the minimum required money is 12.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2026/01/04/ex3drawio.png" style="width: 312px; height: 52px;" />​​​​​​​</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,1,1]], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<p>It is impossible to reach node 2 from node 0 using any amount of money. Therefore, the answer is -1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= edges.length == m &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li>There are no self-loops or duplicate edges in the graph.</li>
</ul>
