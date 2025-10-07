<h2><a href="https://leetcode.com/problems/maximize-profit-from-task-assignment">Maximize Profit from Task Assignment</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an integer array <code>workers</code>, where <code>workers[i]</code> represents the skill level of the <code>i<sup>th</sup></code> worker. You are also given a 2D integer array <code>tasks</code>, where:</p>

<ul>
	<li><code>tasks[i][0]</code> represents the skill requirement needed to complete the task.</li>
	<li><code>tasks[i][1]</code> represents the profit earned from completing the task.</li>
</ul>

<p>Each worker can complete <strong>at most</strong> one task, and they can only take a task if their skill level is <strong>equal</strong> to the task&#39;s skill requirement. An <strong>additional</strong> worker joins today who can take up <em>any</em> task, <strong>regardless</strong> of the skill requirement.</p>

<p>Return the <strong>maximum</strong> total profit that can be earned by optimally assigning the tasks to the workers.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">workers = [1,2,3,4,5], tasks = [[1,100],[2,400],[3,100],[3,400]]</span></p>

<p><strong>Output:</strong> <span class="example-io">1000</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Worker 0 completes task 0.</li>
	<li>Worker 1 completes task 1.</li>
	<li>Worker 2 completes task 3.</li>
	<li>The additional worker completes task 2.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">workers = [10,10000,100000000], tasks = [[1,100]]</span></p>

<p><strong>Output:</strong> <span class="example-io">100</span></p>

<p><strong>Explanation:</strong></p>

<p>Since no worker matches the skill requirement, only the additional worker can complete task 0.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">workers = [7], tasks = [[3,3],[3,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The additional worker completes task 1. Worker 0 cannot work since no task has a skill requirement of 7.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= workers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= workers[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>tasks[i].length == 2</code></li>
	<li><code>1 &lt;= tasks[i][0], tasks[i][1] &lt;= 10<sup>9</sup></code></li>
</ul>
