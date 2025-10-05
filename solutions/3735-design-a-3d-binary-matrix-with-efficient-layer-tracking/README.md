<h2><a href="https://leetcode.com/problems/design-a-3d-binary-matrix-with-efficient-layer-tracking">Design a 3D Binary Matrix with Efficient Layer Tracking</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a <code>n x n x n</code> <strong>binary</strong> 3D array <code>matrix</code>.</p>

<p>Implement the <code>Matrix3D</code> class:</p>

<ul>
	<li><code>Matrix3D(int n)</code> Initializes the object with the 3D binary array <code>matrix</code>, where <strong>all</strong> elements are initially set to 0.</li>
	<li><code>void setCell(int x, int y, int z)</code> Sets the value at <code>matrix[x][y][z]</code> to 1.</li>
	<li><code>void unsetCell(int x, int y, int z)</code> Sets the value at <code>matrix[x][y][z]</code> to 0.</li>
	<li><code>int largestMatrix()</code> Returns the index <code>x</code> where <code>matrix[x]</code> contains the most number of 1&#39;s. If there are multiple such indices, return the <strong>largest</strong> <code>x</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong><br />
<span class="example-io">[&quot;Matrix3D&quot;, &quot;setCell&quot;, &quot;largestMatrix&quot;, &quot;setCell&quot;, &quot;largestMatrix&quot;, &quot;setCell&quot;, &quot;largestMatrix&quot;]<br />
[[3], [0, 0, 0], [], [1, 1, 2], [], [0, 0, 1], []]</span></p>

<p><strong>Output:</strong><br />
<span class="example-io">[null, null, 0, null, 1, null, 0] </span></p>

<p><strong>Explanation</strong></p>
Matrix3D matrix3D = new Matrix3D(3); // Initializes a <code>3 x 3 x 3</code> 3D array <code>matrix</code>, filled with all 0&#39;s.<br />
matrix3D.setCell(0, 0, 0); // Sets <code>matrix[0][0][0]</code> to 1.<br />
matrix3D.largestMatrix(); // Returns 0. <code>matrix[0]</code> has the most number of 1&#39;s.<br />
matrix3D.setCell(1, 1, 2); // Sets <code>matrix[1][1][2]</code> to 1.<br />
matrix3D.largestMatrix(); // Returns 1. <code>matrix[0]</code> and <code>matrix[1]</code> tie with the most number of 1&#39;s, but index 1 is bigger.<br />
matrix3D.setCell(0, 0, 1); // Sets <code>matrix[0][0][1]</code> to 1.<br />
matrix3D.largestMatrix(); // Returns 0. <code>matrix[0]</code> has the most number of 1&#39;s.</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong><br />
<span class="example-io">[&quot;Matrix3D&quot;, &quot;setCell&quot;, &quot;largestMatrix&quot;, &quot;unsetCell&quot;, &quot;largestMatrix&quot;]<br />
[[4], [2, 1, 1], [], [2, 1, 1], []]</span></p>

<p><strong>Output:</strong><br />
<span class="example-io">[null, null, 2, null, 3] </span></p>

<p><strong>Explanation</strong></p>
Matrix3D matrix3D = new Matrix3D(4); // Initializes a <code>4 x 4 x 4</code> 3D array <code>matrix</code>, filled with all 0&#39;s.<br />
matrix3D.setCell(2, 1, 1); // Sets <code>matrix[2][1][1]</code> to 1.<br />
matrix3D.largestMatrix(); // Returns 2. <code>matrix[2]</code> has the most number of 1&#39;s.<br />
matrix3D.unsetCell(2, 1, 1); // Sets <code>matrix[2][1][1]</code> to 0.<br />
matrix3D.largestMatrix(); // Returns 3. All indices from 0 to 3 tie with the same number of 1&#39;s, but index 3 is the biggest.</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= x, y, z &lt; n</code></li>
	<li>At most <code>10<sup>5</sup></code> calls are made in total to <code>setCell</code> and <code>unsetCell</code>.</li>
	<li>At most <code>10<sup>4</sup></code> calls are made to <code>largestMatrix</code>.</li>
</ul>
