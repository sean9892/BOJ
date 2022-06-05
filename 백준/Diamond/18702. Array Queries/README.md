# [Diamond I] Array Queries - 18702 

[문제 링크](https://www.acmicpc.net/problem/18702) 

### 성능 요약

메모리: 18960 KB, 시간: 1580 ms

### 분류

자료 구조(data_structures), 느리게 갱신되는 세그먼트 트리(lazyprop), 세그먼트 트리(segtree)

### 문제 설명

<p>We all love problems without a story, who doesn’t?! Here’s one more.</p>

<p>In this problem you are given an array of N integers a<sub>1</sub>, a<sub>2</sub>, · · · , a<sub>N</sub>. Followed by Q queries, each query will be in one of the following types:</p>

<ol>
	<li>For each integer ai where L ≤ i ≤ R, replace it with floor(sqrt(a<sub>i</sub>)). Where sqrt(a) is the square root of a, and floor(b) is the integer value of b after removing everything on the right of the decimal point.</li>
	<li>Print the sum of all integers a<sub>i</sub> where L ≤ i ≤ R.</li>
	<li>Add x to each integer a<sub>i</sub> where L ≤ i ≤ R.</li>
</ol>

### 입력 

 <p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T (1 ≤ T ≤ 100) representing the number of test cases. Followed by T test cases.</p>

<p>Each test case starts with a line containing 2 integers separated by a space, N (1 ≤ N ≤ 10<sup>5</sup>)</p>

<p>representing the number of integers in the array and Q (1 ≤ Q ≤ 20, 000) representing the number of queries.</p>

<p>Followed by a line containing N integers separated by a space, which are the initial integers in the array a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>N</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>6</sup>).</p>

<p>Followed by Q lines, each line will be in one of the following formats (1 ≤ L ≤ R ≤ N) and (1 ≤ x ≤ 10<sup>6</sup>):</p>

<ul>
	<li>A query of the first type: 1 L R</li>
	<li>A query of the second type: 2 L R</li>
	<li>A query of the third type: 3 L R x</li>
</ul>

### 출력 

 <p>For each query of the second type, print the corresponding answer in a single line.</p>

