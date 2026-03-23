<h1>Algorithmic Analysis</h1>

<p>project description...</p>

<h2>Team Members</h2>
<p>Marcelino Salazar, Oscar Mendez, Jose Angel Gomez-Bravo, Juvraj Singh Shergill</p>

<h2>Experiment Overview</h2>
<p>...</p>

<h2>Theoretical Time Complexity Summary</h2>

<table>
  <thead>
    <tr>
      <th>Algorithm</th>
      <th>Best Case</th>
      <th>Average Case</th>
      <th>Worst Case</th>
      <th>Short Justification</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Insertion Sort</td>
      <td>O(n)</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>Already sorted input requires minimal shifting. Random and reverse order may force many elements to move left.</td>
    </tr>
    <tr>
      <td>Selection Sort</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>It always scans the unsorted portion to find the next minimum, so comparisons remain quadratic in every case.</td>
    </tr>
    <tr>
      <td>Bubble Sort*</td>
      <td>O(n)</td>
      <td>O(n²)</td>
      <td>O(n²)</td>
      <td>With an early-exit optimization, already sorted input finishes after one pass. Otherwise many adjacent comparisons and swaps are needed.</td>
    </tr>
    <tr>
      <td>Merge Sort</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>The array is always divided into halves and merged back together, regardless of input order.</td>
    </tr>
    <tr>
      <td>Quicksort</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n²)</td>
      <td>Balanced partitions give logarithmic recursion depth, while extremely unbalanced partitions cause quadratic behavior.</td>
    </tr>
    <tr>
      <td>Heapsort</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>O(n log n)</td>
      <td>Heap construction and repeated heap restoration keep runtime in the n log n family across cases.</td>
    </tr>
    <tr>
      <td>Counting Sort</td>
      <td>O(n + k)</td>
      <td>O(n + k)</td>
      <td>O(n + k)</td>
      <td>It counts occurrences instead of comparing elements. In this project, values are in [0, n-1], so k = n and runtime becomes linear.</td>
    </tr>
    <tr>
      <td>Radix Sort</td>
      <td>O(d(n + k))</td>
      <td>O(d(n + k))</td>
      <td>O(d(n + k))</td>
      <td>It processes one digit at a time using a stable subroutine. Runtime depends on digit count d and digit range k.</td>
    </tr>
  </tbody>
</table>

<p><strong>*Note:</strong> Bubble Sort has best-case O(n) only if the implementation uses the standard early-exit optimization. Otherwise its best case is also O(n²).</p>

<h2>How to Run</h2>
<p>...</p>
