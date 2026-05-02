<h1>Algorithmic Analysis</h1>

<h2>Team Info</h2>
<p><strong>Team name:</strong> The Tanks</p>
<p><strong>Team members:</strong> Marcelino Salazar, Oscar Mendez, Jose Angel Gomez-Bravo, Juvraj Singh Shergill</p>

<h2>Language And Environment</h2>
<p><strong>Language:</strong> C++</p>
<p><strong>Standard:</strong> C++17</p>
<p><strong>Compiler:</strong> g++ or clang++</p>

<h2>Project Structure</h2>
<pre>
part1_sorting/
  src/        source code
  tests/      test inputs, generators, and experiment helper code
  data/       optional small data files
</pre>

<h2>Part 1 Overview</h2>
<p>Part 1 compares sorting algorithm runtime on different input orders. Each experiment runs an algorithm 10 times and reports the median time. For comparison-based algorithms, the program also prints the number of comparisons and the median time divided by the comparison count. The program uses a fixed random seed, <code>srand(1)</code>, so random inputs are reproducible across runs.</p>

<h2>How To Run Part 1</h2>
<p>After downloading or cloning the project, open a terminal in the main project folder. Then move into the Part 1 folder:</p>

<pre>
cd part1_sorting
</pre>

<p>Compile the experiment program:</p>

<pre>
g++ -std=c++17 src/Test.cpp src/Algorithms.cpp tests/Number-Generator.cpp tests/Test-Inputs.cpp src/Validate.cpp -o test_experiment
</pre>

<p>Run:</p>

<pre>
./test_experiment
</pre>

<p>If you want to compile from the main project folder instead, use this command:</p>

<pre>
g++ -std=c++17 part1_sorting/src/Test.cpp part1_sorting/src/Algorithms.cpp part1_sorting/tests/Number-Generator.cpp part1_sorting/tests/Test-Inputs.cpp part1_sorting/src/Validate.cpp -o part1_sorting/test_experiment
</pre>

<p>Then run it with:</p>

<pre>
./part1_sorting/test_experiment
</pre>

<p>The program opens this testing menu:</p>

<pre>
1. Manual test
2. Fast algorithms only
3. Slow algorithms only
4. Full experiment
</pre>

<p><strong>Expected parameters:</strong></p>
<ul>
  <li>Manual test asks for an array size <code>n</code>.</li>
  <li>Manual test then asks for input type: <code>1</code> sorted, <code>2</code> random, <code>3</code> reversed, or <code>4</code> half-sorted.</li>
  <li>Fast algorithms mode runs Quick Sort, Merge Sort, Heap Sort, Counting Sort, and Radix Sort up to <code>n = 100000</code>.</li>
  <li>Slow algorithms mode runs Selection Sort, Insertion Sort, and Bubble Sort for <code>n = 1000</code>, <code>10000</code>, and <code>25000</code>.</li>
  <li>Full experiment runs all algorithms and warns that it may take a long time.</li>
</ul>

<p>Run with the sample input file:</p>

<pre>
./test_experiment &lt; tests/sample_inputs.txt
</pre>

<p>The file <code>tests/expected_output_summary.txt</code> explains what the sample run should show.</p>

<h2>How To Reproduce Graphs</h2>
<p>...</p>

<h2>Notes</h2>
<ul>
  <li>If an algorithm takes more than 60 seconds at one size, larger sizes for that same algorithm and input type are skipped.</li>
  <li>Full experiment mode may take a long time because Selection Sort, Insertion Sort, and Bubble Sort are quadratic algorithms.</li>
</ul>

<h2>Theoretical Time Complexity Summary</h2>

<table>
  <thead>
    <tr>
      <th>Algorithm</th>
      <th>Best Case</th>
      <th>Best-Case Input</th>
      <th>Average Case</th>
      <th>Average-Case Input</th>
      <th>Worst Case</th>
      <th>Worst-Case Input</th>
      <th>Justification</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Insertion Sort</td>
      <td>O(n)</td>
      <td>Already sorted</td>
      <td>O(n²)</td>
      <td>Random order</td>
      <td>O(n²)</td>
      <td>Reverse sorted</td>
      <td>Already sorted input requires minimal shifting. Random and reverse order may force many elements to move left.</td>
    </tr>
    <tr>
      <td>Selection Sort</td>
      <td>O(n²)</td>
      <td>Any order</td>
      <td>O(n²)</td>
      <td>Any order</td>
      <td>O(n²)</td>
      <td>Any order</td>
      <td>It always scans the unsorted portion to find the next minimum, so comparisons remain quadratic in every case.</td>
    </tr>
    <tr>
      <td>Bubble Sort*</td>
      <td>O(n)</td>
      <td>Already sorted</td>
      <td>O(n²)</td>
      <td>Random order</td>
      <td>O(n²)</td>
      <td>Reverse sorted</td>
      <td>With an early-exit optimization, already sorted input finishes after one pass. Otherwise many adjacent comparisons and swaps are needed.</td>
    </tr>
    <tr>
      <td>Merge Sort</td>
      <td>O(n log n)</td>
      <td>Any order</td>
      <td>O(n log n)</td>
      <td>Any order</td>
      <td>O(n log n)</td>
      <td>Any order</td>
      <td>The array is always divided into halves and merged back together, regardless of input order.</td>
    </tr>
    <tr>
      <td>Quicksort</td>
      <td>O(n log n)</td>
      <td>Balanced partitions</td>
      <td>O(n log n)</td>
      <td>Random order</td>
      <td>O(n²)</td>
      <td>Already sorted or reverse sorted with a bad pivot choice</td>
      <td>Balanced partitions give logarithmic recursion depth, while extremely unbalanced partitions cause quadratic behavior.</td>
    </tr>
    <tr>
      <td>Heapsort</td>
      <td>O(n log n)</td>
      <td>Any order</td>
      <td>O(n log n)</td>
      <td>Any order</td>
      <td>O(n log n)</td>
      <td>Any order</td>
      <td>Heap construction and repeated heap restoration keep runtime in the n log n family across cases.</td>
    </tr>
    <tr>
      <td>Counting Sort</td>
      <td>O(n + k)</td>
      <td>Values in a small known range</td>
      <td>O(n + k)</td>
      <td>Values in a small known range</td>
      <td>O(n + k)</td>
      <td>Large value range compared to n</td>
      <td>It counts occurrences instead of comparing elements. In this project, values are in <code>[0, n - 1]</code>, so <code>k = n</code>.</td>
    </tr>
    <tr>
      <td>Radix Sort</td>
      <td>O(d(n + k))</td>
      <td>Few digits</td>
      <td>O(d(n + k))</td>
      <td>Typical digit count</td>
      <td>O(d(n + k))</td>
      <td>Many digits</td>
      <td>It processes one digit at a time using a stable counting-sort-style subroutine.</td>
    </tr>
  </tbody>
</table>
