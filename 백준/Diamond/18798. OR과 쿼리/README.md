# [Diamond V] OR과 쿼리 - 18798 

[문제 링크](https://www.acmicpc.net/problem/18798) 

### 성능 요약

메모리: 10772 KB, 시간: 208 ms

### 분류

자료 구조(data_structures), 세그먼트 트리(segtree)

### 문제 설명

<p>길이가 N인 수열 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>과 음이 아닌 정수 K가 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li>
	<p><code>1 l r x</code> : 모든 l ≤ i ≤ r에 대해, A<sub>i</sub>를 A<sub>i</sub> ∨ x로 바꾼다. (단, ∨는 bitwise OR 연산이다.)</p>
	</li>
	<li>
	<p><code>2 l r</code> : A<sub>i</sub> = K를 만족하는 l ≤ i ≤ r의 개수를 출력한다.</p>
	</li>
</ul>

<p>수열의 인덱스는 1부터 시작한다.</p>

### 입력 

 <p>첫째 줄에 수열의 크기 N (1 ≤ N ≤ 250,000), K (0 ≤ K < 2<sup>30</sup>)가 주어진다.</p>

<p>둘째 줄에는 A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub>이 주어진다. (0 ≤ A<sub>i</sub> < 2<sup>30</sup>)</p>

<p>셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 250,000)이 주어진다.</p>

<p>넷째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. 2번 쿼리는 하나 이상 주어진다. (1 ≤ l ≤ r ≤ N, 0 ≤ x < 2<sup>30</sup>)</p>

### 출력 

 <p>각각의 2번 쿼리마다 정답을 한 줄에 하나씩 출력한다.</p>

