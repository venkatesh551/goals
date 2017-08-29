K-way Merging :
---------------------
https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-toolbox-2
https://en.wikipedia.org/wiki/K-Way_Merge_Algorithms

--
Naive algorithm
using heap
using Divide and conquer 
find no of comparisons for each solution ??
kWayMerge on lists and arrays :

Go through the stanford pdf, CLRS

random shuffling :
-------------------
    
https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm


MergeSort:
*************

Lower bound for sorting a Young tableaux.  (sedgewick)
 O(n^2 logn) for n*n

1. Merging two arrays of different lengths. Given two sorted arrays a[] and b[] of sizes M and N where M ≥ N, devise an algorithm to merge them into a new sorted array c[] using ~ N lg M compares.
Hint: use binary search.
Note: there is a lower bound of Omega(N log (1 + M/N)) compares. This follows because there are M+N choose N possible merged outcomes. A decision tree argument shows that this requires at least lg (M+N choose N) compares. We note that n choose r >= (n/r)^r.

2. Merging three arrays. Given three sorted arrays a[], b[], and c[], each of size N, design an algorithm to merge them into a new sorted array d[] using at most ~ 6 N compares in the worst case (or, even better, ~ 5 N compares).

3. Merging three arrays. Given three sorted arrays a[], b[], and c[], each of size N, prove that no compare-based algorithm can merge them into a new sorted array d[] using fewer than ~ 4.754887503 N compares in the worst case.

4. Ford-Johnson merge-insertion sort alg

* 5. Implementation is pending for 

 k-near-sorting. Suppose you have an array a[] of N distinct items which is nearly sorted: each item at most k positions away from its position in the sorted order. Design an algorithm to sort the array in time proportional to N log k.

6. https://www.reddit.com/r/programming/comments/9jqsi/how_to_merge_sorted_lists_with_olog_n_comparisons/



