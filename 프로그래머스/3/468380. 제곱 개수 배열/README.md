# [level 3] 제곱 개수 배열 - 468380 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/468380) 

### 성능 요약

메모리: 6.27 MB, 시간: 1.29 ms

### 구분

코딩테스트 연습 > 2025 카카오 하반기 2차

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2026년 08월 14일 19:47:58

### 문제 설명

<p>1이상의 정수로 이루어진 길이가 <code>N</code>인 1차원 정수 배열 <code>arr</code>가 주어집니다. 다음 규칙에 따라 배열 <code>brr</code>를 만듭니다.</p>

<ul>
<li>배열 <code>arr</code>의 인덱스 순서대로 <code>arr[i]</code>를 배열 <code>brr</code>에 연속으로 <code>arr[i]</code>개씩 추가합니다.</li>
</ul>

<p>예를 들어, <code>arr</code>가 [2, 1, 5]이면 <code>brr</code>는 [2, 2, 1, 5, 5, 5, 5, 5]입니다.</p>

<p><code>brr</code>의 부분 배열<sup id="fnref1"><a href="#fn1">1</a></sup> 구간의 양 끝을 나타내는 <code>l</code>, <code>r</code>이 주어질 때 아래 2가지를 구하려고 합니다.</p>

<ol>
<li><code>K</code> = <code>brr</code>의 <code>l</code>번째 원소부터 <code>r</code>번째 원소까지의 합 = <code>brr[l-1] + brr[l] + brr[l+1] + ... + brr[r-2] + brr[r-1]</code></li>
<li><code>C</code> = 길이가 <code>r - l + 1</code>인 <code>brr</code>의 부분 배열 중 합이 <code>K</code>인 부분 배열의 개수</li>
</ol>

<p>1차원 정수 배열 <code>arr</code>와 구간의 양 끝을 나타내는 정수 <code>l</code>, <code>r</code>이 매개변수로 주어집니다. 이때, 1차원 정수 배열 <code>[K, C]</code>를 return 하도록 solution 함수를 완성해 주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ <code>arr</code>의 길이 = <code>N</code> ≤ 100,000

<ul>
<li>1 ≤ <code>arr[i]</code> ≤ 100,000</li>
<li><code>brr</code>의 모든 원소의 합 ≤ 10<sup>15</sup></li>
</ul></li>
<li>1 ≤ <code>l</code> ≤ <code>r</code> ≤ <code>arr</code>의 모든 원소의 합

<ul>
<li><code>l</code>번째 원소부터 <code>r</code>번째 원소까지의 합을 구해야 합니다.</li>
</ul></li>
</ul>

<hr>

<h5>테스트 케이스 구성 안내</h5>

<p>아래는 테스트 케이스 구성을 나타냅니다. 각 그룹은 하나 이상의 하위 그룹으로 이루어져 있으며, 하위 그룹의 모든 테스트 케이스를 통과하면 해당 그룹에 할당된 점수를 획득할 수 있습니다.</p>
<table class="table">
        <thead><tr>
<th>그룹</th>
<th>총점</th>
<th>테스트 케이스 그룹 설명</th>
</tr>
</thead>
        <tbody><tr>
<td>#1</td>
<td>5%</td>
<td><code>l = r</code></td>
</tr>
<tr>
<td>#2</td>
<td>15%</td>
<td><code>N</code> ≤ 100, <code>arr[i]</code> ≤ 10</td>
</tr>
<tr>
<td>#3</td>
<td>35%</td>
<td>정답이 <code>C = 1</code>인 테스트 케이스만 주어집니다.</td>
</tr>
<tr>
<td>#4</td>
<td>45%</td>
<td>추가 제한 사항 없음</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>arr</th>
<th>l</th>
<th>r</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[3, 2, 3, 1, 1]</td>
<td>5</td>
<td>7</td>
<td>[8, 2]</td>
</tr>
<tr>
<td>[2, 2, 2]</td>
<td>2</td>
<td>2</td>
<td>[2, 6]</td>
</tr>
<tr>
<td>[8, 8, 6, 5, 2, 9, 8, 4, 3, 10]</td>
<td>25</td>
<td>27</td>
<td>[15, 3]</td>
</tr>
<tr>
<td>[70195, 25471, 7389, 58187, 18454, 90532, 97667, 17148, 91636, 2810]</td>
<td>126058</td>
<td>462933</td>
<td>[27554327568, 1]</td>
</tr>
<tr>
<td>[16952, 70276, 16771, 37992, 87549, 54906, 36718, 20478, 57088, 27916, 51509, 83422, 51707, 18807, 80859, 2673, 37734, 93380]</td>
<td>149845</td>
<td>228204</td>
<td>[6860339640, 9190]</td>
</tr>
<tr>
<td>[49134, 86806, 94548, 88849, 95022, 28334, 16637, 79487, 23773, 7314, 47370, 50269, 36573, 9415, 44674, 28096]</td>
<td>61242</td>
<td>88535</td>
<td>[2369282964, 59513]</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p><strong>입출력 예 #1</strong>  </p>

<p>brr는 [3, 3, 3, 2, <code>2, 3, 3</code>, 3, 1, 1]입니다. 5~7번째 원소로 이루어진 부분 배열의 합은 8(=<code>K</code>)입니다.<br>
[3, <code>3, 3, 2</code>, 2, 3, 3, 3, 1, 1] 또한 부분 배열의 합이 8이며 길이가 3입니다. <br>
위 두 경우 외에는 합이 8이고 길이가 3인 부분 배열은 존재하지 않습니다.<br>
[3, 3, 3, 2, 2, 3, <code>3, 3, 1, 1</code>]은 부분 배열의 합이 8이지만 길이가 4이므로 <code>C</code>로 세지 않습니다.</p>

<p>따라서 [8, 2]를 return 해야 합니다.</p>

<p><strong>입출력 예 #2</strong>  </p>

<p>brr는 [2, <code>2</code>, 2, 2, 2, 2]입니다. 2~2번째 원소로 이루어진 부분 배열의 합은 2(=<code>K</code>)입니다. 합이 2이고 길이가 1인 부분 배열의 개수는 6개입니다.</p>

<p>따라서 [2, 6]을 return 해야 합니다.</p>

<p><strong>입출력 예 #3</strong>  </p>

<p>[15, 3]을 return 해야 합니다.</p>

<p><strong>입출력 예 #4</strong>  </p>

<p>[27554327568, 1]을 return 해야 합니다.</p>

<p><strong>입출력 예 #5</strong>  </p>

<p>[6860339640, 9190]을 return 해야 합니다.</p>

<p><strong>입출력 예 #6</strong>  </p>

<p>[2369282964, 59513]을 return 해야 합니다.</p>

<div class="footnotes">
<hr>
<ol>

<li id="fn1">
<p>부분 배열이란 주어진 배열에서 연속된 원소들로 이루어진 배열을 의미합니다.&nbsp;<a href="#fnref1">↩</a></p>
</li>

</ol>
</div>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges