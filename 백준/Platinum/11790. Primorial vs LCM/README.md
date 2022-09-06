# [Platinum II] Primorial vs LCM - 11790 

[문제 링크](https://www.acmicpc.net/problem/11790) 

### 성능 요약

메모리: 67680 KB, 시간: 324 ms

### 분류

이분 탐색(binary_search), 수학(math), 정수론(number_theory), 소수 판정(primality_test), 에라토스테네스의 체(sieve), 정렬(sorting)

### 문제 설명

<p>Given N (2<=N<=10<sup>14</sup>), what is the quotient of LCM(1,2,3,....,N) divided by multiple of all primes up to N. As the result might be too big, output it's modulo by 1000000007.</p>

<p>For example, when N=5, the result is LCM(1,2,3,4,5)/(2*3*5)=60/30=2.</p>

<p>Note that LCM stands for Lowest or Least Common Multiple. </p>

### 입력 

 <p>The first line of the input is T(T ≤ 50000), then T test cases follows in next T lines. Each line contains an integer N (2 ≤ N ≤ 100000000000000 or 10<sup>14</sup>). The meaning of N is given in the problem statement. </p>

### 출력 

 <p>For each test case print a line in “Case x: S” format where x is case number and S is the quotient modulo by 1000000007. </p>

