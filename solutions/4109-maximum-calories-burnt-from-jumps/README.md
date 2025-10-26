<h2><a href="https://leetcode.com/problems/maximum-calories-burnt-from-jumps">Maximum Calories Burnt from Jumps</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>heights</code> of size <code>n</code>, where <code>heights[i]</code> represents the height of the <code>i<sup>th</sup></code> block in an exercise routine.</p>

<p>You start on the ground (height 0) and <strong>must</strong> jump onto each block <strong>exactly once</strong> in any order.</p>

<ul>
	<li>The <strong>calories burned</strong> for a jump from a block of height <code>a</code> to a block of height <code>b</code> is <code>(a - b)<sup>2</sup></code>.</li>
	<li>The <strong>calories burned</strong> for the first jump from the ground to the chosen first block <code>heights[i]</code> is <code>(0 - heights[i])<sup>2</sup></code>.</li>
</ul>

<p>Return the <strong>maximum</strong> total calories you can burn by selecting an optimal jumping sequence.</p>

<p><strong>Note:</strong> Once you jump onto the first block, you cannot return to the ground.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">heights = [1,7,9]</span></p>

<p><strong>Output:</strong> <span class="example-io">181</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<p>The optimal sequence is <code>[9, 1, 7]</code>.</p>

<ul>
	<li>Initial jump from the ground to <code>heights[2] = 9</code>: <code>(0 - 9)<sup>2</sup> = 81</code>.</li>
	<li>Next jump to <code>heights[0] = 1</code>: <code>(9 - 1)<sup>2</sup> = 64</code>.</li>
	<li>Final jump to <code>heights[1] = 7</code>: <code>(1 - 7)<sup>2</sup> = 36</code>.</li>
</ul>

<p>Total calories burned = <code>81 + 64 + 36 = 181</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">heights = [5,2,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">38</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal sequence is <code>[5, 2, 4]</code>.</p>

<ul>
	<li>Initial jump from the ground to <code>heights[0] = 5</code>: <code>(0 - 5)<sup>2</sup> = 25</code>.</li>
	<li>Next jump to <code>heights[1] = 2</code>: <code>(5 - 2)<sup>2</sup> = 9</code>.</li>
	<li>Final jump to <code>heights[2] = 4</code>: <code>(2 - 4)<sup>2</sup> = 4</code>.</li>
</ul>

<p>Total calories burned = <code>25 + 9 + 4 = 38</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">heights = [3,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">9</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal sequence is <code>[3, 3]</code>.</p>

<ul>
	<li>Initial jump from the ground to <code>heights[0] = 3</code>: <code>(0 - 3)<sup>2</sup> = 9</code>.</li>
	<li>Next jump to <code>heights[1] = 3</code>: <code>(3 - 3)<sup>2</sup> = 0</code>.</li>
</ul>

<p>Total calories burned = <code>9 + 0 = 9</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>5</sup></code></li>
</ul>
